#include <AFMotor.h>

#include <NewPing.h>

  // Sistem Pergerakan
  int in1 = 4; // Maju kiri
  int in2 = 3; // Mundur kiri
  int in3 = 6; // Maju kanan
  int in4 = 5; // Mundur kanan

  int ENA = 2; 
  int ENB = 7;
  int PWM = 200;

  // Sistem Sensor Ultrasonik
  int EchoPin1 = A4; // Pin Echo Sensor Ultrasonik bagian kiri
  int TrigPin1 = A5; // Pin Trig Sensor Ultrasonik bagian kiri

  int EchoPin2 = A3; // Pin Echo Sensor Ultrasonik bagian tengah
  int TrigPin2 = A2; // Pin Trig Sensor Ultrasonik bagian tengah

  int EchoPin3 = A0; // Pin Echo Sensor Ultrasonik bagian kanan
  int TrigPin3 = A1; // Pin Trig Sensor Ultrasonik bagian kanan


void setup() {

  // Setup pin Sensor Ultrasonik
  Serial.begin(9600);
  pinMode(EchoPin1, INPUT); // Setup Sensor Ultrasonik bagian kiri 
  pinMode(TrigPin1, OUTPUT);

  pinMode(EchoPin2, INPUT); // Setup Sensor Ultrasonik bagian tengah
  pinMode(TrigPin2, OUTPUT);

  pinMode(EchoPin3, INPUT); // Setup Sensor Ultrasonik bagian kanan
  pinMode(TrigPin3, OUTPUT);

} // Penutupan Void Setup

void loop() {
  
  long duration1, duration2, duration3;
  int DistanceCM1, DistanceCM2, DistanceCM3;

  digitalWrite(TrigPin1, HIGH);
  digitalWrite(TrigPin2, HIGH);
  digitalWrite(TrigPin3, HIGH);

  delayMicroseconds(10); // Lama pelepasan gelombang sebelum Sensor Ultrasonik mati

  digitalWrite(TrigPin1, LOW);
  digitalWrite(TrigPin2, LOW);
  digitalWrite(TrigPin3, LOW);

  duration1 = pulseIn(EchoPin1, HIGH); // Echo bagian kiri nyala
  duration2 = pulseIn(EchoPin2, HIGH); // Echo bagian tengah nyala
  duration3 = pulseIn(EchoPin3, HIGH); // Echo bagian kanan nyala

  DistanceCM1 = (duration1 * 20.41) / 2; // Rumus perhitungan jarak pada echo bagian kiri
  DistanceCM2 = (duration2 * 20.41) / 2; // Rumus perhitungan jarak pada echo bagian tengah
  DistanceCM3 = (duration3 * 20.41) / 2; // Rumus perhitungan jarak pada echo bagian kanan

  if (DistanceCM2 > DistanceCM1 && DistanceCM2 > DistanceCM3 && DistanceCM1 >= 0 && DistanceCM3 >= 0) { 
  // Jika nilai jarak Sensor Ultrasonik bagian tengah > nilai jarak Sensor Ultrasonik bagian kanan = kiri >= nilai jarak yang ditentukan, maka mobil akan maju

  Serial.print("Distance CM1: ");
  Serial.print(DistanceCM1);
  Serial.print(" | Distance CM2: ");
  Serial.print(DistanceCM2);
  Serial.print(" | Distance CM3: ");
  Serial.println(DistanceCM3);
  Serial.print("CM");

  digitalWrite(in1, HIGH); // Maju kanan
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); // Maju kiri
  digitalWrite(in4, LOW);

  analogWrite(ENA, PWM);
  analogWrite(ENB, PWM);
  Serial.println("CM");
} // Penutupan 'if' pertama

else if (DistanceCM1 > DistanceCM2 && DistanceCM1 > DistanceCM3 && DistanceCM2 >= 0 && DistanceCM3 >= 0) { 
  // Jika nilai jarak yang ditentukan > nilai jarak Sensor Ultrasonik bagian kanan = bagian tengah = bagian kiri, maka mobil aka mundur

  Serial.print("CM");

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); // Mundur kanan
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); // Mundur kiri

  analogWrite(ENA, PWM);
  analogWrite(ENB, PWM);
  Serial.println("CM");
} // Penutupan 'else if' pertama

else if (DistanceCM3 > DistanceCM2 && DistanceCM3 > DistanceCM1 && DistanceCM1 >= 0 && DistanceCM2 >= 0) { 
  // Jika nilai jarak sensor Ultrasonik bagian kanan > bagian tengah = bagian kiri >= nilai jarak yang ditentukan, maka mobil akan belok kanan

  Serial.print("CM");

  digitalWrite(in1, HIGH); // Maju kanan
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); // Mundur kiri

  analogWrite(ENA, PWM);
  analogWrite(ENB, PWM);
  Serial.println("CM");
} // Penutupan 'else if' kedua

else if (DistanceCM1 > DistanceCM3 && DistanceCM1 > DistanceCM2 && DistanceCM2 >= 0 && DistanceCM3 >= 0) {
  // Jika nilai jarak Sensor Ultrasonic bagian kiri lebih > bagian kanan = bagian tengah >= nlai jarak yang ditentukan, maka mobil akan belok kiri

  Serial.print("CM");

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); // Maju kiri
  digitalWrite(in3, HIGH); // Mundur kanan
  digitalWrite(in4, LOW);
} // Penutupan 'else if' ketiga

else if (DistanceCM1 <= 0 || DistanceCM2 <= 0 || DistanceCM3 <= 0) {
  // Jika nilai jarak yang ditentukan < 0, maka mobil akan berhenti

  Serial.print("CM");

  digitalWrite(in1, LOW); // Mobil berhenti
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
} // Penutupan 'else' ini sebagai penutupan 'if' pertama

} // Penutupan Void Loop

