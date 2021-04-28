#ifndef Eyes_h
#define Eyes_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Pinout.h>

class Eye
{
private:
  Adafruit_SSD1306 display;
  int x_position;
  int y_position;
  int iris_outer_diameter;
  int iris_inner_diameter;
  int pupilsize;

  

 int lightsensor_left = lightsensor_pin_left;
 
  //the lower the value, the brighter the light
  int lightvalue_threshhold=300;
  int pupilsize_withlight = 5;
  int pupilsize_nolight = 15;

public:
  Eye(Adafruit_SSD1306 display);

  void drawIris(int irisOuter_D, int irisInner_D);

  void changePupilSize(int new_pupilsize);

  void reactToLight();

  void eyeSetup();
};

#endif