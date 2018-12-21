class LED {
  private:
    byte pin;
    int delayTime;

  public:
    LED();
    byte getPin();
    byte setPin();
    int getDelay();
    int setDelay();
    void on();
    void off();
    void blink();
};
