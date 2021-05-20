#include <Arduino.h>
#include <ChestCompression.h>
#include <Eyes.h>
#include <Heart.h>
#include <Lungs.h>
#include <Speech.h>
#include <EyesReact.h>
#include <sendData.h>


//#### Eyes ####
Adafruit_SSD1306 display1(128, 64, &Wire, -1);
Eye eye_left(display1, 0x3C, lightsensor_pin_left, lightsensor_pin_right);
Adafruit_SSD1306 display2(128, 64, &Wire, -1);
Eye eye_right(display2, 0x3D, lightsensor_pin_right, lightsensor_pin_left);



//#### Lungs ####



//____________SETUP________________________________________________________
void setup() {
  Serial.begin(baudrate);
  Serial.println("start of setup");
//#### Chest-Compression ####

//#### Eyes ####
 eye_left.eyeSetup();
 eye_right.eyeSetup();
 eyes_React_init();

//#### Heart ####
hand_init();
cpr_init();
//#### Lungs ####

lungs_setup();


//#### Speech ####
speechInit();

Serial.println("end of setup");

//#### Send Data ####
sendDataInit();
}


//____________LOOP________________________________________________________
void loop() {
//#### Chest-Compression ####

//#### Eyes ####
eyes_React(eye_left,eye_right);

//#### Heart ####
hand_log_positionQuality();
cpr_logCpr();
//#### Lungs ####
lungs_log_inflation();

//#### Speech ####
play(1,7000);

//#### Send Data ####
sendData();

}



