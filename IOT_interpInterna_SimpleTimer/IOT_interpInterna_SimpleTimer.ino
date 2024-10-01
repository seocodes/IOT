#include <SimpleTimer.h>

const int pin_led = 7;
const int interruptPin_botao = 2;
SimpleTimer firstTimer(1000);
bool state = 1;

void setup()
{
    Serial.begin(9600);
    pinMode(interruptPin_botao, INPUT_PULLUP);
    pinMode(pin_led, OUTPUT);
                                                                //quando LOW, puxa o bloco de código "turnOff"
    attachInterrupt(digitalPinToInterrupt(interruptPin_botao), turnOff, LOW);  //LOW, pois se refere ao estado do botao que deve estar para executar a função (LOW/abaixado)
    //nao preciso fazer um but == HIGH pra fazer isso pq o attachInterrupt já identifica quando há uma alteração no botão e faz oq tem ali dentro
}

void loop(){
    if (firstTimer.isReady()) {            
        Serial.println("1 second has passed, TURNING ON");
        digitalWrite(pin_led, state);
        firstTimer.reset();
        state = !state;       //deve estar dentro do if pra trocar logo depois, se estiver fora, vai demorar.
        }
}

void turnOff(){
  digitalWrite(pin_led, LOW);
}
