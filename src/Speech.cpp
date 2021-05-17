#include <Arduino.h>
#include <Pinout.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <Speech.h>
Speech::Speech(){

}

void Speech::play(int track, unsigned long duration)
{
  mp3MillisNew=millis();
  //cheking if timestepp has elapsed
  if (mp3MillisNew-mp3MillisOld>mp3Timestepp)
  {
    //checking if it should be running
    if (digitalRead(mp3Player_on))
  {
    //cheking if song is over and need to be restarted
    if (millis() - timeystamp > duration || firstTimePlay||!mp3Running)
    {

        timeystamp=millis();
        //Serial.println("play");
        this->mp3Player.play(track); 
        firstTimePlay = false;
        mp3Running=true;
        
   }
  }else{
    //cheking if mp3 is running. if yes turn off
    if (mp3Running)
    {
      this->mp3Player.stop();
      mp3Running=false;
    }
    
    
  }
  mp3MillisOld=mp3MillisNew;
  }
  
  

}

void Speech::init(){
  SoftwareSerial mySoftwareSerial(mp3Player_rx, mp3Player_tx); // RX, TX
  mp3Running = false;
  mp3MillisNew= millis();
  mp3MillisOld=mp3MillisNew;

  mySoftwareSerial.begin(9600);
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

