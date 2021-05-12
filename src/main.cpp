#include <Arduino.h>
#include <ChestCompression.h>
#include <Eyes.h>
#include <Heart.h>
#include <Lungs.h>
#include <Speech.h>


//#### Eyes ####
Adafruit_SSD1306 display1(128, 64, &Wire, -1);
Eye eye_left(display1, 0x3C);
Position_recognition_hand positionWatch;
Speech speaker;
Cpr cpr;

//#### Lungs ####
Lungs lung;


//____________SETUP________________________________________________________
void setup() {
  Serial.begin(baudrate);
//#### Chest-Compression ####

//#### Eyes ####
 eye_left.eyeSetup();

//#### Heart ####
positionWatch.init();
cpr.init();
//#### Lungs ####

lung.setup();


//#### Speech ####
speaker.init();


}


//____________LOOP________________________________________________________
void loop() {
//#### Chest-Compression ####

//#### Eyes ####
eye_left.reactToLight();

//#### Heart ####
positionWatch.log_positionQuality();
cpr.logCpr();
//#### Lungs ####
lung.log_inflation();

//#### Speech ####
//speaker.play(1,100);


}

