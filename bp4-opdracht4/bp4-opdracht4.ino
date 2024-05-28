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
  
  ledFun();  // voer de led methode uit
  delay(delayTime);  // vertraag zodat de veranderingen beter zichtbaar zijn
}

// methode om de leds aan te zetten of uit
void ledFun() {
  /*
    Zet de leds aan of uit afhankelijk van de stand van de potmeter
    - Lees de waarde van de potmeter
    - Gebruik mapping om de waarde van de potmeter om te zetten naar het aantal aan te zetten leds
    - Zet de leds aan of uit met behulp van een for-loop
  */
  int potVal = analogRead(potMeterPin);
  int ledCount = map(potVal, 0, 1023, 0, numLeds);

  for (int i = 0; i < numLeds; i++) {
    if (i < ledCount) {
      digitalWrite(ledPins[i], HIGH); 
    } else {
      digitalWrite(ledPins[i], LOW); 
    }
  } 
}

