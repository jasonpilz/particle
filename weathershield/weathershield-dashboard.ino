#include "SparkFun_Photon_Weather_Shield_Library/SparkFun_Photon_Weather_Shield_Library.h"

Weather sensor;

float tempF = 0;
float t     = 0;  // actual temperature
float h     = 0;  // humidity

void setup() {
  Particle.variable("tempF", tempF);
  Particle.variable("humidity", h);

  sensor.begin();
  sensor.setOversampleRate(7);
  sensor.setModeBarometer();
  delay(1000);
}

void loop() {
  getClimateData();
  publishData();
  delay(15000);
}

void getClimateData() {
  tempF = sensor.getTempF();
  t = (tempF - 32) * 0.5555555556;
  h = sensor.getRH();
}

void publishData() {
  char payload[255];

  snprintf(payload, sizeof(payload), "{ \"t\": %.3f, \"h\": %.1f }", t, h);
  Particle.publish("climate", payload, 60);
}
