// Sensor - TMP36

int tempPin  = A5;
double vPow  = 3.33;
double tempF = 0;
double tempC = 0;

void setup() {
  pinMode(tempPin, INPUT);

  Particle.variable("tempC", tempC);
  Particle.variable("tempF", tempF);
}

void loop() {
  getTemperature();

  publishData();

  delay(15000);
}

void getTemperature() {
  
  tempF =
  tempC = (tempF - 32) * 0.5555555556;
}

void publishData() {
  char payload[255];

  snprintf(payload, sizeof(payload), "{ \"°C\": %.3f, \"°F\": %1.f }", tempC, tempF);
  Particle.publish("temperature", payload, 60);
}
