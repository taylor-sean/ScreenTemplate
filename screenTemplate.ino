/*
 Name:    ScreenTemplate.ino
 Created: 10/29/2018 5:49:45 PM
 Author:  Sean
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);



int whichScreen = 0;
int maxScreen = 3;

boolean hasChanged = true;
const int buttonPin = 4;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(buttonPin, INPUT_PULLUP);
}

void firstScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Screen 1");
}

void secondScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Screen 2");
}

void thirdScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Screen 3");
}

void loop() {
  if (hasChanged == true) {
    switch (whichScreen) {
    case 1: {
      firstScreen();
    }
        break;
    case 2: {
      secondScreen();
    }
        break;
    case 3: {
      thirdScreen();
    }
        break;
    case 0: {

    }
        break;
    }
  }
  
  int reading = digitalRead(buttonPin);
  
  if (reading != buttonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        hasChanged = true;
        whichScreen++;
      }
    }
    else {
      hasChanged = false;
    }
  }

  lastButtonState = reading;

  if (whichScreen > maxScreen) {
    whichScreen = 1;
  }
}

