#ifndef Speech_h
#define Speech_h

#include <Arduino.h>
#include <Pinout.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#define speach_volume 23
#define mp3Timestepp 500



bool mp3Running;
unsigned long mp3MillisOld;
unsigned long mp3MillisNew;
unsigned long timeStamp;
//SoftwareSerial myoftwareSerial(mp3Player_rx, mp3Player_tx); // RX, TX  


DFRobotDFPlayerMini mp3Player;

void play(int track, unsigned long duration)
{
  mp3MillisNew=millis();
  
  //cheking if timestepp has elapsed
  if (mp3MillisNew-mp3MillisOld>mp3Timestepp)
  {
      //should mp3 be running ?
      if (digitalRead(mp3Player_on))
      {
        //cheking if song has ended
        if (mp3MillisNew-timeStamp>duration||!mp3Running)
        {
            mp3Player.play(1);
            Serial.println("started mp3 ");
            mp3Running=true;
            timeStamp=millis();
                
            
        }
      }else{
            //cheking if mp3 is running. if yes turn off
            if (mp3Running)
            {
                Serial.println("stop ");
                mp3Player.stop();
                mp3Running=false;
            }
        }
    mp3MillisOld=mp3MillisNew;
  }
   
}


void speechInit(){
  SoftwareSerial mySoftwareSerial(mp3Player_rx, mp3Player_tx); // RX, TX
  mySoftwareSerial.begin(9600);
  mp3Running = false;
  mp3MillisNew= millis();
  mp3MillisOld=mp3MillisNew;
  timeStamp=millis();
  
  pinMode(mp3Player_on,INPUT);

  
 // Serial.begin(9600);


  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!mp3Player.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  mp3Player.volume(23);  //Set volume value. From 0 to 30
  //mp3Player.play(1);  //Play the first mp3
}


#endif