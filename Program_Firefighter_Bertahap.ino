#include <AFMotor.h>

#include <NewPing.h>

#include <Servo.h> 
Servo myservo;

int pos = 0;    
boolean fire = false;
 
#define Left_Fire 9      // left fire sensor
#define Right_Fire 10    // right fire sensor
#define Front_Fire 8     // front fire sensor
#define Water_Pump 12    // Pompa air

// Pin Sistem Pergerakan
int in1 = 4; // Dua Roda Kanan Maju
int in2 = 3; // Dua Roda Kanan Mundur
int in3 = 5; // Dua Roda Kiri Maju
int in4 = 6; // Dua Roda Kiri Mundur

int ENA = 2;
int ENB = 7;
int PWM = 150;
 
 
// Sub-Fungsi Sistem Pergerakan
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ENA, PWM);
  analogWrite(ENB, PWM);
  //Serial.println("cm\t\t");
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ENA, PWM);
  analogWrite(ENB, PWM);
  //Serial.println("cm\t\t");
}

void moveRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ENA, PWM);
  analogWrite(ENB, PWM);
 Serial.println("cm\t\t");
}

void moveLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ENA, PWM);
  analogWrite(ENB, PWM);
  Serial.println("cm\t\t");
}

void stopMoving() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  //Serial.println("cm\t\t");
}

// Pin Sensor Ultrasonik
const int Echo1 = A4; // Sensor Kiri
const int Trig1 = A5;

const int Echo2 = A2; // Sensor Tengah
const int Trig2 = A3;

const int Echo3 = A0; // Sensor Kanan
const int Trig3 = A1;

#define Echo1 A4
#define Echo2 A2
#define Echo3 A0

#define Trig1 A5
#define Trig2 A3
#define Trig3 A1

void setup() {

// Setup Sensor Ultrasonik
Serial.begin(9600);
pinMode(Echo1, INPUT);
pinMode(Trig1, OUTPUT);

pinMode(Echo2, INPUT);
pinMode(Trig2, OUTPUT);

pinMode(Echo3, INPUT);
pinMode(Trig3, OUTPUT);

// Setup Sistem Pergerakan
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);

// Setup Sensor Api
pinMode(Left_Fire, INPUT);
pinMode(Right_Fire, INPUT);
pinMode(Front_Fire, INPUT);

// Setup Pompa Air
pinMode(Water_Pump, OUTPUT);

// Setup Servo
myservo.attach(11);
myservo.write(90);

}

// Setup Fungsi Pemadaman Api
void put_off_fire() {

  delay (500);
    
  stopMoving();
    
  digitalWrite(Water_Pump, HIGH);
  delay(500);
    
  for (pos = 0; pos <= 180; pos += 1) { 
  myservo.write(pos); 
   delay(10);  
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
  myservo.write(pos); 
  delay(10);
  }
  
  digitalWrite(Water_Pump,LOW);
  myservo.write(90);
  
  fire=false;
}

void loop() {

  long duration1, duration2, duration3, distanceCM1, distanceCM2, distanceCM3;
  
  // Sensor Kiri
  digitalWrite(Trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig1, HIGH);
  delayMicroseconds(2);
  digitalWrite(Trig1, LOW);
  duration1 = pulseIn(Echo1, HIGH);

  distanceCM1 = duration1 / 29.41 / 2;

  // Sensor Tengah
  digitalWrite(Trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig2, HIGH);
  delayMicroseconds(2);
  digitalWrite(Trig2, LOW);
  duration2 = pulseIn(Echo2, HIGH);

  distanceCM2 = duration2 / 29.41 / 2;

  // Sesnor Kanan
  digitalWrite(Trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig3, HIGH);
  delayMicroseconds(2);
  digitalWrite(Trig3, LOW);
  duration3 = pulseIn(Echo3, HIGH);

  distanceCM3 = duration3 / 29.41 / 2;

// Logika Sensor dengan Sistem Pergerakan

if (distanceCM2 <= 20) {

  stopMoving();
  delay(200);

  Serial.print(distanceCM2);
  Serial.println("CM");

  if (distanceCM3 > distanceCM1) {
  
    moveRight();
    delay(500);

    Serial.print(distanceCM3);
    Serial.println("CM");

  }
  else {

    moveLeft();
    delay(500);

    Serial.print(distanceCM1);
    Serial.println("CM");

  }
}
else (distanceCM2 > 10); {
  
  moveForward();

  Serial.print(distanceCM2);
  Serial.println("CM");

  if (digitalRead(Left_Fire) ==0 && digitalRead(Right_Fire)==0 && digitalRead(Front_Fire) ==0) {

  moveForward();
                
  }
  else if (digitalRead(Front_Fire) ==1) {
   
  stopMoving();

  fire = true;

  while (fire == true) {

  put_off_fire();

  } 
  }
  else if (digitalRead(Left_Fire) ==1) {

  moveLeft();
  delay(200);

  }
  else if (digitalRead(Right_Fire) ==1) {

  moveRight();
  delay(200);

  }
  delay(300); 
}

}



