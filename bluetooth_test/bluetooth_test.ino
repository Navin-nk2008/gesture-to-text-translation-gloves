#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Type from app...");
}

void loop() {
  while (BT.available()) {
    char c = BT.read();
    Serial.write(c);   // directly print in Serial Monitor
  }
}
