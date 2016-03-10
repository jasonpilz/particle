int vPin    = A5;
int ledPin  = D0;
double vPow = 3.353;
double r1   = 82000;
double r2   = 10000;
double voltageValue = 0;
double maxInput = 0;

void setup() {
  pinMode(vPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Particle.variable("voltage", voltageValue);
  Particle.variable("maxvoltage", maxInput);

  Particle.function("led", ledToggle);

  maxInput = (vPow / (r2 / (r1 + r2)));
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Particle.io ref voltage is 3.3V and A2D is 12bit
  double v = (analogRead(vPin) * vPow) / 4096.0;
  // Convert from voltage divider circuit
  double v2 = v / (r2 / (r1 + r2));

  voltageValue = v2;

  delay(5000);
}

int ledToggle(String command) {

  if (command=="on") {
    digitalWrite(ledPin, HIGH);
    return 1;
  }
  else if (command=="off") {
    digitalWrite(ledPin, LOW);
    return 0;
  }
  else {
    return -1;
  }
}
