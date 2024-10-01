const int ledPin  = 7;
const int interruptPin_botao = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin_botao, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_botao), blink, CHANGE);

}

void loop() {
  digitalWrite(ledPin, state);

}

void blink(){
  state = !state;
}