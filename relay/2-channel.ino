int channelOne = D1;
int channelTwo = D2;

void setup()
{
  pinMode(channelOne, OUTPUT);
  pinMode(channelTwo, OUTPUT);

  Particle.function("relay1", channelOne);
  Particle.function("relay2", channelTwo);

  digitalWrite(channelOne, HIGH);
  digitalWrite(channelTwo, HIGH);
}

int channelOne(String command) {
  if (command=="on") {
    digitalWrite(channelOne, LOW);
    return 1;
  }
  else if (command=="off") {
    digitalWrite(channelOne, HIGH);
    return 0;
  }
  else { return -1; }
}

int channelTwo(String command) {
  if (command=="on") {
    digitalWrite(channelTwo, LOW);
    return 1;
  }
  else if (command=="off") {
    digitalWrite(channelTwo, HIGH);
    return 0;
  }
  else { return -1; }
}
