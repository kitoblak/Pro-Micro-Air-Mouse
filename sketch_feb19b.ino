#include <Wire.h>
#include <MPU6050.h>
#include <Mouse.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;

int smpin = 16; // button that stops moving cursor
int sensitivity = 700; // you might want to change that
int error = 0; // change it if cursor spontaneously change it's position

void setup() {

  Serial.begin(9600);
  Wire.begin();
  pinMode(smpin, INPUT_PULLUP);
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
  }
  Mouse.begin();
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = gx / sensitivity + error;
  vy = gz / sensitivity + error;
  if (digitalRead(smpin) == HIGH) Mouse.move(vx, vy);
}
