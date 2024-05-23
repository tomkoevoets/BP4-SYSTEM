#include <Servo.h>

Servo myServo;  // Definieer een Servo object

// Globale waardes
const int buttonPin1 = 12;  // Eerste drukknop
const int buttonPin2 = 4;  // Tweede drukknop
const int servoEngine = 2;  // ServoMotor
const int dbDelay = 100;

void setup() {
  myServo.attach(servoEngine);  // Sluit de servomotor aan op servo_pin
  myServo.write(0);  // Stel beginpositie van de servomotor in
  
  pinMode(buttonPin1, INPUT);  
  pinMode(buttonPin2, INPUT);  
}

// Methode om de motor te laten bewegen
void moveServo(int startPos, int endPos, int duration, int pauseDuration = 0) {
  int stepSmoothing = duration / abs(endPos - startPos); // vertraging (in milliseconden) tussen opeenvolgende stappen van de servomotor
  
  // Beweeg van startPos naar endPos
  for (int pos = startPos; pos <= endPos; pos++) {
    myServo.write(pos);
    delay(stepSmoothing);
  }

  // Pauzeer op endPos
  if (pauseDuration > 0) {
    delay(pauseDuration);
  }

  // Beweeg terug van endPos naar startPos
  for (int pos = endPos; pos >= startPos; pos--) {
    myServo.write(pos);
    delay(stepSmoothing);
  }
}

void loop() {
  bool button1State = digitalRead(buttonPin1);
  delay(dbDelay); // Delay zodat het tegerlijk indrukken van de knoppen tijd heeft om te registreren
  bool button2State = digitalRead(buttonPin2);

  if (button1State && button2State) {
    // Beide knoppen ingedrukt
    moveServo(0, 120, 5000, 2000);
    delay(500);  
  } else if (button1State) {
    // Knop 1 ingedrukt
    moveServo(0, 120, 5000);
  } else if (button2State) {
    // Knop 2 ingedrukt
    moveServo(0, 120, 500);
  }
}


