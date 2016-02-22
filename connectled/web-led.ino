// -----------------------------------
// Controlling LEDs over the Internet
// -----------------------------------

int led1 = D0;
int led2 = D7;

void setup()
{
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);

   Particle.function("led", ledToggle);

   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
}

void loop()
{
   // Nothing to do here
}

int ledToggle(String command) {
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
