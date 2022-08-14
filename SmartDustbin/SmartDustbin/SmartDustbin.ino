//definitions 
#include <Servo.h>
Servo servo1;

//sensor for led
#define trigPin 7
#define echoPin 8

//sensor for servo
#define servotrig 4
#define servoecho 3

//led pins
#define led1 23
#define led2 24
#define led3 25
#define led4 26
#define led5 27
#define led6 28

int sound = 340;
long position;
long time;
long duration, distance;
//for servo motor
void setup() 
{
  servo1.attach(5);//servo pin Config
  pinMode(servotrig, OUTPUT);
  pinMode(servoecho, INPUT);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}
 
void loop() 
{
  ultraservo();//for servo
  servo1.write(0);
  if(position <= 20)//cms
  {
  servo1.write(90);//degree
  }
  
  ultraled();//for led
  if (distance <= 30) 
  {
    digitalWrite(led1, HIGH);
    sound = 250;
  }
  else 
  {
    digitalWrite(led1,LOW);
  }
  if (distance < 25)
  {
      digitalWrite(led2, HIGH);
      sound = 260;
  }
  else 
  {
      digitalWrite(led2, LOW);
  }
  if (distance < 20) 
  {
      digitalWrite(led3, HIGH);
      sound = 270;
  }
  else 
  {
    digitalWrite(led3, LOW);
  }
  if (distance < 15)
  {
    digitalWrite(led4, HIGH);
    sound = 280;
  }
  else 
  {
    digitalWrite(led4,LOW);
  }
  if (distance < 10)
  {
    digitalWrite(led5, HIGH);
    sound = 290;
  }
  else
  {
    digitalWrite(led5,LOW);
  }
  if (distance < 5)
  {
    digitalWrite(led6, HIGH);
    sound = 300;
  }
  else
  {
    digitalWrite(led6,LOW);
  }
  if (distance <= 5)
  {
    Serial.println("Dustbin Full");
  }
  else
  {
    Serial.print(distance/0.3);
    Serial.println(" %");
  }
  delay(1000);
}//main code end

void ultraservo()
  {
    digitalWrite(servotrig, LOW);
    delayMicroseconds(2);
    digitalWrite(servotrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(servotrig, LOW);
    time = pulseIn(servoecho, HIGH);
    position = time*0.034/2;
      }
void ultraled()
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
      }
