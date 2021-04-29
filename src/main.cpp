#include <Arduino.h>
#include <ChestCompression.h>
#include <Eyes.h>
#include <Heart.h>
#include <Lungs.h>
#include <Speech.h>


//____________SETUP________________________________________________________
void setup() {
  Serial.begin(9600);
//#### Chest-Compression ####

//#### Eyes ####

//#### Heart ####

//#### Lungs ####

lungs_setup();


//#### Speech ####




}


//____________LOOP________________________________________________________
void loop() {
//#### Chest-Compression ####

//#### Eyes ####

//#### Heart ####

//#### Lungs ####
measure_ventilation();

//#### Speech ####


}

//____________DEVELOPER NOTES_____________________________________________
//