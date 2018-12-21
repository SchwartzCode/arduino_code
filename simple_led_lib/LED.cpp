//unsure if I need this definition statement- will look into it
//#ifndef LED
//#define LED

#include <LED.h>

class LED {
  
  private:
  byte pin;
  int delayTime;



  public:
//constructors
  LED() {
    pin = 13;
    delayTime = 500;
  }

  LED(byte pinGiven) {
    pin = pinGiven;
  }

  LED(byte pinGiven, int delayGiven) {
    pin = pinGiven;
    delayTime = delayGiven;
  }

//   MEMBER FUNCTIONS    ==========================================================
// functions for obtaining and/or manipulating member variables
  byte getPin() {
    return pin;
  }
  int getDelay() {
    return delayTime;
  }
 
  byte setPin(byte newPin) {
    byte temp = getPin();
    pin = newPin;
    return temp;
  }
  int setDelay(int newDelay) {
    int temp = getDelay();
    delayTime = newDelay;
    return temp;
  }

// functions to make the pin do things 
  void on() {
    digitalWrite(pin, HIGH);
  }

  void off(){
    digitalWrite(pin, LOW);
  }

  void glowOn() {
    for (int i=0; i<255; i+=10) {
      analogWrite(pin, i);
      delay(20);
    }
  }

  void glowOff() {
    for (int i=255; i>0; i-=10) {
      analogWrite(pin, i);
      delay(20);
    }
  }

  void blink() {
    on();
    delay(delayTime);
    off();
  }
};

//#endif
//thi is meant to match the if statement that defines the class
//not sure if I need it though so it's commented out for now
