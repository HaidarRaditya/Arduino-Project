int led1 = 10; // Variable led1 untuk pin 10
int led2 = 9;  // Variable led2 untuk pin 9
int led3 = 8;  // Variable led3 untuk pin 8
int led4 = 7;  // Variable led4 untuk pin 7


void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT); // Inisiasi pin led1
  pinMode(led2, OUTPUT); // Inisiasi pin led2
  pinMode(led3, OUTPUT); // Inisiasi pin led3
  pinMode(led4, OUTPUT); // Inisiasi pin led4
}

void loop() {
  // put your main code here, to run repeatedly:

  // Urutan LED nyala-mati dari 1 hingga 4

  digitalWrite(led1, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led1, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati

  digitalWrite(led2, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led2, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati

  digitalWrite(led3, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led3, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati

  digitalWrite(led4, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led4, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati

  // Urutan LED nyala-mati dari 4 hingga 1

  digitalWrite(led4, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led4, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati

  digitalWrite(led3, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led3, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati

  digitalWrite(led2, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led2, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati

  digitalWrite(led1, HIGH); // Nyalakan LED
  delay(500);               // Berapa lama LED akan menyala
  digitalWrite(led1, LOW);  // Matikan LED
  delay(500);               //Berapa lama LED akan mati
}
