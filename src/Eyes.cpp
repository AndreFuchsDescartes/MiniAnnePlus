#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Eyes.h>

//constructor for eye-object, takes a display-object and uses it as a reference for all functions
 Eye:: Eye(Adafruit_SSD1306 display)
  {
    this->x_position = display.width() / 2;
    this->y_position = display.height() / 2;
    this->iris_outer_diameter = display.height() / 2;
    this->iris_inner_diameter = iris_outer_diameter - 5;
    this->pupilsize = 0;
    this->display = display;
  }

  void Eye::drawIris(int irisOuter_D, int irisInner_D)
  {
    for (int16_t i = irisInner_D; i < irisOuter_D; i += 1)
    {
      display.drawCircle(x_position, y_position, i, WHITE);
      display.display();
      delay(1);
    }
  }

//change pupilsize from its old size (initially 0) to the input size
 void Eye::changePupilSize(int new_pupilsize)
  {
    int t = 100;
    //compare pupilsizes to see, if it becames larger or smaller
    if (new_pupilsize > pupilsize)
    {
      //larger
      for (int16_t i = pupilsize * 0.99; i < new_pupilsize; i += 1)
      {
        display.drawCircle(x_position, y_position, i, WHITE);
        display.display();
        delay(t);
      }
    }
    else
    {
      //smaller
      for (int16_t i = pupilsize; i-- > new_pupilsize;) //reverse for-loop
      {
        display.drawCircle(x_position, y_position, i, BLACK);
        display.display();
        delay(t);
      }
    }
    pupilsize = new_pupilsize;
  }
//setup for Eye-object containing both the display.begin function, as well as display.clear, invert, and iris-drawing function
void Eye::eyeSetup()
  {
    Serial.begin(9600);
    Serial.println("begin setup");
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
      Serial.println(F("SSD1306 allocation failed"));
      for (;;)
        ; // Don't proceed, loop forever
    }
    display.clearDisplay();
    display.invertDisplay(true);
    drawIris(iris_outer_diameter, iris_inner_diameter);
  }