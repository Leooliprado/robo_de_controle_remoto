/*robô de controle remoto.43º projeto.linguagem utilizada c++

  criado por: Leonardo de Oliveira Prado
  Instagram: arduino2.0tecnologico

  Data de inicio do projeto 26/2/2024
  Data de término do projeto  06/4/2024
*/
//*************INCLUSÃO DA BIBLIOTECA
#include "BluetoothSerial.h"
//*************DEFINIÇÕES
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

#define roda_da_direita_1 2    //D2
#define roda_da_ESQUERDA_1 4   //D4
#define roda_da_direita_2 18   //D18
#define roda_da_ESQUERDA_2 19  //D19

#define lede_1 21
#define lede_2 22

#define velocidade 32

int velocidade_motor = 120;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Robô Esp32");  // Nome do dispositivo Bluetooth

  pinMode(roda_da_direita_1, OUTPUT);   // Pinagem do motor
  pinMode(roda_da_ESQUERDA_1, OUTPUT);  // Pinagem do motor
  pinMode(roda_da_direita_2, OUTPUT);   // Pinagem do motor
  pinMode(roda_da_ESQUERDA_2, OUTPUT);  // Pinagem do motor
  pinMode(lede_1, OUTPUT);
  pinMode(lede_2, OUTPUT);
  pinMode(velocidade, OUTPUT);

  analogWrite(velocidade, velocidade_motor);
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    switch (command) {

      case FORWARD:
        Serial.println("FRENTE");
        digitalWrite(roda_da_ESQUERDA_2, HIGH); //******* FRENTE
        digitalWrite(roda_da_direita_1, HIGH);

        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        delay(500);
        digitalWrite(roda_da_ESQUERDA_2, LOW);
        digitalWrite(roda_da_direita_1, LOW);
        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case BACKWARD:
        Serial.println("TRÁS");
        digitalWrite(roda_da_ESQUERDA_2, LOW);  //******* TRAS
        digitalWrite(roda_da_direita_1, LOW);

        digitalWrite(roda_da_direita_2, HIGH);
        digitalWrite(roda_da_ESQUERDA_1, HIGH);
        delay(500);
        digitalWrite(roda_da_ESQUERDA_2, LOW);
        digitalWrite(roda_da_direita_1, LOW);
        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case LEFT:
        Serial.println("ESQUERDA");
        digitalWrite(roda_da_ESQUERDA_2, HIGH);  //*******ESQUERDA
        digitalWrite(roda_da_direita_1, LOW);

        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, HIGH);
        delay(250);
        digitalWrite(roda_da_ESQUERDA_2, LOW);
        digitalWrite(roda_da_direita_1, LOW);
        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case RIGHT:
        Serial.println("DIREITA");
        digitalWrite(roda_da_ESQUERDA_2, LOW);  //*******DIREITA
        digitalWrite(roda_da_direita_1, HIGH);

        digitalWrite(roda_da_direita_2, HIGH);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        delay(250);
        digitalWrite(roda_da_ESQUERDA_2, LOW);
        digitalWrite(roda_da_direita_1, LOW);
        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case CIRCLE:
        Serial.println("CÍRCULO DIREITA");
        digitalWrite(roda_da_ESQUERDA_2, LOW);  //*******DIREITA
        digitalWrite(roda_da_direita_1, HIGH);

        digitalWrite(roda_da_direita_2, HIGH);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        delay(125);
        digitalWrite(roda_da_ESQUERDA_2, LOW);
        digitalWrite(roda_da_direita_1, LOW);
        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case CROSS:
        Serial.println("CRUZAMENTO");
        velocidade_motor += 20;

        if (velocidade_motor > 255) {
          velocidade_motor = 100;
        }

        analogWrite(velocidade, velocidade_motor);
        break;
      case TRIANGLE:
        Serial.println("TRIÂNGULO");
        digitalWrite(lede_1, !digitalRead(lede_1));
        digitalWrite(lede_2, !digitalRead(lede_2));
        break;
      case SQUARE:
        Serial.println("QUADRADO ESQUERDA");
        digitalWrite(roda_da_ESQUERDA_2, HIGH);  //*******ESQUERDA
        digitalWrite(roda_da_direita_1, LOW);

        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, HIGH);
        delay(125);
        digitalWrite(roda_da_ESQUERDA_2, LOW);
        digitalWrite(roda_da_direita_1, LOW);
        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case START:
        Serial.println("INICIAR");
        digitalWrite(roda_da_ESQUERDA_2, HIGH);  //******* INICIAR
        digitalWrite(roda_da_direita_1, HIGH);

        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case PAUSE:
        Serial.println("PAUSAR");
        digitalWrite(roda_da_ESQUERDA_2, LOW);  //******* PAUSAR
        digitalWrite(roda_da_direita_1, LOW);

        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      default:
        Serial.println("COMANDO INVÁLIDO");
        // Comando inválido recebido
        break;
    }
  }
}
