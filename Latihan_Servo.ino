#include <Servo.h>

Servo myservo;

int pos = 0; //posisi derajat semula pada servo

void setup() 

//Sudut 30 ---> 180 Derajat
{
  myservo.attach(9); //pasang servo di pin 9

}

void loop() {
  for (pos = 30; pos <= 180; pos += 1) { //dari 30 derajat ke 180 derajat
    myservo.write(pos);                  //perintah servo untuk pindah ke variabel "pos"
    delay(10);                           //waktu yang dibutuhkan servo untuk pindah
  }
  for (pos = 180; pos >= 30; pos -= 1) { //dari 180 derajat ke 30 derajat 
    myservo.write(pos);                  //perintah servo untuk pindah ke variabel "pos"
    delay(10);                           //waktu yang dibutuhkan servountuk pindah
  }

//Sudut 50 ---> 0 Derajat

for (pos = 50; pos <= 0; pos += 1) {     //dari 50 derajat ke 0 derajat
    myservo.write(pos);                 //perintah servo untuk pindah ke variabel "pos"
    delay(10);                           //waktu yang dibutuhkan servo untuk pindah
  }
  for (pos = 0; pos >= 50; pos -= 1) {   //dari 0 derajat ke 50 derajat 
    myservo.write(pos);                  //perintah servo untuk pindah ke variabel "pos"
    delay(10);                           //waktu yang dibutuhkan servountuk pindah
  }

//Sudut 30 ---> 0 Derajat

for (pos = 30; pos <= 0; pos += 1) {     //dari 30 derajat ke 0 derajat
    myservo.write(pos);                 //perintah servo untuk pindah ke variabel "pos"
    delay(10);                           //waktu yang dibutuhkan servo untuk pindah
  }
  for (pos = 0; pos >= 30; pos -= 1) { //dari 0 derajat ke 30 derajat 
    myservo.write(pos);                  //perintah servo untuk pindah ke variabel "pos"
    delay(10);                           //waktu yang dibutuhkan servountuk pindah
  }
}
