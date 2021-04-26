#include <Arduino.h>
#include <Eyes.h>

Adafruit_SSD1306 display1(128, 64, &Wire, -1);
Eye eye_left(display1);

//____________SETUP________________________________________________________
void setup()
{
 eye_left.eyeSetup();
}

//____________LOOP________________________________________________________
void loop()
{
eye_left.reactToLight();
}

//____________DEVELOPER NOTES_____________________________________________
//