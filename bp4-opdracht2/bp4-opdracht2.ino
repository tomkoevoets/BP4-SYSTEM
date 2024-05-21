// globale waardes
//  een lijst met pinnen waarop de LEDs zijn aangesloten
const int ledPins[] = {13, 12, 11, 10, 7, 6, 3, 2};
/* Bereken het aantal LEDs door het aantal bytes van alle elementen te delen door het aantal bytes van 1 element 
 sizeof berekend dus in bytes waardoor het werkt om alle elementen te delen door 1 (op positie 0 in de array) 
 https://www.w3schools.com/cpp/cpp_arrays_size.asp
 */
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);  
 // Wacht 75 milliseconden tussen elke actie
const int delayTime = 75; 

void setup() {
  // Zet alle pinnen in de lijst ledPins in de OUTPUT stand
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);  
  }
}

void loop() {
  // Zet elke LED één voor één aan en weer uit
  for (int i = 0; i < numLeds; i++) {
    // Zet de LED aan
    digitalWrite(ledPins[i], HIGH);  
    delay(delayTime);
    // Zet de LED uit
    digitalWrite(ledPins[i], LOW);  
  }

  // Zet elke LED één voor één aan en uit in omgekeerde volgorde
  for (int i = numLeds - 1; i >= 0; i--) {
    // Zet de LED aan
    digitalWrite(ledPins[i], HIGH);  
    delay(delayTime);  
    // Zet de LED uit
    digitalWrite(ledPins[i], LOW);  
  }
}

