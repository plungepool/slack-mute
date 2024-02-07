#include <Bounce.h>

const int buttonPin = 0;
const int led = 11;
Bounce pushbutton = Bounce(buttonPin, 15);  // 10 ms debounce

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      digitalWrite(led, HIGH);
      Keyboard.press(MODIFIERKEY_GUI);
      Keyboard.press(MODIFIERKEY_SHIFT);
      Keyboard.press(KEY_SPACE);
      Keyboard.release(KEY_SPACE);
      delay(300);
      Keyboard.release(MODIFIERKEY_GUI);
      Keyboard.release(MODIFIERKEY_SHIFT);
    }
    if (pushbutton.risingEdge()) {
      digitalWrite(led, LOW);
    }
  }
}
