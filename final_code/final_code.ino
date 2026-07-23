#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>

MPU6050 mpu;
SoftwareSerial bt(10, 11);

int flexPins[4] = {A0, A1, A2, A3};

const int totalSamples = 100;   // fixed samples

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

  Wire.begin();
  mpu.initialize();

  if (mpu.testConnection()) {
    bt.println("MPU OK");
  } else {
    bt.println("MPU FAILED");
  }

  bt.println("READY");
}

void loop() {

  // Wait for 's' from Python
  if (bt.available()) {
    char cmd = bt.read();

    if (cmd == 's') {

      bt.println("START");

      for (int i = 0; i < totalSamples; i++) {

        sendData();
        delay(20);   // 50 Hz sampling
      }

      bt.println("END");
    }
  }
}

// 🔧 Function to send one sample
void sendData() {

  int f1 = analogRead(flexPins[0]);
  int f2 = analogRead(flexPins[1]);
  int f3 = analogRead(flexPins[2]);
  int f4 = analogRead(flexPins[3]);

  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  bt.print(f1); bt.print(",");
  bt.print(f2); bt.print(",");
  bt.print(f3); bt.print(",");
  bt.print(f4); bt.print(",");
  bt.print(ax); bt.print(",");
  bt.print(ay); bt.print(",");
  bt.print(az); bt.print(",");
  bt.print(gx); bt.print(",");
  bt.print(gy); bt.print(",");
  bt.println(gz);
}