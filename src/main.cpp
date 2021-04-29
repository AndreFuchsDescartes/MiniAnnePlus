#include <Arduino.h>
#include <ChestCompression.h>
#include <Eyes.h>
#include <Heart.h>
#include <Lungs.h>
#include <Speech.h>

Adafruit_SSD1306 display1(128, 64, &Wire, -1);
Eye eye_left(display1);

Lungs lung;

//____________SETUP________________________________________________________
void setup() {
  Serial.begin(115200);
//#### Chest-Compression ####

//#### Eyes ####
 eye_left.eyeSetup();

//#### Heart ####

//#### Lungs ####

lung.setup();


//#### Speech ####




}


//____________LOOP________________________________________________________
void loop() {
//#### Chest-Compression ####

//#### Eyes ####
eye_left.reactToLight();

//#### Heart ####

//#### Lungs ####
lung.log_ventilation();

//#### Speech ####


}

//____________DEVELOPER NOTES_____________________________________________
//!!! MP3 Player: rx and tx wires crossed