class LED_LINE{
  private:
    int size; //number of leds in the line
    LED[] lights;
    int delayTime;
  
  public:
    //constructor
    LED_LINE(byte[] pins, int delayGiven) {
      size = pins.size();
      delayTime = delayGiven;
      for (int i=0; i<size; i=+){
        lights[i] = new LED(pins[i]);
      }
    }

    //basic functions
    allOn() {
      for (int i=0; i<size; i++) {
        lights[i].on();
      }
    }  

    allOff() {
      for (int i=0; i<size; i++) {
        lights[i].off();
      }
    }

    allGlowOn() {
      for (int i=0; i<size; i++) {
        lights[i].glowOn();
      }
    }

    allGlowOff() {
      for (int i=0; i<size; i++) {
        lights[i].glowOff();
      }
    }

    allBlink() {
      allOn();
      delay(delayTime);
      allOff();
    }

    allGlow() {
      allGlowOn();
      delay(delayTime);
      allGlowOff();
    }

//fancy (relatively) functions
    //one bulbs glows on then off, one at a time in order
    loading1(int count) {
      while (count > 0) {
	for (int i=0; i<size; i++) {
	  pin[i].glowOn();
	  delay(delayTime);
	  pin[i].glowOff();
	}
	count--;
      }
    }

    //glows on all of the leds one at a time in order, then all glow off
    loading2(int count) {
      while (count > 0) {
	for (int i=0; i<size; i++) {
	  pin[i].glowOn();
	}
	allGlowOff();
	delay(delayTime);
      }
    }

};
