#include <avr/sleep.h>

void pressFWD() 
{
  // NEXT is 3650 Ohm on PA1
  pinConfigure(PIN_PA1, PIN_DIR_OUTPUT, PIN_OUT_HIGH);
  delay(50);
  pinConfigure(PIN_PA1, PIN_DIR_INPUT);
  delay(50); 
}

void pressBCK() {
  // BACK is 1000 Ohm on PA3
  pinConfigure(PIN_PA3, PIN_DIR_OUTPUT, PIN_OUT_HIGH);
  delay(50);
  pinConfigure(PIN_PA3, PIN_DIR_INPUT);
  delay(50); 
}

void pressPAUSE() {
  // PAUSE is 5150 Ohm on PA2
  pinConfigure(PIN_PA2, PIN_DIR_OUTPUT, PIN_OUT_HIGH);
  delay(50);
  pinConfigure(PIN_PA2, PIN_DIR_INPUT);
  delay(50);  
}

void setup() {
  pinConfigure(PIN_PA1, PIN_DIR_INPUT);
  pinConfigure(PIN_PA2, PIN_DIR_INPUT);
  pinConfigure(PIN_PA3, PIN_DIR_INPUT);
}

void loop() {
  // enter the Konami code :)
  delay(100);
  pressFWD();
  pressFWD();
  pressBCK();
  pressBCK();
  pressFWD();
  pressBCK();
  pressFWD();
  pressBCK();
  pressPAUSE();
  pressPAUSE();
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable(); // we are not waking up from this
  sleep_cpu();
}
