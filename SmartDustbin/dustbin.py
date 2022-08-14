#serial com library
import serial
from time import sleep
import string
import pynmea2
#push message related libraries
from pushbullet import Pushbullet
pb= Pushbullet("o.wvpfI303QYadbHKKG1Nw8lj5nP3NhOyg")

#print registered devices
print(pb.devices[0])

#define push notification
def notification():
    #get devices the user has access to
    real = pb.get_device('Realme RMX1931')
    #send push notification over to user("head","body")
    push =  real.push_note("Alert!!","Dustbin is full.Click On link to see Location:\n http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=19.250992,73.139576")

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
