// Código legal pra revisar e tirar dúvidas (usa o blackbox a vontade)
// No portal tem um código do Marcos em programas.zip, o arquivo se chama Brilho_LED.ino

const int blue_led = 9;
const int green_led = 3;
const int red_led = 6; 
unsigned char red_outputValue; // Valor inteiro sem sinal de 8 bits (0-255)
unsigned char green_outputValue; // Valor inteiro sem sinal de 8 bits (0-255)
unsigned char blue_outputValue; // Valor inteiro sem sinal de 8 bits (0-255)
int estado = 0;

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial em 9600 bps
}

void loop() {
  if(Serial.available() >= 3){ // Verifica se há pelo menos 3 bytes disponíveis no buffer de entrada serial
    /* A variável estado é usada para controlar a leitura sequencial dos valores de entrada
     Isso é necessário porque o método Serial.parseInt() lê todos os caracteres disponíveis no buffer de entrada
     e retorna o primeiro valor inteiro encontrado. Se não usássemos a variável estado, todos os três valores
     seriam lidos como o mesmo valor, pois o método Serial.parseInt() não sabe qual valor é qual. */
    if(estado == 0){
      red_outputValue = Serial.parseInt(); // Atribui o valor inteiro analisado a uma variável unsigned char
      analogWrite(red_led, red_outputValue); // Escreve o valor no pino do LED vermelho
      estado = 1;
    }
    else if (estado == 1){
      green_outputValue = Serial.parseInt(); 
      analogWrite(green_led, green_outputValue); // Escreve o valor no pino do LED verde
      estado = 2;
    }
    else if (estado == 2){
      blue_outputValue = Serial.parseInt(); 
      analogWrite(blue_led, blue_outputValue); // Escreve o valor no pino do LED azul
      estado = 0;
    }

    // Imprime os valores analisados no monitor serial
    Serial.println(red_outputValue);
    Serial.println(green_outputValue);
    Serial.println(blue_outputValue);
  }
}
// OBS: o código funcionaria se os analogWrite estivessem aqui
// porque a variável estado garante que apenas um valor seja lido por vez.
// Por exemplo:
// - Quando estado == 0, apenas o valor de red_outputValue é lido e armazenado.
//   Nesse caso, os analogWrite seriam executados com:
//   - red_outputValue (novo valor lido)
//   - green_outputValue (valor anterior, não alterado)
//   - blue_outputValue (valor anterior, não alterado)
// - Quando estado == 1, apenas o valor de green_outputValue é lido e armazenado.
//   Nesse caso, os analogWrite seriam executados com:
//   - red_outputValue (valor anterior, não alterado)
//   - green_outputValue (novo valor lido)
//   - blue_outputValue (valor anterior, não alterado)
// - Quando estado == 2, apenas o valor de blue_outputValue é lido e armazenado.
//   Nesse caso, os analogWrite seriam executados com:
//   - red_outputValue (valor anterior, não alterado)
//   - green_outputValue (valor anterior, não alterado)
//   - blue_outputValue (novo valor lido)
// Dessa forma, os LEDs seriam atualizados corretamente, um por vez, com os valores mais recentes lidos.