// home.h

#ifndef BUTTONDETECTION_H
#define BUTTONDETECTION_H

#include <Arduino.h>

// Declaración de variables globales que se utilizan en ButtonManager
extern const int buttonPin1;
extern const int buttonPin2;
extern const int buttonPin3;
extern const int buttonPin4;
extern String MainMenuText;
extern int ledPin1;
extern int ledPin2;
extern int ledPin3;

extern bool button1Status;
extern bool button2Status;
extern bool button3Status;
extern bool button4Status;

// Definición de la función ButtonManager
void ButtonManager() {
  int button1 = digitalRead(buttonPin1);
  int button2 = digitalRead(buttonPin2);
  int button3 = digitalRead(buttonPin3);
  int button4 = digitalRead(buttonPin4);
  Serial.print(button1);
  Serial.print(button2);
  Serial.print(button3);
  Serial.print(button4);
  
  if(button1 == LOW) {
    MainMenuText = "Using a Stimpak..";
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, HIGH);
    button1Status = true;
  } else if(button2 == LOW) {
    MainMenuText = "Loading Inventory...";
    button2Status = true;
  } else if(button3 == LOW) {
    MainMenuText = "Loading global map...";
    button3Status = true;
  } else if(button4 == LOW) {
    MainMenuText = "Searching available radios..";
    button4Status = true;
  }
}

#endif // BUTTONDETECTION_H
