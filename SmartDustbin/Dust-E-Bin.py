from gpiozero import Button
from time import sleep
import subprocess
import pyfiglet
button= Button(23)

def toggle():
    print("Booting the Smart Dustbin...")
    print("Starting serial communication...")
    subprocess.Popen('python3','dustbin.py')

result = pyfiglet.figlet_format("Dust-E-Bin")
print(result)
print("\n press the button to begin:")
while True :
    button.when_pressed = toggle