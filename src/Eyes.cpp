#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Eyes.h>
 Eye:: Eye(Adafruit_SSD1306 display, int adress, int lightsensor_thisEye, int lightsensor_otherEye)
  {
    this->x_position = display.width() / 2;
    this->y_position = display.height() / 2;
    this->iris_outer_diameter = display.height() / 2;
    this->iris_inner_diameter = iris_outer_diameter - 5;
    this->pupilsize = 0;
    this->display = display;
    this->i2cAdress=adress;
    this->lightsensor_thisEye = lightsensor_thisEye;
    this->lightsensor_otherEye = lightsensor_otherEye;
  }

  void Eye::drawIris(int irisOuter_D, int irisInner_D)
  {
    Serial.println("eyes drawIris");
    for (int16_t i = irisInner_D; i < irisOuter_D; i += 1)
    {
      display.drawCircle(x_position, y_position, i, WHITE);
      display.display();
      delay(1);
    }
  }

void Eye::changePupilSize(int new_pupilsize){
  Serial.println("eyes changePupilSize");
  int time_trigger = 100;//ms
  if (new_pupilsize > pupilsize){
    //make larger
    if (millis()-timestamp > time_trigger && pupilsize < new_pupilsize){
      timestamp = millis();
      
      display.drawCircle(x_position, y_position, pupilsize, WHITE);
      display.display();this->pupilsize++;
    } 
  }else{
    //make smaller
    if (millis()-timestamp > time_trigger && pupilsize > new_pupilsize){
      timestamp = millis();
      
      display.drawCircle(x_position, y_position, pupilsize, BLACK);
      display.display();this->pupilsize--;
    }
  }   
}

void Eye::reactToLight(bool both_eyes_react, bool this_lightsensor_works, bool other_lightsensor_works){
  Serial.println("eyes reactToLight");
  int lightvalue_thisEye = 0;
  if(this_lightsensor_works){
    //read value from lightsensor
    lightvalue_thisEye = analogRead(lightsensor_thisEye);
  }else{
    lightvalue_thisEye = lightvalue_threshhold+1; // = too big to trigger if-clause
  }
  
  //read value from other lightsensor
  int lightvalue_otherEye =0;
  if(other_lightsensor_works){
    //read value from lightsensor
    lightvalue_otherEye = analogRead(lightsensor_otherEye);
  }else{
    lightvalue_otherEye = lightvalue_threshhold+1; // = too big to trigger if-clause
  }
  //if light is brighter than defined threshhold, change pupilsize
  if(lightvalue_thisEye < lightvalue_threshhold || lightvalue_otherEye < lightvalue_threshhold){
  this->changePupilSize(pupilsize_withlight);
  }else{
  this->changePupilSize(pupilsize_normal);
  }
}

void Eye::eyeSetup()
  {
    pinMode(lightsensor_thisEye,INPUT);
    //Serial.begin(9600);
    //Serial.println("begin setup");
    if (!display.begin(SSD1306_SWITCHCAPVCC, this->i2cAdress))
    {
      Serial.println(F("SSD1306 allocation failed"));
      for (;;);
         // Don't proceed, loop forever
    }
    Serial.println(F("SSD1306 setup complete"));
    display.clearDisplay();
    display.invertDisplay(true);
    drawIris(iris_outer_diameter, iris_inner_diameter);
  }