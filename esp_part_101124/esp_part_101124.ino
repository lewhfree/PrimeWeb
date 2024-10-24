#include <WiFi.h>
#include <HTTPClient.h>

const char WIFI_SSID[] = "SSID";
const char WIFI_PASSWORD[] = "PASSWORD";

void setup() {
  Serial.begin(57600);
  Serial.setTimeout(1000);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  delay(10000);

  while (WiFi.status() != WL_CONNECTED) { delay(1000); }

  // String response = makeHTTPRequest("https://lite.duckduckgo.com/lite");
  // Serial.print(response);
}

void loop() {
  if (Serial.available()) {
    String url = Serial.readString();
    url.trim();
    Serial.print("Recieved: ");
    Serial.println(url);
    if (url.length() > 0) {
      String response = makeHTTPRequest(url);
      int length = response.length();
      int midpoint = length / 2;
      Serial.println(length);
      Serial.println(midpoint);
      Serial.print(response);
    }
  }
  delay(500);
}

String makeHTTPRequest(String urll) {
  String URL = urll;
  HTTPClient http;

  http.setTimeout(30 * 1000);

  http.begin(URL);
  int httpCode = http.GET();
  String payload;  // Initialize payload

  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      payload = http.getString();  // Store the response in payload
    } else {
      payload = String("[HTTP] GET... code: ") + String(httpCode);  // Correct way to format
    }
  } else {
    payload = String("[HTTP] GET... failed, error: ") + http.errorToString(httpCode).c_str();  // Correct way to format
  }

  http.end();
  return payload;
}