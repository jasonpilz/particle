int channelOne = D1;
int channelTwo = D2;

void setup()
{
  pinMode(channelOne, OUTPUT);
  pinMode(channelTwo, OUTPUT);

  Particle.function("relay1", relay1Toggle);
  Particle.function("relay2", relay2Toggle);

  digitalWrite(channelOne, HIGH);
  digitalWrite(channelTwo, HIGH);
}

int relay1Toggle(String command) {
  if (command=="on") {
    digitalWrite(channelOne, LOW);
    return 1;
  }
  else if (command=="off") {
    digitalWrite(channelOne, HIGH);
    return 0;
  }
  else {
    return -1;
  }
}

int relay2Toggle(String command) {
  if (command=="on") {
    digitalWrite(channelTwo, LOW);
    return 1;
  }
  else if (command=="off") {
    digitalWrite(channelTwo, HIGH);
    return 0;
  }
  else {
    return -1;
  }
}
