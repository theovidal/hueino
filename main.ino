#include "lib/compose.h"

int mode(0);
bool activated(false);

Pot pot(0);
Btn btn(13);
Led led(6, 5, 3);

void setup()
{
  led.setup();
  Serial.begin(9600);
  btn.setup();
}
void loop()
{
  Serial.println(digitalRead(13));
  if (btn.isPressed())
  {
    switchMode();
  }
  delay(100);
}

int ledIntensity()
{
  return (pot.get() * 255) / 1023;
}

void getMode()
{
  switch (mode)
  {
  case 0:
    led.commonAnode(false);
    led.displayColor(ledIntensity(), 0, 0);
    break;
  case 1:
    led.commonAnode(false);
    led.displayColor(0, ledIntensity(), 0);
    break;
  case 2:
    led.commonAnode(false);
    led.displayColor(0, 0, ledIntensity());
    break;
  case 3:
    led.commonAnode(true);
    led.displayColor(ledIntensity(), 0, 0);
    break;
  case 4:
    led.commonAnode(true);
    led.displayColor(0, ledIntensity(), 0);
    break;
  case 5:
    led.commonAnode(true);
    led.displayColor(0, 0, ledIntensity());
    break;
  case 6:
    led.commonAnode(false);
    led.displayColor(0, 0, 0);
    break;
  }
}

void switchMode()
{
  ++mode;
  if (mode == 7)
  {
    mode = 0;
  }
  getMode();
}
