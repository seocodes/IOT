const int blue_led = 9;
const int green_led = 3;
const int red_led = 6;
unsigned char red_outputValue;
unsigned char green_outputValue;
unsigned char blue_outputValue;
int estado = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available() >= 3){
    if(estado == 0){
      red_outputValue = Serial.parseInt();
      analogWrite(red_led, red_outputValue);
      estado = 1;
    }
    else if (estado == 1){
      green_outputValue = Serial.parseInt();
      analogWrite(green_led, green_outputValue);
      estado = 2;
    }
    else if (estado == 2){
      blue_outputValue = Serial.parseInt();
      analogWrite(blue_led, blue_outputValue);
      estado = 0;
    }

    
    Serial.println(red_outputValue);
    Serial.println(green_outputValue);
    Serial.println(blue_outputValue);
  }
}
