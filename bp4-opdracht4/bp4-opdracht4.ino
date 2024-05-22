// globale waardes
// A5 = analog port 5
const int potMeterPin = A5; 
const int ledPins[] = {13, 12, 11, 7, 6, 5}; 
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]); 
const int delayTime = 100; 

void setup() {
  // Zet alle pinnen in de lijst ledPins in de OUTPUT stand
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);  
  }
}

void loop() {
  // voer de led methode uit
  ledFun();
  // vertraag zodat de veranderingen beter zichtbaar zijn
  delay(delayTime);
}

// methode om de leds aan te zetten of uit
void ledFun () {
  // het lezen van in welke stand de potmeter staat
  int potVal = analogRead(potMeterPin);

  // gebruik mapping om aan de hand van de potVal het aantal aan te zetten leds te bepalen
  int ledCount = map(potVal, 0, 1023, 0, numLeds);

  // forloop die ledCount gebruikt om leds aan en uit te zetten
  for (int i = 0; i < numLeds; i++) {
    if (i < ledCount) {
      digitalWrite(ledPins[i], HIGH); 
    } else {
      digitalWrite(ledPins[i], LOW); 
    }
  } 
}
