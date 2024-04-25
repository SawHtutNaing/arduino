
//https://www.roboindia.com/tutorials

#include<Servo.h>

const int LED=2;            // LED connect to Digital Pin 
const int LDRSensor= A0;    //Sensor pin connects to analog pin A0

Servo myservo;
const int trigPin=3;
const int echoPin=5; 
long tmeduration;
int distance;




int state;                  //declaring variable to store the reading 
int threshold=600;          //threshold voltage declared 

void setup() 
{
  myservo.attach(9);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
 
  pinMode (LED, OUTPUT);   
  Serial.begin(9600); 
}

void loop()
{
  state= analogRead(LDRSensor); //sensor reading value stored in state variable
  if (state < threshold)
    {
      digitalWrite(LED, HIGH); //if the light is below the threshold value, the LED will turns on
   
      delay(2000);
    }
  else
    {
      digitalWrite(LED, LOW); //otherwise, the LED is off
     
      delay(1000);
    }

    digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
 
tmeduration=pulseIn(echoPin,HIGH);
distance=(0.034*tmeduration)/2;
 
if(distance<=10){
 
myservo.write(90);

  }
else{
myservo.write(0);}
 

 
delay(1);
}