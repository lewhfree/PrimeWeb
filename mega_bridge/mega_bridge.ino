void setup() {
  // put your setup code here, to run once:
  Serial1.begin(57600); // Output to the arduino.
  Serial3.begin(57600); // Input from esp32.
  Serial.begin(74880);
  Serial.print("Serial Setup!");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial1.available()){ // if data is coming from the arduino to the esp32
    int data = Serial1.read();
    Serial3.print(data);
    Serial.print(data);
  }

  while(Serial3.available()){//esp32 to arduino
    int data = Serial3.read();
    Serial1.print(data);
    Serial.print(data);
  }
}
