/********************************************************************************
 Code for Smart Dustbin
 Written by: Rohan Bhamre 
 
 ADC Connection:
        Pins Function      Wire Color
        VCC  +5V          Blue(Ultraservo),Grey(Servo),Red(UltraLCD),Red(LCD)
        GND  Ground       White(Ultraservo),Black(Servo),Brown(ULtraLCD),Brown(LCD)
        03   echopin      yellow
        04   trigpin      orange
        05   servoecho    Grey
        06   servotrig    purple
        07   servosig     white
        SDA   SDA         Orange
        SCL   SCL         Yellow
   
*********************************************************************************/
#include <Wire.h> //Enable I2C
// LCD library For Hardware Application
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// LCD library For Tinkercad
// #include <Adafruit_LiquidCrystal.h>
// Adafruit_LiquidCrystal lcd(0);

#include <Servo.h>
Servo myservo;
//Servo signal pin
#define servosig 7  
//Ultrasonic sensor for servo
#define servotrig 6 
#define servoecho 5
//Ultrasonic sensor for LCD
#define trigPin 4 // orange
#define echoPin 3 //yellow


long lcd_trig_duration;
long servo_trig_duration;
float lcd_trig_dist;
float servotrigdist;
float Fill_level;

void setup() 
{ 
  Serial.begin(9600);
  //servo,Ultrasonic pin Config
  myservo.attach(servosig);
  pinMode(servotrig, OUTPUT);
  pinMode(servoecho, INPUT);
  //LCD,Ultrasonic pin config
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //lcd.begin(16, 2);     //for Tinkercad
  
  // lcd.init();        //For hardware
  // lcd.backlight();
  // lcd.clear();
  bootanimation();
  // delay(500);
  // lcd.clear(); 
}
 
void loop() 
{
  //for servo
  ultraservo();
  myservo.write(90);
  if(servotrigdist <= 40)//cms
    {
    myservo.write(0);
    lcd.setCursor(5,1);
    lcd.print("Open");
    Serial.println("Open");
    }
  else { 
    lcd.setCursor(5,1);
  	lcd.print("Closed");
    Serial.println("Closed");

  }
  //for LCD
  ultraled();
  if (lcd_trig_dist >= 32)//cm
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("!Out of Dustbin!");
    Serial.println("!Out of Dustbin!");
    delay(2000);
    lcd.clear();
  }
  else if (lcd_trig_dist <= 5)//cm
  {
    lcd.clear();
    lcd.setCursor(1,1);
    lcd.print("!DUSTBIN FULL!");
    Serial.println("!DUSTBIN FULL!");
    delay(2000);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Capacity:");
    //lcd.setBacklight(1);
    lcd.setCursor(15,0);
    lcd.print("%");
    Fill_level =abs(100-(lcd_trig_dist/31.87)*100) ;
    lcd.setCursor(10,0);
    lcd.print(Fill_level);
    Serial.print("Capacity: ");
    Serial.println(Fill_level);
    delay(250);
  }
}

//functions
void bootanimation()
  {
    lcd.setCursor(1, 0);
    lcd.print("STARTING NOW!");
    Serial.println("STARTING NOW!");
    delay(1000);
    lcd.setCursor(1, 0);
    lcd.print("SMART DUSTBIN");
    lcd.setCursor(0, 1);
    lcd.print("LOADING[");
    lcd.setCursor(15, 1);
    lcd.print("]");
    for (int i = 0; i < 6; i++)
    {
      delay(500);
      lcd.setCursor(i + 8, 1);
      lcd.print("=>");
    }
    lcd.setCursor(14, 1);
    lcd.print("=");
    delay(500);
    lcd.clear();
  }
void ultraservo()
  {
    digitalWrite(servotrig,LOW);
    delayMicroseconds(2);
    digitalWrite(servotrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(servotrig, LOW);
    servo_trig_duration = pulseIn(servoecho, HIGH);
    servotrigdist = (servo_trig_duration*0.0346)/2;//cm
      }
void ultraled()
  {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    lcd_trig_duration = pulseIn(echoPin, HIGH);
    lcd_trig_dist = (lcd_trig_duration*0.0346)/2;//cm
      }
