#include <LiquidCrystal.h> 
LiquidCrystal LCD(8,9,10,11,12,13); 
#define trig1 4 
#define echo1 5 
#define trig2 6 
#define echo2 7
float Time,velocity=0,s1,s2,time1,time2,flag1,flag2;
float t1, distance1;
float ult1(){
 digitalWrite(trig1,LOW);
 delayMicroseconds(5);
 digitalWrite(trig1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig1,LOW);   
 t1=pulseIn(echo1,HIGH);
 distance1=t1/58.2;
 return distance1;}
float t2=0 , distance2=0;
float ult2(){
 digitalWrite(trig2,LOW);
 delayMicroseconds(5);
 digitalWrite(trig2,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig2,LOW);   
 t2=pulseIn(echo2,HIGH);
 distance2=t2/58.2;
     return distance2;}
void setup() {
  Serial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  LCD.begin(16,2); 
  LCD.setCursor(0,0);  
  LCD.print("Max X:");  
  LCD.setCursor(0,1);  
  LCD.print("speed:");  
}
void loop() {
  velocity=0;
 s1=ult1();
 s2=ult2();
if(s1<=15){time1 = millis();time2=0;
if(s2<=15){time2 = millis();}
if(time1 > time2){Time = time1 - time2;}
else if(time2 > time1){Time = time2 - time1;}
Time=Time/1000;
velocity=(10/Time);}
Serial.println(s1);
Serial.println(s2);
Serial.println(time1);
Serial.println(time2);
Serial.println(Time);
Serial.println(velocity);
LCD.setCursor(7,1);   
LCD.print(velocity); 
LCD.print(" cm/s");
}
