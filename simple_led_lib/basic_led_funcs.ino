int ledPins[] = {2, 3, 4, 5}; //enter arduino pins that connect to the LED (don't forget a resistor)
int pin_count = 4;
int delayTime = 1250; //time delay (in milliseconds) between actions
void setup() {  
  for (int i=0; i<pin_count; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}



void powerPin(int pin) {
	digitalWrite(pin, HIGH);
}
void offPin(int pin) {
	digitalWrite(pin, LOW);
}


void powerAll() {
	for (int i=0; i<pin_count; i++) {
		powerPin(ledPins[i]);
	}
}

void offAll() {
	for (int i=0; i<pin_count; i++) {
		offPin(ledPins[i]);
	}
}



void loop() {

  Serial.println(""); 
}
