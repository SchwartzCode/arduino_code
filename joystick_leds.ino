
// led pin numbers, 4 leds in a square with (0,0) bottom right and (1,1) top left
int led_pins[2][2] = { {10, 12},
                        {11, 13}
                     };
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
int curr_x = 0;
int curr_y = 0;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void lightAll() {
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      digitalWrite(led_pins[i][j], HIGH);  
    }
  }
  int swit = digitalRead(SW_pin);
    while(!swit) {
    swit = digitalRead(SW_pin);
    delay(100);
  }

  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      digitalWrite(led_pins[i][j], LOW);  
    }
  }
}

void moveRight() {
  Serial.println("RIGHT");
  if (curr_x>0) {
    digitalWrite(led_pins[curr_x][curr_y], LOW);
    curr_x--;
    digitalWrite(led_pins[curr_x][curr_y], HIGH);
  }
}
void moveLeft() {
  Serial.println("LEFT");
  if (curr_x<1) {
    digitalWrite(led_pins[curr_x][curr_y], LOW);
    curr_x++;
    digitalWrite(led_pins[curr_x][curr_y], HIGH);
  }
}

void moveUp() {
  Serial.println("UP");
  if (curr_y<1) {
    digitalWrite(led_pins[curr_x][curr_y], LOW);
    curr_y++;
    digitalWrite(led_pins[curr_x][curr_y], HIGH);
  }
}
void moveDown() {
  Serial.println("DOWN");
  if (curr_y>0) {
    digitalWrite(led_pins[curr_x][curr_y], LOW);
    curr_y--;
    digitalWrite(led_pins[curr_x][curr_y], HIGH);
  }
}

void loop() {
  int sw = digitalRead(SW_pin);
  int x = analogRead(X_pin);
  int y = analogRead(Y_pin);
  
  Serial.print("Switch:  ");
  Serial.print(sw);
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(y);
  Serial.print("Curr_X: ");
  Serial.print(curr_x);
  Serial.print("\t Curr_Y: ");
  Serial.println(curr_y);
  Serial.print("\n\n");

  if(!sw) {
    lightAll();
  }
  else if(x>510) {
    moveRight();
  }
  else if(x<490) {
    moveLeft();
  }

  if(y<490) {
    moveUp();
  }
  else if(y>510) {
    moveDown();
  }

  digitalWrite(led_pins[curr_x][curr_y], HIGH);
  
  delay(100);

}
