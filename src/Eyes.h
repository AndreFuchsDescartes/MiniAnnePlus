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
#define pupilsize_withlight 5

#define pupilsize_small 3
#define pupilsize_big 20


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

  void reactToLight(bool both_eyes_react, bool this_lightsensor_works);

  void eyeSetup();
};

static void eyes_React(Eye eye1, Eye eye2){
  //inputs from RPie
  bool bit0, bit1, bit2;
  bit0=digitalRead(EyeBit0);
  bit1=digitalRead(EyeBit1);
  bit2=digitalRead(EyeBit2);
  
  //create case number from input
  int scenario = bit0+ bit1*2 + bit2*4; 

  //react according to scenario
  switch (scenario)
  {
  case 0:
    /* both eyes work properly */
    eye1.reactToLight(true,true);
    eye2.reactToLight(true,true);
    break;

  case 1:
    /* too small, fixed size */
    eye1.changePupilSize(pupilsize_small);
    eye2.changePupilSize(pupilsize_small);
    break;

    case 2:
    /* no reaction, fixed size  */
    eye1.changePupilSize(pupilsize_normal);
    eye2.changePupilSize(pupilsize_normal);
    break;

    case 3:
    /* too big, fixed size */
    eye1.changePupilSize(pupilsize_big);
    eye2.changePupilSize(pupilsize_big);
    break;

    case 4:
    /* uneven, fixed */
    eye1.changePupilSize(pupilsize_small);
    eye2.changePupilSize(pupilsize_normal);
    break;

    case 5:
    /* only one eye reacts, both lightsensors work */
    eye1.reactToLight(true,true);
    eye2.changePupilSize(pupilsize_normal);
    break;

    case 6:
    /* both eyes react, only one lightsensor works */
    eye1.reactToLight(true,false);
    eye2.reactToLight(true,true);
    break;

  default:
    break;
  }
}
#endif