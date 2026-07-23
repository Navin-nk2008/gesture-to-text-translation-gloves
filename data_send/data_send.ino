#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>

MPU6050 mpu;
SoftwareSerial bt(10, 11);

int flexPins[4] = {A0, A1, A2, A3};

const unsigned long interval = 20;
unsigned long previousMillis = 0;

bool recording = true;
int sampleCount = 0;
const int maxSamples = 1000;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

  Wire.begin();
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU OK");
    bt.println("MPU OK");
  } else {
    Serial.println("MPU FAILED");
    bt.println("MPU FAILED");
  }

  Serial.println("SYSTEM READY");
  bt.println("READY");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int f1 = analogRead(flexPins[0]);
    int f2 = analogRead(flexPins[1]);
    int f3 = analogRead(flexPins[2]);
    int f4 = analogRead(flexPins[3]);

    int16_t ax, ay, az;
    int16_t gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    Serial.print(f1); Serial.print(",");
    Serial.print(f2); Serial.print(",");
    Serial.print(f3); Serial.print(",");
    Serial.print(f4); Serial.print(",");
    Serial.print(ax); Serial.print(",");
    Serial.print(ay); Serial.print(",");
    Serial.print(az); Serial.print(",");
    Serial.print(gx); Serial.print(",");
    Serial.print(gy); Serial.print(",");
    Serial.println(gz);

    bt.print(f1); bt.print(",");
    bt.print(f2); bt.print(",");
    bt.print(f3); bt.print(",");
    bt.print(f4); bt.print(",");
    bt.print(ax); bt.print(",");
    bt.print(ay); bt.print(",");
    bt.print(az); bt.print(",");
    bt.print(gx); bt.print(",");
    bt.print(gy); bt.println(gz);

    sampleCount++;

    if (sampleCount >= maxSamples) {
      sampleCount = 0;
    }
  }
}