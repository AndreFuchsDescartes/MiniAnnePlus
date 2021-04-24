#ifndef Eyes_h
#define Eyes_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Eye
{
private:
  Adafruit_SSD1306 display;
  int x_position;
  int y_position;
  int iris_outer_diameter;
  int iris_inner_diameter;
  int pupilsize;

public:
  Eye(Adafruit_SSD1306 display);

  void drawIris(int irisOuter_D, int irisInner_D);

  void changePupilSize(int new_pupilsize);

  void eyeSetup();
};

#endif