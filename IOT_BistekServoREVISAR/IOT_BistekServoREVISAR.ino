//USEI O METODO FINITE STATE MACHINE (FSM) NESSE CÓDIGO (OS CASE MALUCO ALI)

void  printarDistancia(int x){
    Serial.print("Distance in CM: ");
    Serial.println(x);
}

#include <Ultrasonic.h>
#include <Servo.h>
Ultrasonic ultrasonic(12,13);
Servo myservo;

int distance;
int pos = 0;
const int but = 3;
int estado = 0;
unsigned long tempoAnt = 0;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(but, INPUT_PULLUP);
}

void loop() {
  bool button = !digitalRead(but);
  distance = ultrasonic.read();
  printarDistancia(distance);
  switch(estado){
    case 0:
      myservo.write(0);
      if (distance < 10){
        estado = 1;
      }
      break;
    case 1:
      Serial.println("Pressione o botão!!!!!!@@!!!!!!!!!!!");
      if (button == HIGH){
        myservo.write(90);
        tempoAnt = millis();
        estado = 2;
      }
      break;
    case 2:
    unsigned long tempoAtual = millis();
      if (tempoAtual - tempoAnt >= 1000){
        estado = 0;
      }
      break;
    default:
      Serial.begin("QUEBRO TUDO quebro tudo BROKE EVERYTHING broke everything")
      estado = 0;
  }
  //OBS LEGAL: dá pra ter um if aqui, tipo, de um botao de emergencia
  //isso porque há um break no final de todo case e sempre que dá esse break ele vem pra cá e depois continnua o loop (imagina isso dps e quando que pode dar um break em cada case)
}
