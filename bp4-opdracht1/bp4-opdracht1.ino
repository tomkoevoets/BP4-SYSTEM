void setup() {
  // set up de outputs
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // zet poort 13 aan, 10 uit
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);
  // wacht 1,5 seconden
  delay(1500); 
  // zet poort 10 aan, 13 uit
  digitalWrite(13, LOW); 
  digitalWrite(10, HIGH);
  // wacht 1,5 seconden
  delay(1500); 
}
