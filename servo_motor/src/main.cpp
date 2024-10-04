#include <Arduino.h>
#include <Servo.h>

Servo meuServo; // Cria um objeto servo
const int trigPin = 23; // Pino do Trigger do HC-SR04
const int echoPin = 22; // Pino do Echo do HC-SR04
const int servoPin = 18; // Pino do servo

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  meuServo.attach(servoPin); // Anexa o pino do servo
  meuServo.write(0); // Inicializa o servo em 0 graus
  pinMode(trigPin, OUTPUT); // Define o pino do Trigger como saída
  pinMode(echoPin, INPUT); // Define o pino do Echo como entrada
}

void loop() {
  long duracao, distancia;

  // Limpa o pino do Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Define o Trigger em HIGH por 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o tempo do Echo
  duracao = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  distancia = duracao * 0.034 / 2;

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Se a distância for menor que 5 cm, abre o servo em 90 graus
  if (distancia < 5) {
    meuServo.write(90); // Move o servo para 90 graus
  } else {
    meuServo.write(0); // Retorna o servo para 0 graus
  }

  delay(500); // Aguarda meio segundo antes de medir novamente
}