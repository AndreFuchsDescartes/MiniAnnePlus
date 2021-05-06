#ifndef Speech_h
#define Speech_h
#include <Arduino.h>
#include <Pinout.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>


#define speach_volume 23

//audiotrack list
#define track_rickroll 1

class Speech{
    private:
    DFRobotDFPlayerMini mp3Player;
    //SoftwareSerial myoftwareSerial(mp3Player_rx, mp3Player_tx); // RX, TX  
    

    int timestamp = 0;

    public:
    int track;
    Speech();
    void play(int track, int duration);
    void init();
};
#endif