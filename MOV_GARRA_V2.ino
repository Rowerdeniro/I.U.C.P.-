#include <Servo.h>

Servo pinza;
Servo servoX;
Servo servoY;

int posAbierto = 1;   // Posición para abrir la pinza
int posCerrado = 173;   // Posición para cerrar la pinza
int posX = 80;         // Posición inicial en el eje X
int posY = 180;         // Posición inicial en el eje Y

void setup() {
  pinza.attach(9);      // Conecta el servo de la pinza al pin 9
  servoX.attach(10);    // Conecta el servo del eje X al pin 10
  servoY.attach(11);    // Conecta el servo del eje Y al pin 11
  pinza.write(posCerrado);  // Inicialmente, la pinza está cerrada
  servoX.write(posX);       // Posición inicial en el eje X
  servoY.write(posY);       // Posición inicial en el eje Y
  Serial.begin(9600);  // Inicializa la comunicación serial
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'm') { // Mover todos los servos a la vez
      pinza.write(posAbierto);
      delay(1000);  // Espera 1 segundo
      servoX.write(posX - 60); // Mueve el servo X
      delay(1000);  // Espera 1 segundo
      servoY.write(posY - 80); // Mueve el servo Y
      delay(1000);  // Espera 1 segundo
      pinza.write(posCerrado);
      delay(1000);  // Espera 1 segundo
      servoX.write(posX); // Vuelve al punto inicial en X
      delay(1000);  // Espera 1 segundo
      servoY.write(posY); // Vuelve al punto inicial en Y
    }
    else if (command == 'r'){
      pinza.write(posCerrado);
      delay(1000);  // Espera 1 segundo
      servoY.write(posY - 80); // Vuelve al punto inicial en Y
      delay(1000);
      pinza.write(posAbierto);
      delay(1000);  // Espera 1 segundo
      servoY.write(posY); // Vuelve al punto inicial en Y
      delay(1000);
      pinza.write(posCerrado);
      delay(1000);

    }
  }
}