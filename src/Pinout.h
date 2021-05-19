#ifndef Pinout_h
#define Pinout_h

#define baudrate 115200
//#### Chest-Compression ####

//#### Eyes ####
#define lightsensor_pin_left A12
#define lightsensor_pin_right A13
//input from RPie to controll Eyes
#define EyeBit0 26
#define EyeBit1 27
#define EyeBit2 28
//#### Heart ####
#define position_recognition_hand_pin1 5
#define position_recognition_hand_pin2 6
//#### Lungs ####

//Input pin to read analog voltage from lung sensor in chest
#define lung_inflation_input_pin A8
//Input pin to read analog voltage from ventilation sensor in face
#define cprInputPin A3

//#### Speech ####
#define mp3Player_rx 10
#define mp3Player_tx 11

#define mp3Player_on 29

#endif