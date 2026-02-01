#include <Wire.h>
#include "MPU6050.h"

MPU6050 mpu;

const float FREEFALL_TH = 0.5;     // g
const float IMPACT_TH   = 2.5;     // g
const int STILL_TIME_MS = 3000;    // 3 sec

bool impactDetected = false;
unsigned long impactTime = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
}

void loop() {

  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  float a_res = sqrt(ax_g*ax_g + ay_g*ay_g + az_g*az_g);

  /* ---------- STEP 1 : FREE FALL ---------- */
  if (a_res < FREEFALL_TH) {
    Serial.println("Free fall detected");
  }

  /* ---------- STEP 2 : IMPACT ---------- */
  if (a_res > IMPACT_TH) {
    impactDetected = true;
    impactTime = millis();
    Serial.println("Impact detected");
  }

  /* ---------- STEP 3 : LYING STILL ---------- */
  if (impactDetected) {

    float gyroMag = abs(gx) + abs(gy) + abs(gz);

    if (gyroMag < 200 && millis() - impactTime > STILL_TIME_MS) {
      triggerAlert();
      impactDetected = false;
    }
  }

  delay(20);
}

void triggerAlert() {
  Serial.println("FALL DETECTED! Alert sent.");
}
