//initialize pin numbers for input and output
int kill_switch = 13; 
int temp_pin1 = 2;
int temp_pin2 = 3;

double temp1=0, temp2=0; //initialize temp readings to 0
bool stop = false; //initialize boolean that activates kill switch


//checks for any temperature issues, returns true if there are, causing kill_switch to activate
bool issue_check() {
  bool issues_found = false;
  
  if (temp1 > 70 || temp1 < 20)
    issues_found = true;	//activates kill switch if first temp reading is out of acceptable range
  else if (temp2 > 70 || temp2 < 20)
    issues_found = true;	//activates kill switch if second temp reading is out of acceptable range
  
    
  return issues_found;
}

//reads from temperature sensors and converts voltage reading to readable temperature
double temp_read(int pin) {

  int raw_data = analogRead(pin); //returns an int between 0 and 1023, representing voltage across pin (4.9 mV increments)
  double voltage = 4.9 * raw_data; //converts raw data to millvolts
  double temp = (voltage - 500) / 10; //converts voltage in millivolts to temperature in degrees C
  
  return temp;
}

//puts arduino into an endless loop, only used after activating kill_switch
void freeze() {
  Serial.println();
  Serial.println();
  while (true) {
   	delay(10000); 
  }
}


void setup()
{
  pinMode(kill_switch, OUTPUT); //LED; kill switch
  pinMode(2, INPUT); //first temperature sensor
  pinMode(3, INPUT); //second temperature sensor
  
  Serial.begin(9600); //opens a serial port for debugging
}


void loop()
{
  //read and handle temperature sensor readings
  temp1=temp_read(temp_pin1);
  delay(10); //not certain delay are necessary
  temp2=temp_read(temp_pin2);
  delay(10);
  
  //prints temperature readings to serial port for debugging
  Serial.print("TEMP_1: ");
  Serial.println(temp1);
  Serial.print("TEMP_2: ");
  Serial.println(temp2);

  
  //check readings for any issues
  stop = issue_check();
  
  //activates kill switches and puts arduino to sleep if isssues were found
  if (stop) {
    digitalWrite(kill_switch, HIGH);
  	freeze();
  }

}
