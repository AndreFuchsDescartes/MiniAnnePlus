#ifndef EyesReact_h
#define EyesReact_h

#include <Eyes.h>
#include <Arduino.h>

void eyes_React_init(){
    pinMode(EyeBit0, INPUT);
    pinMode(EyeBit1, INPUT);
    pinMode(EyeBit2, INPUT);

}

void eyes_React(Eye &eye1, Eye &eye2){
  Serial.println("start of eyes_React");
  //inputs from RPie
  bool bit0 = false;
  bool bit1 = false;
  bool bit2 = false;
  
  bit0=digitalRead(EyeBit0);
  bit1=digitalRead(EyeBit1);
  bit2=digitalRead(EyeBit2);
  
  
  //create case number from input
  int scenario =(int)bit0+ (int)bit1*2 + (int)bit2*4; 
  Serial.print("scn");
  Serial.println(scenario);

  //react according to scenario
  
  switch (scenario)
  {
  case 0:
    // both eyes work properly 
    eye1.reactToLight(true,true,true);
    eye2.reactToLight(true,true,true);
    break;

  case 1:
    // too small, fixed size 
    eye1.changePupilSize(pupilsize_small);
    eye2.changePupilSize(pupilsize_small);
    break;

    case 2:
    // no reaction, fixed size  
    eye1.changePupilSize(pupilsize_normal);
    eye2.changePupilSize(pupilsize_normal);
    break;

    case 3:
    // too big, fixed size 
    eye1.changePupilSize(pupilsize_big);
    eye2.changePupilSize(pupilsize_big);
    break;

    case 4:
    // uneven, fixed 
    eye1.changePupilSize(pupilsize_small);
    eye2.changePupilSize(pupilsize_normal);
    break;

    case 5:
    // only one eye reacts, both lightsensors work 
    eye1.reactToLight(true,true,true);
    eye2.changePupilSize(pupilsize_normal);
    break;

    case 6:
    // both eyes react, only one lightsensor works 
    eye1.reactToLight(true,false,true);
    eye2.reactToLight(true,true,false);
    break;
    

    default:
    break;
  }
      
  Serial.println("end of eyes_React");
  
}

#endif