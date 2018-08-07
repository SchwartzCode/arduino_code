int ledPins[] = {2, 3, 4, 5}; //enter arduino pins that connect to the LED (don't forget a resistor)
int delayTime = 1250; //time delay (in milliseconds) between actions
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

  int time_spacing=delayTime;
  do {
  time_spacing=time_spacing/3 * 2 + 3;
  
  powerPin_1();
  delay(time_spacing * 2);
  offPin_1();
  
  powerPin_2();
  delay(time_spacing * 2);
  offPin_2();
  
  powerPin_3();
  delay(time_spacing * 2);
  offPin_3();

  powerPin_4();
  delay(time_spacing * 2);
  offPin_4();
  } while (time_spacing > 20);
  
  time_spacing = delayTime;
  powerAll();

  delay(delayTime);
  offAll();
  delay(delayTime);
  
  Serial.println(""); 
}
