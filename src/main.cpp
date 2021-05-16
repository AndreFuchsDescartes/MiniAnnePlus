#include <Arduino.h>
#include <ChestCompression.h>
#include <Eyes.h>
#include <Heart.h>
#include <Lungs.h>
#include <Speech.h>


//#### Eyes ####
Adafruit_SSD1306 display1(128, 64, &Wire, -1);
Eye eye_left(display1, 0x3C, lightsensor_pin_left, lightsensor_pin_right);
Adafruit_SSD1306 display2(128, 64, &Wire, -1);
Eye eye_right(display2, 0x3D, lightsensor_pin_right, lightsensor_pin_left);
Position_recognition_hand positionWatch;
Speech speaker;


//#### Lungs ####



//____________SETUP________________________________________________________
void setup() {
  Serial.begin(baudrate);
//#### Chest-Compression ####

//#### Eyes ####
 eye_left.eyeSetup();
 eye_right.eyeSetup();

//#### Heart ####
positionWatch.init();
cpr_init();
//#### Lungs ####

lungs_setup();


//#### Speech ####
speaker.init();


}


//____________LOOP________________________________________________________
void loop() {
//#### Chest-Compression ####

//#### Eyes ####
eyesReact(eye_left,eye_right);

//#### Heart ####
positionWatch.log_positionQuality();
cpr_logCpr();
//#### Lungs ####
lungs_log_inflation();

//#### Speech ####
speaker.play(1,120000);


}

