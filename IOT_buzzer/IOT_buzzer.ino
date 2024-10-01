const int pin_entrada = A0;
const int buzzer = 10;
const int range = 3;
int valor;
float tensao;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  valor = analogRead(pin_entrada);
  tensao = float(valor)*5/1023;
  Serial.println(tensao);
  if (tensao >= range){
    digitalWrite(buzzer, tensao);
  }
  else{
    digitalWrite(buzzer, LOW);
  }

}
