const int pin_led = 9;
const int pin_potenciometro = A0;
int valor;
float tensao;

void setup() {
  Serial.begin(9600);
  pinMode(pin_potenciometro, INPUT);
  pinMode(pin_led, OUTPUT);
}

void loop() {
  valor = analogRead(pin_potenciometro);
  tensao = float(valor)*255/1023;
  Serial.print("Tensao = ");
  Serial.print(tensao);
  analogWrite(pin_led, tensao);
}
