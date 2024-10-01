const int pin_led1 = 9;
const int pin_led2 = 3;
const int pin_led3 = 5;
const int pin_led4 = 6;
int LDR = A0;
int  valor;

void setup() {
  Serial.begin(9600);
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
}

void loop() {
  valor = analogRead(LDR);
  Serial.println(valor);
  if (valor > 70){
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
      if (valor > 200){
        digitalWrite(pin_led1, HIGH);
        digitalWrite(pin_led2, HIGH);
        digitalWrite(pin_led3, LOW);                  //OS IFS PRECISAM SER UM DENTRO DO OUTRO POIS CASO NÃO SEJA ASSIM, ELES IRÃO DE ANULAR
        digitalWrite(pin_led4, LOW);                  // TENTE PENSAR NO CODIGO COM OS IFS SEPARADOS, O PRIMEIRO IF FARIA O O RESTO FICAR DESLIGADO 
        if (valor > 350){                             // E ACREDITO Q N PRECISA DOS DIGITALWRITE(PIN, LOW), POIS ISSO N IMPORTA MT, SÓ NO ELSE{}
          digitalWrite(pin_led1, HIGH);
          digitalWrite(pin_led2, HIGH);
          digitalWrite(pin_led3, HIGH);
          digitalWrite(pin_led4, LOW);
            if (valor > 350){
              digitalWrite(pin_led1, HIGH);
              digitalWrite(pin_led2, HIGH);
              digitalWrite(pin_led3, HIGH);
              digitalWrite(pin_led4, LOW);
              if (valor > 700){
                  digitalWrite(pin_led1, HIGH);
                  digitalWrite(pin_led2, HIGH);
                  digitalWrite(pin_led3, HIGH);
                  digitalWrite(pin_led4, HIGH);
        }
      }
    }
   }
  }
  else{
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
  }
}
