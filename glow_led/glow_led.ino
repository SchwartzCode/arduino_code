int ledPins[] = {2, 3, 4, 5};
int delayTime = 250; // this number times 255 is ~how long the led will take to glow all the way
void setup() {  
  for (int i=0; i<4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i=0; i<4; i++) {
  digitalWrite(ledPins[i], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[i], LOW);
  delay(delayTime);
  }
  
  Serial.println(""); 
}
