#include <AFMotor.h>

#include <NewPing.h>

#include <Servo.h>  //include servo.h library
Servo myservo;

int pos = 0;    
boolean fire = false;
 
#define Left 9     // left sensor
#define Right 10    // right sensor
#define Forward 8   //front sensor
#define pump 12

int Echo1 = A4; //left_sensor echo
int Trig1 = A5; //left_sensor trig
int Echo2 = A3; //central_sensor echo
int Trig2 = A2; //central_sensor trig
int Echo3 = A0; //right_sensor echo
int Trig3 = A1; //right_sensor trig

int in1 = 4;//pin 3 arduino
int in2 = 3;//pin 4 arduino
int in3 = 6;//pin 5 arduino
int in4 = 5;//pin 6 arduino
int ENA = 2;//pin 2 arduino
int ENB = 7;//pin 7 arduino
int PWM = 200;//ATUR KECEPATAN 10 SAMPAI 255
int Left_Distance = 0,Right_Distance = 0,Middle_Distance = 0 ;
void _Forward()
{

digitalWrite(in1,HIGH);//maju
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ENA,PWM);
analogWrite(ENB,PWM);
Serial.println("cm");
}
void _Back()
{

digitalWrite(in1,LOW);//mundur
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(ENA,PWM);
analogWrite(ENB,PWM);
Serial.println("cm\t\t");
}
void _left()
{

digitalWrite(in1,LOW);//belok kiri
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ENA,PWM);
analogWrite(ENB,PWM);
Serial.println("cm\t\t");
}
void _right()
{

digitalWrite(in1,HIGH);//belok kanan
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(ENA,PWM);
analogWrite(ENB,PWM);
Serial.println("cm\t\t");
}
void _Stop()
{
digitalWrite(in1,LOW);//stop
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
digitalWrite(ENA,LOW);
digitalWrite(ENB,LOW);
Serial.println("cm\t\t");
}
//Ultrasonic distance measurement Sub function/
int Left_Distance_test()
{
digitalWrite(Trig1, LOW);
delayMicroseconds(2);
digitalWrite(Trig1, HIGH);
delayMicroseconds(20);
digitalWrite(Trig1, LOW);
float Fdistance = pulseIn(Echo1, HIGH);
delay(10);

Fdistance= Fdistance/ 29 / 2;
return (int)Fdistance;
}
int Middle_Distance_test()
{
digitalWrite(Trig2, LOW);
delayMicroseconds(2);
digitalWrite(Trig2, HIGH);
delayMicroseconds(20);
digitalWrite(Trig2, LOW);
float Fdistance = pulseIn(Echo2, HIGH);
delay(10);
Fdistance= Fdistance/ 29 / 2;
return (int)Fdistance;
}
int Right_Distance_test()
{
digitalWrite(Trig3, LOW);
delayMicroseconds(2);
digitalWrite(Trig3, HIGH);
delayMicroseconds(20);
digitalWrite(Trig3, LOW);
float Fdistance = pulseIn(Echo3, HIGH);
delay(10);
Fdistance= Fdistance/ 29 / 2;
return (int)Fdistance;
}
void setup()
{
Serial.begin(9600);
pinMode(Echo1, INPUT);
pinMode(Trig1, OUTPUT);
pinMode(Echo2, INPUT);
pinMode(Trig2, OUTPUT);
pinMode(Echo3, INPUT);
pinMode(Trig3, OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);

pinMode(Left, INPUT);
pinMode(Right, INPUT);
pinMode(Forward, INPUT);
pinMode(pump, OUTPUT);
myservo.attach(11);
myservo.write(90); 

_Stop();
}

void put_off_fire()
{
    delay (500);
    
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    
   digitalWrite(pump, HIGH);
   delay(500);
    
    for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  
  digitalWrite(pump,LOW);
  myservo.write(90);
  
  fire=false;
}

void loop()
{

if (digitalRead(Left) ==0 && digitalRead(Right)==0 && digitalRead(Forward) ==0) // 0
    {
            digitalWrite(in1, HIGH);  // LOW
            digitalWrite(in2, LOW); // HIGH
            digitalWrite(in3, HIGH); // LOW
            digitalWrite(in4, LOW); // HIGH
                
          
    }
else if (digitalRead(Forward) ==1) // 1
    {
   // _Forward();
     digitalWrite(in1, HIGH); // HIGH
     digitalWrite(in2, HIGH); // LOW
     digitalWrite(in3, HIGH); // HIGH
     digitalWrite(in4, HIGH); // LOW
    fire = true;
    }
else if (digitalRead(Left) ==1) // 1
    {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    }
else if (digitalRead(Right) ==1) // 1
    {
    digitalWrite(in1, LOW); // HIGH
    digitalWrite(in2, LOW); // HIGH
    digitalWrite(in3, LOW); // HIGH
    digitalWrite(in4, HIGH); // LOW
    }
delay(300);//change this value to increase the distance
 
     while (fire == true)
     {
      put_off_fire();
     }


Left_Distance = Left_Distance_test();
delay(10);
Middle_Distance = Middle_Distance_test();
delay(10);
Right_Distance = Right_Distance_test();
delay(10);
Serial.println("Left_Distance\tMiddle_Distance\tRight_Distance\tStatus\n");
Serial.print(Left_Distance);
Serial.print("cm\t\t");
Serial.print(Middle_Distance);
Serial.print("cm\t\t");
Serial.print(Right_Distance);
Serial.print("cm\t\t");

if(Middle_Distance<=80)
// if(Middle_Distance<=20)
{
/* _Stop();
delay(1000);*/
// _Stop();
// delay(1000);
// _right();

if(Right_Distance>Left_Distance)
{
// if((Right_Distance<=30)&&(Left_Distance<=30))
if((Right_Distance<=20)&&(Left_Distance<=20))
{_Stop();
delay(200);
_Back();
delay(2000);

}
else{
// _Back();
// delay(2000);
_right();
delay(500);}

}
else if(Right_Distance<Left_Distance)
{
// if((Right_Distance<=30)&&(Left_Distance<=30))
if((Right_Distance<=20)&&(Left_Distance<=20))

{_Stop();
delay(200);
_Back();
delay(1000); //1000
}
else{
// _Back();
// delay(3000);
_left();
delay(500); //500
}
}
}
else if(Right_Distance<=20) //30
{
_left();
delay(500); //500
}

else if(Left_Distance<=20) //30
{
_right();
delay(500); //500
}
else{
_Forward();
}
//delay(500);
}
