int vPin    = A2;
double vPow = 3.3;
double r1   = 100000;
double r2   = 10000;
double voltageValue = 0;
double maxInput = 0;

void setup() {
  pinMode(vPin,INPUT);

  Particle.variable("voltage", voltageValue);
  Particle.variable("maxvoltage", maxInput);

  maxInput = (vPow / (r2 / (r1 + r2)));
}

void loop() {
  // Particle.io ref voltage is 3.3V and A2D is 12bit
  double v = (analogRead(vPin) * vPow) / 4095.0; // 4096.0??
  // Convert from voltage divider circuit
  double v2 = v / (r2 / (r1 + r2));

  voltageValue = v2;

  delay(5000);
}
