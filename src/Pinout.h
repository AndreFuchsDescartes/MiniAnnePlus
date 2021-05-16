#ifndef Pinout_h
#define Pinout_h

#define baudrate 115200
//#### Chest-Compression ####

//#### Eyes ####
#define lightsensor_pin_left A2
#define lightsensor_pin_right A3
//input from RPie to controll Eyes
#define EyeBit0 2
#define EyeBit1 3
#define EyeBit2 4
//#### Heart ####
#define position_recognition_hand_pin1 7
#define position_recognition_hand_pin2 8
//#### Lungs ####

//Input pin to read analog voltage from lung sensor in chest
#define lung_inflation_input_pin A1
//Input pin to read analog voltage from ventilation sensor in face
#define ventilation_input_pin A0
//Input pin to read analog voltage from cpr sensor
#define cprInputPin A6

//#### Speech ####
#define mp3Player_rx 10
#define mp3Player_tx 11  

#endif