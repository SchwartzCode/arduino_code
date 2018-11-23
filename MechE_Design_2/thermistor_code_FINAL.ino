#define SERIES_RESISTOR_THERMISTOR 100000    //set resistor values as constants
#define SERIES_RESISTOR_RESISTIVITY 47000   
#define THERMISTOR_PIN A0                    //set pin value that will read in thermistor resistance data
#define RESISTIVITY_PIN A5                   //set pin value that will read in gel resistivity data 

#define THERMISTORNOMINAL 114000 //resistance of thermistor at room temperature
#define TEMPERATURENOMINAL 20    //actual temperature used for "room temperature"
#define BCOEFFICIENT 3000        //beta coefficient of the thermistor, ususally between 2000 and 3000

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  double total_raw_data_thermistor = 0.0;
  double total_raw_data_resistivity = 0.0;

  //collect 5 data samples every second and average them for more accurate results
  for (int i=0; i<5; i++) {
    total_raw_data_thermistor += analogRead(THERMISTOR_PIN);
    total_raw_data_resistivity += analogRead(RESISTIVITY_PIN);
    delay(200);
  }
  double avg_data_thermistor = total_raw_data_thermistor / 5;
  double avg_data_resistivity = total_raw_data_resistivity / 5;

  //calculate resistance from measured data
  double scaled_data_thermistor = (1023 / avg_data_thermistor) - 1;
  double thermistor_resistance = SERIES_RESISTOR_THERMISTOR / scaled_data_thermistor;

  double scaled_data_resistivity = (1023 / avg_data_resistivity) - 1;
  double hydrogel_resistance = SERIES_RESISTOR_RESISTIVITY / scaled_data_resistivity;


          
  //uses Steinhart and Hart equation to convert the thermistor's resistance to ambient temperature
  float steinhart;
  steinhart = thermistor_resistance / THERMISTORNOMINAL;
  steinhart = log(steinhart);
  steinhart /= BCOEFFICIENT;
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15);
  steinhart = 1.0 / steinhart;
  steinhart -= 273.15;


  Serial.print("Gel Resistance:\t");
  Serial.println(hydrogel_resistance);
  Serial.print("Temperature:\t");
  Serial.print(steinhart);
  Serial.println(" *C");
  Serial.println();

}
