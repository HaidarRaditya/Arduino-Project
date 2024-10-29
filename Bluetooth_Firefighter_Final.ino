#include <SoftwareSerial.h>
#include <Wire.h>

// Sistem Pergerakan Bluetooth
SoftwareSerial modul_bt(0,1); // harus menyilang, TX modul ke RX(0) arduinno
                              // RX modul ke TX(1) arduino
                              // Saat upload, cabut dulu kabel RX dan TX. kalau sudah selesai upload baru colokkan lagi
#include <L298N.h>
const int ENA = 6; // motor A (kiri)
const int IN1 = 4;
const int IN2 = 7;
const int IN3 = 5;
const int IN4 = 2;
const int ENB = 3;  // motor B (kanan)
L298N driver(ENA,IN1,IN2,IN3,IN4,ENB); 
int time_delay = 500;
int speed = 125;
char val;

boolean light = false;
boolean fire = false;

// #include <AFMotor.h>

// #include <NewPing.h>

#include <Servo.h> 
Servo myservo;

int pos = 0;    
 
#define Front_Fire 8     // front fire sensor
#define Water_Pump 12    // Pompa air

// Pin LED (perspektif depan)
int led1 = 9; // Hijau kanan dan kiri
int led2 = 10; // Merah kanan dan kiri

void setup() {

// Setup Bluetooth
modul_bt.begin(9600);
Serial.begin(9600);

// Setup LED
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);

// Setup Sensor Api
pinMode(Front_Fire, INPUT);

// Setup Pompa Air
pinMode(Water_Pump, OUTPUT);

// Setup Servo
myservo.attach(11);
myservo.write(90);

}

// Setup Fungsi Pemadaman Api
void put_off_fire() {

   
  // stopMoving();
    
  digitalWrite(Water_Pump, HIGH);
  delay(500);
  myservo.attach(11);
  
  for (pos = 0; pos <= 180; pos += 1) { 
  myservo.write(pos); 
   delay(10);  
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
  myservo.write(pos); 
  delay(10);
  }
  
  delay(500);
} 

void lampu() {

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(500); 
}

void lampuoff() {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW); 
}

void drive(int motor,int state1,int state2) {
  driver.setup_motor(motor,state1,state2);
  driver.drive_motor(motor,speed); 
}

void loop() {

  if (light) {lampu();}
  if (!light) {lampuoff();}

  if (fire) {put_off_fire();}
  if (!fire) {
     digitalWrite(Water_Pump, LOW);
     myservo.write(180);
     myservo.detach();
  }


  if (Serial.available() > 0) {
    val = Serial.read();

  if (val=='S') // stop
  {
  drive(L298N::MOTOR_A,LOW,LOW); // stop 
  drive(L298N::MOTOR_B,LOW,LOW);
  }
  if (val=='F')  
  {
  drive(L298N::MOTOR_A,HIGH,LOW); // maju 
  drive(L298N::MOTOR_B,HIGH,LOW);
  }
  if (val=='B') 
  { 
  drive(L298N::MOTOR_A,LOW,HIGH); // mundur
  drive(L298N::MOTOR_B,LOW,HIGH);
  }
  if (val=='L') 
  {
  drive(L298N::MOTOR_A,HIGH,LOW); // kiri
  drive(L298N::MOTOR_B,LOW,HIGH);
  }
  if (val=='R')  
  {
  drive(L298N::MOTOR_A,LOW,HIGH); // kanan
  drive(L298N::MOTOR_B,HIGH,LOW);
  }
if (val == 'T') {

   light = true;
  
}
if (val == 'G') {

  light = false;

}
  if (val=='W')
  {
    fire = true;

    //digitalWrite(Water_Pump, HIGH);
    
    //while (Water_Pump, HIGH) {
    //for (pos = 0; pos <= 180; pos += 1) { 
      //myservo.write(pos); 
      //delay(10);  
    //}
    //for (pos = 180; pos >= 0; pos -= 1) { 
      //myservo.write(pos); 
      //delay(10);
    //}
    
    //}
  }
  }
  if (val=='M')
  {
    fire = false;

    //digitalWrite(Water_Pump, LOW);
    //myservo.write(180);
    //myservo.detach();
  }
}