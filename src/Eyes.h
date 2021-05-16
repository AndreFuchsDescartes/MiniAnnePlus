#ifndef Eyes_h
#define Eyes_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Pinout.h>

//the lower the value, the brighter the light
#define lightvalue_threshhold 300
#define pupilsize_normal 15
#define pupilsize_withlight 10

#define pupilsize_small 5
#define pupilsize_big 25


class Eye
{
private:
  Adafruit_SSD1306 display;
  int x_position;
  int y_position;
  int iris_outer_diameter;
  int iris_inner_diameter;
  int pupilsize;
  int i2cAdress;

  unsigned long timestamp=0;
  int pupilposition=0;

 int lightsensor_thisEye;
 int lightsensor_otherEye;

public:
  Eye(Adafruit_SSD1306 display, int adress, int lightsensor_thisEye, int lightsensor_otherEye);

  void drawIris(int irisOuter_D, int irisInner_D);

  void changePupilSize(int new_pupilsize);

  //void changePupilSize2(int new_pupilsize);

  void reactToLight(bool both_eyes_react, bool this_lightsensor_works, bool other_lightsensor_works);

  void eyeSetup();
};


#endif