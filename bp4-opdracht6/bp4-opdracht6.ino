#include <Adafruit_LiquidCrystal.h>

// Globale waardes
// Pins voor de knoppen
const int buttonPin1 = 12;
const int buttonPin2 = 8;

// Variabelen om knopstatus bij te houden
int buttonState1 = 0;
int lastButtonState1 = 0;
int buttonState2 = 0;
int lastButtonState2 = 0;
bool button1Pressed = false;
bool button2Pressed = false;
bool pausedDisplayed = false;

// Variabelen voor stopwatch
unsigned long elapsedTime = 0;
unsigned long lapStartTime = 0;
bool running = false;
bool paused = false;

// LCD-initialisatie
Adafruit_LiquidCrystal lcd(0x20); // lcd adres

void setup() {
  // Initialiseer de LCD
  lcd.begin(16, 2);           // Geef het aantal kolommen en rijen van je LCD-scherm op
  lcd.setBacklight(LOW);      // Zet de achtergrondverlichting aan
  lcd.clear();                // Wis het scherm

  // Initialiseer de knoppen
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  // Zet de starttekst op de LCD
  lcd.setCursor(0, 0);             // 1e cijfer is horizontaal, 2e cijfer is verticaal
  lcd.print("Druk op knop 1");     
}

void loop() {
  // Lees de huidige status van de knoppen
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // Check knop 1
  checkButton1Fun();

  // Check knop 2
  checkButton2Fun();

  // Controleer of beide knoppen tegelijk zijn ingedrukt
  checkResetButtonFun();

  // Bewaar de huidige knopstatus voor de volgende iteratie
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;

  // Als de stopwatch loopt, update de tijd elke seconde
  if (running && !paused && !lapTimeDisplayedFun()) {
    delay(1000);        // Wacht 1 seconde
    elapsedTime++;      // Verhoog de verstreken tijd met 1 seconde
    updateDisplayFun();
  }
}

// knop 1 methode
void checkButton1Fun() {
  /*
    Controleer of knop 1 is ingedrukt en voer de juiste acties uit
    - Als knop 1 kort wordt ingedrukt, start de stopwatch
    - Als knop 1 wordt ingedrukt en vastgehouden, toon de laptime
  */
  if (buttonState1 == HIGH && lastButtonState1 == LOW) {
    button1Pressed = true;
    lapStartTime = millis();
  } else if (buttonState1 == LOW && lastButtonState1 == HIGH) {
    if (!running && !paused) {
      startStopwatchFun();
    } else if (paused && !running) {
      resumeStopwatchFun();
    }
    button1Pressed = false;
  } else if (buttonState1 == HIGH && (millis() - lapStartTime >= 2000)) {
    // Als knop 1 wordt ingedrukt en vastgehouden voor 2 seconden, toon laptijd
    showLapTimeFun();
  }
}

// knop 2 methode
void checkButton2Fun() {
  /*
    Controleer of knop 2 is ingedrukt en voer de juiste acties uit
    - Als knop 2 wordt ingedrukt, pauzeer de stopwatch
  */
  if (buttonState2 == HIGH && lastButtonState2 == LOW) {
    button2Pressed = true;
    delay(50);              // Debounce
  } else if (buttonState2 == LOW && lastButtonState2 == HIGH) {
    if (running && !paused) {
      pauseStopwatchFun();
    }
    button2Pressed = false;
  }
}

// 2 knop methode
void checkResetButtonFun() {
  /*
    Controleer of beide knoppen tegelijk zijn ingedrukt voor een resetactie
  */
  if (button1Pressed && button2Pressed) {
    resetStopwatchFun();
  }
}

// methode om stopwatch te starten
void startStopwatchFun() {
  /*
    Start de stopwatch, reset de weergave en update de LCD-display met de verstreken tijd
  */
  running = true;
  paused = false;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Tijd: ");
  pausedDisplayed = false;
}

// methode om stopwatch weer door te laten gaan
void resumeStopwatchFun() {
  /*
    Hervat de stopwatch vanuit de gepauzeerde toestand en update de LCD-display met de verstreken tijd
  */
  running = true;
  paused = false;
  pausedDisplayed = false;
}

// methode om stopwatch te pauzeren
void pauseStopwatchFun() {
  /*
    Pauzeer de stopwatch en toon een pauzemelding op de LCD-display
  */
  running = false;
  paused = true;
  if (!pausedDisplayed) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gepauzeerd");
    pausedDisplayed = true;
  }
}

// methode om stopwatch te resetten
void resetStopwatchFun() {
  /*
    Reset de stopwatch, wis de display en toon een resetmelding op de LCD-display
  */
  elapsedTime = 0;
  running = false;
  paused = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gereset");
}

// methode om de display te updaten
void updateDisplayFun() {
  /*
    Werk de LCD-display bij met de verstreken tijd van de stopwatch
  */
  lcd.setCursor (0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("Tijd: ");
  lcd.print(elapsedTime);
  lcd.print("s   ");
}

// methode om de laptime tijd te checken
bool lapTimeDisplayedFun() {
  /*
    Controleer of de laptime nog wordt weergegeven op basis van de tijd
  */
  return (millis() - lapStartTime < 2000); // Controleren of de laptime-weergave nog niet voorbij is
}

// methode om de laptime te weergeven
void showLapTimeFun() {
  /*
    Toon de laptime op de LCD-display, wacht even en update de display daarna met de verstreken tijd
  */
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Lap: ");
  lcd.print(elapsedTime);
  lcd.print("s");
  delay(2000);
}


