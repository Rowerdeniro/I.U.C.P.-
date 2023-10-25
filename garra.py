import serial
import time
arduino = serial.Serial('COM3', 9600)
time.sleep(1)

while True:
    command = input("Ingresa 'M' para mover todos los servos (bajar, abrir la pinza, cerrar, subir): ")

    if command == 'M':
        arduino.write(command.encode())  # Envia el comando a Arduino
    else:
        print("Comando no válido. Ingresa 'M'.")
arduino.close()