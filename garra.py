import serial
import time
arduino = serial.Serial('COM3', 9600)
time.sleep(1)

while True:
    command = input("Ingresa 'm' o 'r' para mover todos los servos (bajar, abrir la pinza, cerrar, subir): ")

    if command == 'm':
        arduino.write(command.encode())  # Envia el comando a Arduino
    elif command == 'r': 
        arduino.write(command.encode())
    else:
        print("Comando no válido. Ingresa 'm' o 'r'.")
arduino.close()