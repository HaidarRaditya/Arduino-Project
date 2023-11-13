int IR1 = 7; // Sambungkan IR1 ke pin D7
int IR2 = 8; // Sambungkan IR2 infrared ke pin D8

int LED1 = 13; // Samsungkan LED1 ke pin 13
int LED2 = 12; // Sambungkan LED2 ke pin 12




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  
  pinMode(IR1, INPUT); // IR1 pin INPUT
  pinMode(IR2, INPUT); // IR2 pin INPUT


  pinMode(LED1, OUTPUT); // LED1 pin Output
  pinMode(LED2, OUTPUT); // LED2 pin Output


}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorStatus1 = digitalRead(IR1); // Variable sensorStatus1 untuk membaca infrared 1
  int sensorStatus2 = digitalRead(IR2); // Variable sensorStatus1 untuk membaca infrared 1
                                        
 
  if (sensorStatus1 == 1 ) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led
    digitalWrite(LED1, LOW); // LED1 Mati
    digitalWrite(LED2, LOW); // LED2 Mati
    
    Serial.println("Motion Detected!"); // print Motion Detected! on the serial monitor window
  }
  else  {
    //else turn on the onboard LED
    digitalWrite(LED1, HIGH); // LED1 Menyala
    digitalWrite(LED2, HIGH); // LED2 Menyala
    
    Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
  }
}

