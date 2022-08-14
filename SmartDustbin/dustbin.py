#serial com library
import serial
from time import sleep
import string
import pynmea2
#push message related libraries
from pushbullet import Pushbullet
pb= Pushbullet("put your code here")

#print registered devices
print(pb.devices[0])

#define push notification
def notification():
    #get devices the user has access to
    real = pb.get_device('Device name here')
    #send push notification over to user("head","body")
    push =  real.push_note("Alert!!","Dustbin is full.Click On link to see Location:\n (preset location here)")

#main
if __name__=='__main__':
    #open serial port
    ser=serial.Serial('/dev/ttyACM1',9600,timeout=1)
    ser.flush()
    while True:
        if ser.in_waiting >0:
            line =  ser.readline().decode('utf-8').rstrip()
            print(line)
            if line=="Dustbin Full":
                notification()
                print("notification sent")
                print("Please empty the dustbin,\n press the switch to start the program")
                sleep(1)
                break
