#define BAUDRATE 57600
#include "HID-Project.h"
uint8_t rawhidData[64];

void setup() {
  delay(3000); // allows calculator to get up to speed and for esp32 to boot.
  Serial1.begin(BAUDRATE);
  Serial.begin(BAUDRATE);
  RawHID.begin(rawhidData, sizeof(rawhidData));
  Serial1.setTimeout(100);
  Serial.setTimeout(500);
  RawHID.setTimeout(500);

}

void loop() {
  String website = "";
  auto bytesAvailable = RawHID.available();
  if (Serial1.available()) {
    while (Serial1.available()) {
      int data = Serial1.read();
      char character = (char)data;
      //Serial.print(character);
      website += String(character);
      bytesAvailable = RawHID.available();
    }
    //Serial.print(website);
    website.trim();
    uint8_t hidbuffer[64];
    memset(hidbuffer, 0, sizeof(hidbuffer));
    int websiteLength = website.length();
    int rounds = (websiteLength / 64) + (websiteLength % 64 > 0 ? 1 : 0);  // Get the number of round WORKS thanks chatgpt
    uint8_t dummy[1] = {1};
    RawHID.write(dummy, sizeof(dummy));
    for (int i = 0; i < rounds; i++) {  // for each of the rounds IS CORRECT
      int startIndex = i * 64;          
      int endIndex = min((i + 1) * 64, websiteLength);
      String currentSubString = website.substring(startIndex, endIndex);
      for (int a = 0; a < currentSubString.length(); a++) {
        hidbuffer[a] = (uint8_t)currentSubString[a];
      }
      RawHID.write(hidbuffer, currentSubString.length());
    }
  }

  if (bytesAvailable) {
    String url = RawHID.readString();
    url.trim();
    Serial1.print(url);
  }
}