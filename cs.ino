#include <Servo.h>
Servo servoX;
Servo servoY;
Servo pinza;
Servo servo360;

int posAbierto = 1;   // Posición para abrir la pinza
int posCerrado = 173;   // Posición para cerrar la pinza
int posX = 180;         // Posición inicial en el eje X
int posY = 180;         // Posición inicial en el eje Y
int pos360quieto = 89;
int pos360Izquierda = 0;  // Posición inicial del nuevo servo
int pos360Derecha = 180;
void setup() {
  pinza.attach(9);      // Conecta el servo de la pinza al pin 9
  servoX.attach(10);    // Conecta el servo del eje X al pin 10
  servoY.attach(11);
  servo360.attach(12);    // Conecta el servo del eje Y al pin 11
  pinza.write(posCerrado);  // Inicialmente, la pinza está cerrada
  servoX.write(posX);       // Posición inicial en el eje X
  servoY.write(posY);
  servo360.write(pos360quieto);       // Posición inicial en el eje Y
  Serial.begin(9600);  // Inicializa la comunicación serial
}
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

     // Mover todos los servos a la vez
    if (command == 'm') { // Mover todos los servos a la vez
      pinza.write(posAbierto);
      delay(500);  // Espera 1 segundo // Espera 1 segundo
      servoX.write(posX - 100);
      delay(500); // Mueve el servo X
      servoY.write(posY - 180); // Mueve el servo Y
      delay(500);  // Espera 1 segundo
      pinza.write(posCerrado);
      delay(500);  // Espera 1 segundo
      servoX.write(posX); // Vuelve al punto inicial en X
      delay(500);  // Espera 1 segundo
      servoY.write(posY); // Vuelve al punto inicial en Y
      delay(500);
      servo360.write(pos360Derecha);
      delay(1500);
      servo360.write(pos360quieto);  // Mover el servo a la nueva posición
      delay(500);
      pinza.write(posCerrado);
      delay(500);  // Espera 1 segundo
      servoY.write(posY - 180); // Vuelve al punto inicial en Y
      delay(500);
      servoX.write(posX - 90); // Vuelve al punto inicial en Y
      delay(500);
      pinza.write(posAbierto);
      delay(500);  // Espera 1 segundo
      servoY.write(posY); // Vuelve al punto inicial en Y
      delay(500);
      servoX.write(posX); // Vuelve al punto inicial en Y
      delay(500);
      pinza.write(posCerrado);
      delay(500);
      servo360.write(pos360Izquierda);
      delay(1500);
     servo360.write(pos360quieto);  // Mover el servo a la nueva posición
      delay(1000);
    }
    else if (command == 'p'){
      pinza.write(posAbierto);
      delay(500);  // Espera 1 segundo // Espera 1 segundo
      servoX.write(posX - 100);
      delay(500); // Mueve el servo X
      servoY.write(posY - 180); // Mueve el servo Y
      delay(500);  // Espera 1 segundo
      pinza.write(posCerrado);
      delay(500);  // Espera 1 segundo
      servoX.write(posX); // Vuelve al punto inicial en X
      delay(500);  // Espera 1 segundo
      servoY.write(posY); // Vuelve al punto inicial en Y
      delay(500);
      servo360.write(pos360Derecha);
      delay(3000);
      servo360.write(pos360quieto);  // Mover el servo a la nueva posición
      delay(500);
      pinza.write(posCerrado);
      delay(500);  // Espera 1 segundo
      servoY.write(posY - 180); // Vuelve al punto inicial en Y
      delay(500);
      servoX.write(posX - 90); // Vuelve al punto inicial en Y
      delay(500);
      pinza.write(posAbierto);
      delay(500);  // Espera 1 segundo
      servoY.write(posY); // Vuelve al punto inicial en Y
      delay(500);
      servoX.write(posX); // Vuelve al punto inicial en Y
      delay(500);
      pinza.write(posCerrado);
      delay(500);
      servo360.write(pos360Izquierda);
      delay(3000);
     servo360.write(pos360quieto);  // Mover el servo a la nueva posición
      delay(1000);

    } 
  
}
}