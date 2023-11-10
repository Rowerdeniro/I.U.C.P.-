from ultralytics import YOLO
import cv2

model = YOLO("best.pt")

cap = cv2.VideoCapture(0)

while True:

    ret, frame = cap.read()

    resultados= model.predict(frame, imgsz = 640)

    anotaciones = resultados[0].plot()

    cv2.imshow("deteccion", anotaciones)

    if cv2.waitKey(1) == 27:
        break
cap.release()
cv2.destroyAllWindows()