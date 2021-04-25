#include <Arduino.h>
#include <Eyes.h>

Adafruit_SSD1306 display1(128, 64, &Wire, -1);
Eye e(display1);

//____________SETUP________________________________________________________
void setup()
{
 e.eyeSetup();
}

//____________LOOP________________________________________________________
void loop()
{
e.reactToLight();
}

//____________DEVELOPER NOTES_____________________________________________
//