void setup() {
  // set up the outputs
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // turn on port 13, off port 10
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);
  // wait 1,5 seconds
  delay(1500); 
  // turn on port 10, off 13
  digitalWrite(13, LOW); 
  digitalWrite(10, HIGH);
  // wait 1,5 seconds
  delay(1500); 
}
