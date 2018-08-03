int ledPin = 31;
int delayTime = 250; // this number times 255 is ~how long the led will take to glow all the way
void setup() {  
    pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);

  
  
}

