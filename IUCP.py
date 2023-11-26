from ultralytics import YOLO
import cv2
import math
import serial
import time

arduino = serial.Serial('COM3', 9600)
time.sleep(1)

model = YOLO("latasbotellas.pt")

cap = cv2.VideoCapture(0)
clsName = ['bottle', 'can']

# Initialize counters and threshold for each class
bottle_count = 0
can_count = 0
class_threshold = 5  # Set the threshold for resetting the counter

while True:
    ret, frame = cap.read()

    resultados = model.predict(frame, imgsz=640)
    anotaciones = resultados[0].plot()
    results = model(frame, stream=True, verbose=False)

    for res in results:
        boxes = res.boxes
        for box in boxes:
            x1, y1, x2, y2 = box.xyxy[0]
            cls = int(box.cls[0])
            conf = math.ceil(box.conf[0])

            if conf > 0.5:
                if cls == 0:
                    print("Botella")
                    bottle_count += 1
                    if bottle_count >= class_threshold:
                        print("Botella detectada")
                        bottle_count = 0
                        command = "p"
                        arduino.write(command.encode())
                elif cls == 1:
                    print("Lata")
                    can_count += 1
                    if can_count >= class_threshold:
                        print("Lata detectada")
                        can_count = 0
                        command = "m"
                        arduino.write(command.encode())

    cv2.imshow("deteccion", anotaciones)

    if cv2.waitKey(1) == 27:
        arduino.close()
        break


# Release the camera and close OpenCV windows
cap.release()
cv2.destroyAllWindows()
