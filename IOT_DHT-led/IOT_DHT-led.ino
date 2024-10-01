#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
const int ledVerde = 5;
const int ledVermelho = 6;
const int ledAmarelo = 7;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return; }

  if (t <= 25){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  else if (t > 25 && t <= 30){          
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  else if (t > 30){
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
  }

  Serial.println(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
}

