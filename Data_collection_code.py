import cv2
import mediapipe as mp
import time
import math
from tensorflow.keras.models import load_model
import numpy as np
import serial
import keyboard
import csv
import numpy
import datetime

f = open("Crawl1.csv", "w")



class poseDetector():

    def __init__(self, mode=False, upBody=False, smooth=True,
                 detectionCon=0.5, trackCon=0.5):

        self.mode = mode
        self.upBody = upBody
        self.smooth = smooth
        self.detectionCon = detectionCon
        self.trackCon = trackCon

        self.mpDraw = mp.solutions.drawing_utils
        self.mpPose = mp.solutions.pose
        self.pose = self.mpPose.Pose(self.mode, self.upBody, self.smooth,
                                     self.detectionCon, self.trackCon)

    def findPose(self, img, draw=True):
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.pose.process(imgRGB)
        if self.results.pose_landmarks:
            if draw:
                self.mpDraw.draw_landmarks(img, self.results.pose_landmarks,
                                           self.mpPose.POSE_CONNECTIONS)
        return img

    def findPosition(self, img, draw=True):
        self.lmList = []
        if self.results.pose_landmarks:
            for id, lm in enumerate(self.results.pose_landmarks.landmark):
                h, w, c = img.shape
                
                cx, cy = int(lm.x * w), int(lm.y * h)
                self.lmList.append([id + 1, cx, cy])
                if draw:
                    cv2.circle(img, (cx, cy), 5, (255, 0, 0), cv2.FILLED)
        return self.lmList

def main():
    cap = cv2.VideoCapture(0)
    pTime = 0
    detector = poseDetector()

    model = load_model("pose_model3.h5")
    writer = csv.writer(f)
    key = keyboard.read_key()


    if key == 'z':
        time.sleep(5)
        start_time = datetime.datetime.now()
        while True:
            success, img = cap.read()
            img = detector.findPose(img)
            lmList = detector.findPosition(img, draw=False)
            lmList = np.array(lmList)
            a = lmList.flatten()
            a = a.tolist()
            print(a)
            

            
            writer.writerow(str(a).split(','))
            
            later_time = datetime.datetime.now()
            difference = later_time - start_time
            sec_diff = difference.total_seconds()
            sec_diff = round(sec_diff)
            print(sec_diff)
            print("\n")
            if sec_diff == 180:
                break
            cv2.imshow("Image", img)
            cv2.waitKey(100)

    


if __name__ == "__main__":
    main()
