
float vPow = 3.3;
float r1 = 100000;
float r2 = 10000;
int vPin = A2;

void setup() {
  /*Serial.begin(9600);

  Serial.println("--------------------");
  Serial.println("DC VOLTMETER");
  Serial.println("Maximum Voltage: ");
  Serial.println((int)(vPow / (r2 / (r1 + r2))));
  Serial.println("V");
  Serial.println("--------------------");
  Serial.println("");

  delay(2000);*/
}

void loop() {
  // Particle.io ref voltage is 3.3V and A2D is 12bit
  float v = (analogRead(vPin) * vPow) / 4095.0; // 4096.0??
  // Convert from voltage divider circuit
  float v2 = v / (r2 / (r1 + r2));

  Serial.println(v2);

  delay(5000);
}

int readVoltage(String command) {
    /* Spark.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LEDs turning on, 0 for the LEDs turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LEDs.
    */

    if (command=="on") {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        return 0;
    }
    else {
        return -1;
    }
}
