#include <Wire.h>

const int MPU = 0x68;

int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;

void setup() {
  Wire.begin();
  Serial.begin(115200);

  Serial.println("Starting MPU6050...");

  // Check connection
  Wire.beginTransmission(MPU);
  if (Wire.endTransmission() != 0) {
    Serial.println("MPU6050 not found!");
    while (1);
  }

  Serial.println("MPU6050 connected!");

  // Wake up MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {

  // Read data
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  Wire.read(); Wire.read(); // skip temperature

  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  // Print raw values
  Serial.print("AcX: "); Serial.print(AcX);
  Serial.print(" | AcY: "); Serial.print(AcY);
  Serial.print(" | AcZ: "); Serial.print(AcZ);

  Serial.print(" | GyX: "); Serial.print(GyX);
  Serial.print(" | GyY: "); Serial.print(GyY);
  Serial.print(" | GyZ: "); Serial.println(GyZ);

  delay(300);
}