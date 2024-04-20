/*robô de controle remoto.43º projeto.linguagem utilizada c++

  criado por: Leonardo de Oliveira Prado
  Instagram: arduino2.0tecnologico

  Data de inicio do projeto 26/2/2024
  Data de término do projeto  20/4/2024
*/
//*************INCLUSÃO DA BIBLIOTECA
#include "BluetoothSerial.h"
//*************DEFINIÇÕES
#define FRENTE 'F'
#define TRAS 'B'
#define ESQUERDA 'L'
#define DIREITA 'R'
#define VELOCIDADE0 '0'
#define VELOCIDADE1 '1'
#define VELOCIDADE2 '2'
#define VELOCIDADE3 '3'
#define VELOCIDADE4 '4'
#define VELOCIDADE5 '5'
#define VELOCIDADE6 '6'
#define VELOCIDADE7 '7'
#define VELOCIDADE8 '8'
#define VELOCIDADE9 '9'
#define VELOCIDADEq 'q'
#define FAROL1 'W'
#define FAROL0 'w'
#define FAROLTRAS1 'U'
#define FAROLTRAS0 'u'
#define ALERTA1 'X'
#define ALERTA0 'x'
#define PAUSE 'S'

#define roda_da_direita_1 2    //D2
#define roda_da_ESQUERDA_1 4   //D4
#define roda_da_direita_2 18   //D18
#define roda_da_ESQUERDA_2 19  //D19

#define lede_1 21
#define lede_2 22
#define lede_tras 23

#define velocidade 32

int velocidade_motor = 250;

bool alertaAtivado = false;

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
  pinMode(lede_tras, OUTPUT);
  pinMode(velocidade, OUTPUT);

  analogWrite(velocidade, velocidade_motor);
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    switch (command) {

      case FRENTE:
        Serial.println("FRENTE");
        digitalWrite(roda_da_ESQUERDA_2, HIGH);  //******* FRENTE
        digitalWrite(roda_da_direita_1, HIGH);

        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case TRAS:
        Serial.println("TRÁS");
        digitalWrite(roda_da_ESQUERDA_2, LOW);  //******* TRAS
        digitalWrite(roda_da_direita_1, LOW);

        digitalWrite(roda_da_direita_2, HIGH);
        digitalWrite(roda_da_ESQUERDA_1, HIGH);
        break;
      case ESQUERDA:
        Serial.println("ESQUERDA");
        digitalWrite(roda_da_ESQUERDA_2, HIGH);  //*******ESQUERDA
        digitalWrite(roda_da_direita_1, LOW);

        digitalWrite(roda_da_direita_2, LOW);
        digitalWrite(roda_da_ESQUERDA_1, HIGH);
        break;
      case DIREITA:
        Serial.println("DIREITA");
        digitalWrite(roda_da_ESQUERDA_2, LOW);  //*******DIREITA
        digitalWrite(roda_da_direita_1, HIGH);

        digitalWrite(roda_da_direita_2, HIGH);
        digitalWrite(roda_da_ESQUERDA_1, LOW);
        break;
      case VELOCIDADE0:
        velocidade_motor = 0;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE1:
        velocidade_motor = 60;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE2:
        velocidade_motor = 80;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE3:
        velocidade_motor = 90;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE4:
        velocidade_motor = 110;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE5:
        velocidade_motor = 130;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE6:
        velocidade_motor = 150;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE7:
        velocidade_motor = 170;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE8:
        velocidade_motor = 190;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADE9:
        velocidade_motor = 210;
        analogWrite(velocidade, velocidade_motor);
        break;
      case VELOCIDADEq:
        velocidade_motor = 250;
        analogWrite(velocidade, velocidade_motor);
        break;
      case FAROL1:
        digitalWrite(lede_1, HIGH);
        digitalWrite(lede_2, HIGH);
        break;
      case FAROL0:
        digitalWrite(lede_1, LOW);
        digitalWrite(lede_2, LOW);
        break;
      case FAROLTRAS1:
        digitalWrite(lede_tras, HIGH);
        break;
      case FAROLTRAS0:
        digitalWrite(lede_tras, LOW);
        break;
      case ALERTA1:
        alertaAtivado = true;
        break;
      case ALERTA0:
        alertaAtivado = false;
        digitalWrite(lede_1, LOW);
        digitalWrite(lede_2, LOW);
        digitalWrite(lede_tras, LOW);
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
  if (alertaAtivado) {
    digitalWrite(lede_tras, HIGH);
    digitalWrite(lede_1, HIGH);
    digitalWrite(lede_2, LOW);
    delay(100);
    digitalWrite(lede_2, HIGH);
    digitalWrite(lede_1, LOW);
    digitalWrite(lede_tras, LOW);
    delay(100);
  }
}
