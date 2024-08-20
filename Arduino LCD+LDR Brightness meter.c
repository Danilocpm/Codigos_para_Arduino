#include <LiquidCrystal.h>

// Configuração dos pinos para o LCD
const int rs = 3, en = 4, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pinos do sensor e LED
const int sensorPin = A0;
const int ledPin = 9;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  // Configura o LED como saída
  pinMode(ledPin, OUTPUT);

  // Configuração do LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Lê o valor do sensor
  int sensorValue = readSensor(sensorPin);
  
  // Exibe o valor no LCD
  displayOnLCD(sensorValue);
  
  // Ajusta o brilho do LED com base no valor do sensor
  adjustLEDBrightness(sensorValue);
  
  // Aguarda um pouco antes da próxima leitura
  delay(500);
}

int readSensor(int pin) {
  int value = analogRead(pin);
  Serial.print("Valor do Sensor: ");
  Serial.println(value);
  return value;
}

void displayOnLCD(int sensorValue) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Luminosidade:");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);
}

void adjustLEDBrightness(int sensorValue) {
  int brightness = map(sensorValue, 0, 310, 0, 255); // Mapeia o valor para a faixa PWM do LED
  analogWrite(ledPin, brightness);
}


// https://www.tinkercad.com/things/jSsMBfMbmBj-arduino-lcdldr-brightness-meter/editel?sharecode=5nki9Rp67eTPqYk1tOKE14Oc12w8u1hJRnFEtlNvKHw