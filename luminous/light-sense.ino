int analogvalue;
int power         = A5;
int photoresistor = A0;

void setup() {
    Serial.begin(9600);

    pinMode(photoresistor,INPUT);
    // The pin powering the photoresistor is output (sending out consistent power)
    pinMode(power,OUTPUT);
    // Write the power of the photoresistor to be the maximum possible, so that we can use this for power.
    digitalWrite(power,HIGH);

    Particle.variable("lightvalue", analogvalue);
}

void loop() {
    analogvalue = analogRead(photoresistor);
    Serial.println(analogvalue);

    delay(5000);
}
