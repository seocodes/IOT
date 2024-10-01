//COMENTAR ESSE CODIGO
//COMENTAR ESSE CODIGO
//COMENTAR ESSE CODIGO
//COMENTAR ESSE CODIGO
int mult(int a, int b){
  int resultado = 0;
  for (int i = 0; i < b; i++){
  resultado += a; 
  }
  return resultado;
}

void imprimirResultado(int r){
  Serial.print("Resultado: ");
  Serial.println(r);
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Digite o primeiro valor: ");
  while(true){
    if (Serial.available() > 0){
      break;
    }
  }  
  int x = Serial.parseInt();
  Serial.println(x);

  Serial.print("Digite o segundo valor: ");
  while(true){
    if (Serial.available() > 0){    
      break;
    }
  }  
  int y = Serial.parseInt();
  Serial.println(y);

    int z = mult(x,y);
    imprimirResultado(z);
}



