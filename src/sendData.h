#ifndef sendData_h
#define sendData_h

#include <Arduino.h>
#include <Lungs.h>
#include <ChestCompression.h>
#include <Heart.h>


//defines time between data packets. has to be equal or lower than smallest timestepp of functions that have data sent this way
#define sendDataTimestep 100
//used to storre data so it can be sent in one go
String dataPacket;

//timestamps for sending data
unsigned long sendDataMilisNew;
unsigned long sendDataMilisOld;

void sendDataInit(){
    sendDataMilisOld=millis();
    sendDataMilisNew=sendDataMilisOld;
}
//used to write data to serial monitor in an orderley fashion data is preceeded by an identifier and separated by a , Example: pos1,inf50


void sendData(){
    sendDataMilisNew=millis();
    if (sendDataMilisNew-sendDataMilisOld>= sendDataTimestep)
    {/**/
        
        //Print Data for Lungs
        Serial.print(F("inf")); 
        Serial.print(inf);
        Serial.print(F(","));
        
        ///Print Data for Chest Compression
        Serial.print(F("cpr")); 
        Serial.print(cprRollingAverage);
        Serial.print(F(","));
        

        //Print Data for Hand Position
        Serial.print(F("pos")); 
        Serial.print(posAverage);
        Serial.print(F(","));

        //Print Data for Frequency
        Serial.print(F("hz")); 
        Serial.print(frequency);
        Serial.print(F(","));

        //line break
        //Serial.println(dataPacket);
        dataPacket="";
        //resetting millis

        
        Serial.println();
        sendDataMilisOld=sendDataMilisNew;
    }
    

    
}
#endif