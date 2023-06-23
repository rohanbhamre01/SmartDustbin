#serial com library
import serial
from time import sleep
import string
import pynmea2
#push message related libraries
from pushbullet import Pushbullet
pb= Pushbullet("") #Pusbullet API key

#button and UI
import pyfiglet
from gpiozero import Button
button= Button(23)


#print registered devices
print(pb.devices[0])

#define push notification
def notification():
    #get devices the user has access to
    real = pb.get_device('Device Name')
    #send push notification over to user("head","body")
    push =  real.push_note("Alert!!","Dustbin is full.Click On link to see Location:\n //preset location link here//")
    #push =  real.push_note("Alert!!","Dustbin is full.Click On link to see Location:\n http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=",gps) #if Gps Device is Connected

#if Gps Device is Connected Locate GPS coordinates
# def gpslocate():
#     if line[0:6] == "$GPRMC":
#         newmsg=pynmea2.parse(newdata)
#         lat=newmsg.latitude
#         lng=newmsg.longitude
#         gps = str(lat) + "," + str(lng)

def Dustbin():
    print("Booting the Smart Dustbin...")
    print("Starting serial communication...")
    if __name__=='__main__':
        #open serial port
        ser = serial.Serial('/dev/ttyACM1',9600,timeout=1) #can change if port is different
        ser.flush()
        while True:
            if ser.in_waiting >0:
                line =  ser.readline().decode('utf-8').rstrip()
                print(line)
                if line=="!DUSTBIN FULL!":
                    #gpslocate()  #if Gps Device is Connected
                    notification()
                    print("notification sent")
                    print("Please empty the dustbin,\n press the switch to start the program")
                    sleep(1)
                    break

result = pyfiglet.figlet_format("Dust-E-Bin")
print(result)
print("\n press the button to begin:")
while True :
    button.when_pressed = Dustbin
