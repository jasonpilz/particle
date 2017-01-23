// Sensor - TMP36

int tempPin   = A5;
int analogVal = 0;
double vPow   = 3.2;
double tempC  = 0;

void setup() {
  pinMode(tempPin, INPUT);

  Particle.variable("tempC", tempC);
}

void loop() {
  getTemperature();

  publishData();

  delay(15000);
}

void getTemperature() {
  analogVal = analogRead(tempPin);
  tempC = (((analogVal * vPow) / 4095) - 0.5) * 100;
}

void publishData() {
  char payload[255];

  snprintf(payload, sizeof(payload), "{ \"C\": %.3f }", tempC);
  Particle.publish("temperature", payload, 60);
}
