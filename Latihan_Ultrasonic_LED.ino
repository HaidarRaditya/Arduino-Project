

int trigPin = 11;
int echoPin = 12;
int led1 = 10;
int led2 = 9;
int led3 = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distanceCM;

  digitalWrite(trigPin, LOW); // Reset
  delayMicroseconds(2);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  distanceCM = (duration * 20.41) / 2;

  if (distanceCM >= 1 && distanceCM <= 5)  {
    Serial.println(distanceCM);
    Serial.println("CM");

    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);
    
  }
  else if (distanceCM >= 5 && distanceCM <= 10) {
    Serial.println(distanceCM);
    Serial.print("CM");

    digitalWrite(led1, LOW);
    delay(500);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);

  }
  else if (distanceCM >= 10 && distanceCM <= 15) {
    Serial.println(distanceCM);
    Serial.println("CM");

    digitalWrite(led1, LOW);
    delay(500);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);
    
  }
  else {
    Serial.println(distanceCM);
    Serial.println("CM");

    digitalWrite(led1, LOW);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);
    
  }
}
