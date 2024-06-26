// globale waardes
// knop en leds
const int buttonPin = 12;  
const int ledPin1 = 8;    
const int ledPin2 = 10;    

// aanmaken waardes om status button bij te houden via huidig, vorige en teller
int buttonState = 0;      
int lastButtonState = 0; 
int count = 0;

const int delayTime = 50; 

void setup() {
  // zet leds in output modus
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);   // zet button in input modus
}

void loop() {
  
  buttonState = digitalRead(buttonPin);  // lees de huidige status van de knop

  // als de status van de knop veranderd is ten opzichte van de laatste status
  if (buttonState != lastButtonState) {
    // als de knop is ingedrukt verhoog de teller
    if (buttonState == HIGH) {
      count++;
      ledFun();   // voer de ledFun uit
      delay(delayTime); 
    }
  }
  
  lastButtonState = buttonState;   // sla de huidige knopstatus op voor de volgende loop
}

// functie om de leds aan en uit te zetten
void ledFun() {
  /* 
  als de teller even is, zet led1 uit en led2 aan met het gebruik van modulus-oporator
  https://www.w3schools.com/cpp/cpp_operators.asp
  */
  if (count % 2 == 0) {
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
      // als de teller oneven is zet led1 aan en led2 uit
      } else {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
      }
}
