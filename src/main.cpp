#include <Arduino.h>
#include <ChestCompression.h>
#include <Eyes.h>
#include <Heart.h>
#include <Lungs.h>
#include <Speech.h>

Adafruit_SSD1306 display1(128, 64, &Wire, -1);
Eye eye_left(display1);
Position_recognition_hand positionWatch;
Speech speaker;

Lungs lung;

//____________SETUP________________________________________________________
void setup() {
  Serial.begin(baudrate);
//#### Chest-Compression ####

//#### Eyes ####
 eye_left.eyeSetup();

//#### Heart ####
positionWatch.init();
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
//#### Lungs ####
lung.log_ventilation();

//#### Speech ####
speaker.play(2,120000);

}

//____________DEVELOPER NOTES_____________________________________________
//!!! MP3 Player: rx and tx wires crossed