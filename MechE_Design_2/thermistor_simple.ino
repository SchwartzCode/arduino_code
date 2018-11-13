#define SERIESRESISTOR 100000    //set resistor value as constant
#define THERMISTORPIN A0         //set pin value that will read in data

#define THERMISTORNOMINAL 120000 //resistance of thermistor at room temperature
#define TEMPERATURENOMINAL 25    //actual temperature used for "room temperature"
#define BCOEFFICIENT 2950        //beta coefficient of the resistor

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  double raw_data = analogRead(THERMISTORPIN);

  /*
  //FOR DEBUGGING:
  Serial.print("Analog reading: ");
  Serial.println(raw_data);
  */
  double scaled_data = (1023 / raw_data) - 1;
  double thermistor_resistance = SERIESRESISTOR / scaled_data;

  double v_out = 4.9 * raw_data;

  Serial.print("INFO: ");
  Serial.println(thermistor_resistance);

  float steinhart;
  steinhart = thermistor_resistance / THERMISTORNOMINAL;
  steinhart = log(steinhart);
  steinhart /= BCOEFFICIENT;
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15);
  steinhart = 1.0 / steinhart;
  steinhart -= 273.15;

  Serial.print("Temperature: ");
  Serial.print(steinhart);
  Serial.println(" *C");
  
  delay(1000);

}
