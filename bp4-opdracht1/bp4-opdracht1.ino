void setup() {
  // set up de outputs
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // zet poort 13 aan, 10 uit
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);
  
  delay(1500);   // wacht 1,5 seconden
  
  // zet poort 10 aan, 13 uit
  digitalWrite(13, LOW); 
  digitalWrite(10, HIGH);
  
  delay(1500);   // wacht 1,5 seconden
}
