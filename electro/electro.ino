#include <math.h>

int vPin    = A5;
double vPow = 3.33;
double r1   = 82000;
double r2   = 10000;
double voltageValue = 0;
double maxInput = 0;

void setup() {
  pinMode(vPin, INPUT);

  Particle.variable("voltage", voltageValue);
  Particle.variable("maxvoltage", maxInput);

  maxInput = (vPow / (r2 / (r1 + r2)));
}

void loop() {
  // Particle.io ref voltage is 3.3V and A2D is 12bit
  double v = (analogRead(vPin) * vPow) / 4096.0;
  // Convert from voltage divider circuit
  double v2 = v / (r2 / (r1 + r2));

  // Round voltage reading to 3 decimal places
  voltageValue = ((int)(v2 * 10000)) / 10000;

  delay(5000);
}
