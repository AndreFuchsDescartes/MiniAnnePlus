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
    {
        
        //Print Data for Lungs
        dataPacket+=F("inf"); 
        dataPacket+=inf;
        dataPacket+=F(",");
    
        ///Print Data for Chest Compression
        dataPacket+=F("cpr"); 
        dataPacket+=cprRollingAverage;
        dataPacket+=F(",");

        //Print Data for Hand Position
        dataPacket+=F("pos"); 
        dataPacket+=posAverage;
        dataPacket+=F(",");

        //Print Data for Frequency
        dataPacket+=F("hz"); 
        dataPacket+=frequency;
        dataPacket+=F(",");

    

        //line break
        Serial.println(dataPacket);
        dataPacket="";
        //resetting millis
        sendDataMilisOld=sendDataMilisNew;
    }
    

    
}
#endif