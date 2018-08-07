int ledPins[] = {2, 3, 4, 5};
int delayTime = 1250; // this number times 255 is ~how long the led will take to glow all the way
void setup() {  
  for (int i=0; i<4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

//member functions
void powerPin_1()
{
  digitalWrite(ledPins[0], HIGH);
}
void offPin_1()
{
    digitalWrite(ledPins[0], LOW);
}
void powerPin_2()
{
  digitalWrite(ledPins[1], HIGH);
}
void offPin_2()
{
    digitalWrite(ledPins[1], LOW);
}
void powerPin_3()
{
  digitalWrite(ledPins[2], HIGH);
}
void offPin_3()
{
    digitalWrite(ledPins[2], LOW);
}
void powerPin_4()
{
  digitalWrite(ledPins[3], HIGH);
}
void offPin_4()
{
    digitalWrite(ledPins[3], LOW);
}

void powerAll() {
  powerPin_1();
  powerPin_2();
  powerPin_3();
  powerPin_4();
}

void offAll() {
  offPin_1();
  offPin_2();
  offPin_3();
  offPin_4();
}

void loop() {
  /*
  for (int i=0; i<4; i++) {
  digitalWrite(ledPins[i], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[i], LOW);
  delay(delayTime);
  }
  */
  do {
  delayTime=delayTime/2;
  
  powerPin_1();
  delay(delayTime * 2);
  offPin_1();
  delay(delayTime);
  
  powerPin_2();
  delay(delayTime * 2);
  offPin_2();
  delay(delayTime);
  
  powerPin_3();
  delay(delayTime * 2);
  offPin_3();
  delay(delayTime);

  powerPin_4();
  delay(delayTime * 2);
  offPin_4();
  delay(delayTime);
  } while (delayTime > 0);
  
  delayTime=1250;
  powerAll();

  delay(delayTime);
  offAll();
  delay(delayTime);
  
  Serial.println(""); 
}
