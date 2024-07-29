#include <Servo.h>

Servo servo;  // Cria um objeto servo
const int laserPin = 7;

void setup() {
  pinMode(laserPin, OUTPUT); // Configura o pino do LED como saída
  servo.attach(9);  // Atribui o pino 9 ao objeto servo criado anteriormente
  
  randomSeed(analogRead(0));
}

void loop() {
  // Mover o servo de forma aleatória
  int servoPosition = random(50, 110); // Gera uma posição aleatória entre 20 e 120 graus
  servo.write(servoPosition); // Move o servo para a posição aleatória
  delay(random(300, 1200)); // Espera um tempo aleatório entre 300ms e 1200ms

  // Ligar/desligar o Laser de forma aleatória com 90% de chance de estar ligado
  int randomValue = random(0, 10); // Gera um valor aleatório entre 0 e 9
  int laserState = (randomValue < 9) ? HIGH : LOW; // 90% de chance de ser HIGH, 10% de chance de ser LOW
  digitalWrite(laserPin, laserState); // Liga ou desliga o laser com base no valor aleatório
  delay(random(300, 2000)); // Espera um tempo aleatório entre 300ms e 600ms
}
