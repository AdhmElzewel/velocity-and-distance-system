
#include <LiquidCrystal.h> 
LiquidCrystal LCD(8,9,10,11,12,13); 
#define trig 2 
#define echo 3
/*#define trig1 4 
#define echo1 5 
#define trig2 6 
#define echo2 7*/
 float td,velocity,c,f,RightSensor;
 //float s1,s2,time1,time2;
 float my_array[100];
 float a=0;
 float t, distance;
 float ult(){
 digitalWrite(trig,LOW);
 delayMicroseconds(5);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);   
 t=pulseIn(echo,HIGH);
 distance=t/58.2;
 return distance;}
 /*float t1, distance1;
 float ult1(){
 digitalWrite(trig1,LOW);
 delayMicroseconds(5);
 digitalWrite(trig1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig1,LOW);   
 t1=pulseIn(echo1,HIGH);
 distance1=t/58.2;
 return distance1;}
 float t2 , distance2;
 float ult2(){
 digitalWrite(trig2,LOW);
 delayMicroseconds(5);
 digitalWrite(trig2,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig2,LOW);   
 t2=pulseIn(echo2,HIGH);
 distance2=t2/58.2;
 return distance2;}*/
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
 /* pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);*/
  LCD.begin(16,2); 
  LCD.setCursor(0,0);  
  LCD.print("Max Distancs:");  
  LCD.setCursor(0,1);  
  //LCD.print("speed:");  
}
void loop() {
c = ult();
 if (c>=7.5){
 f=0; 
 a=0;
Serial.println(f);
Serial.println(a);
LCD.setCursor(0,1);   
LCD.print(a);
LCD.print(" cm");}
else if((c>0)&&(c<7.5)){
  delay(10);
for (int i = 0; i < 100; i++) {
  RightSensor = ult();
  my_array[i] = RightSensor;
  delay(10);}
f= minimum(my_array,100);
a=8-f;
Serial.println(f);
Serial.println(a);
LCD.setCursor(0,1);   
LCD.print(a); 
LCD.print(" cm");
for (int i = 0; i < 100; i++) {
Serial.print("Distance= ");
Serial.println(my_array[i]);}
delay(3000);
}
/*s1=ult1();
 s2=ult2();
if((s1<15)&&(s1>0)){
  time1=millis();
  time2=0;
  delay(10);}
if((s2<15)&&(s2>0)){
  time2=millis();}
if(time1==0||time2==0){
  velocity=0;}
else{
td=(time2-time1)/1000;
velocity=10/td;}
Serial.println(s1);
Serial.println(s2);
Serial.println(td);
//Serial.println(time2);
Serial.println(velocity);
LCD.setCursor(7,1);   
LCD.print(velocity);
LCD.print(" cm/s");*/
}
 float minimum(float* array, int size){
 int minIndex = 0;
 float min = array[minIndex];
 for (int i=1; i<size; i++){
 if (min>array[i]){
 min = array[i];
 minIndex = i;}}
 return min;}
