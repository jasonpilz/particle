// Sensor - TMP36

int tempPin   = A5;
int analogVal = 0;
double vPow   = 3.2;
double tempF  = 0;
double tempC  = 0;

void setup() {
  pinMode(tempPin, INPUT);

  Particle.variable("tempC", tempC);
  // Particle.variable("tempF", tempF);
}

void loop() {
  getTemperature();

  publishData();

  delay(15000);
}

void getTemperature() {
  analogVal = analogRead(tempPin);
  //tempF     = (analogVal * vPow) / 4095.0;
  //tempC     = (tempF - 32) * 0.5555555556;
  tempC = (((analogVal * vPow) / 4095) - 0.5) * 100;
}

void publishData() {
  char payload[255];

  //snprintf(payload, sizeof(payload), "{ \"°C\": %.3f, \"°F\": %1.f }", tempC, tempF);
  snprintf(payload, sizeof(payload), "{ \"C\": %.3f }", tempC);
  Particle.publish("temperature", payload, 60);
}
