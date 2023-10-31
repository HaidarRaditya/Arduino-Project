 int led1 = 16;// Variable led1 untuk pin 10
 int led2 = 17;// Variable led2 untuk pin 11
 int led3 = 18;// Variable led3 untuk pin 12
               // Variable led4 untuk pin 13




void setup() {
  // put your setup code here, to run once:
  pinMode (led1, OUTPUT); // Inisiasi pin led1
  pinMode (led2, OUTPUT); // Inisiasi pin led2
  pinMode (led3, OUTPUT); // Inisiasi pin led3
                          // Inisiasi pin led4
  

}

void loop() {

  //LED nyala 1, 2, 3, dan 4 (ESP32 : Pin 16, 17, 18)

  digitalWrite(led3, HIGH); 

  delay(500);

  digitalWrite(led3, LOW);

  delay(500);

  digitalWrite(led2, HIGH);

  delay(500);

  digitalWrite(led2, LOW);

  delay(500);

  digitalWrite(led1, HIGH);

  delay(500);

  digitalWrite(led1, LOW);

  //LED nyala dari pin 4, 3, 2, dan 1 (ESP32 : Pin 18, 17, dan 16)

  digitalWrite(led1, HIGH); 

  delay(500);

  digitalWrite(led1, LOW);

  delay(500);

  digitalWrite(led2, HIGH);

  delay(500);

  digitalWrite(led2, LOW);

  delay(500);

  digitalWrite(led3, HIGH);

  delay(500);

  digitalWrite(led3, LOW);

}

// Challange
// Buatlah led menyala dari urutan 1,2,3 dan 4 lalu menyala dari 4,3,2, dan 1
