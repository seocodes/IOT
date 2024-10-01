int porta = A1;
int valor;
const int pin_led = 2;
int claro = 70;

void setup() {
  Serial.begin(9600);
  pinMode(porta, INPUT);
  pinMode(pin_led, OUTPUT);
}

void loop() {
  valor = analogRead(porta);
  Serial.println(valor);
  if (valor <= claro){
    digitalWrite(pin_led, HIGH);
  }
  else{
    digitalWrite(pin_led, LOW);
  }
}
