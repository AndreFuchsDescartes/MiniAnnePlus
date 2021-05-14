#ifndef Heart_h
#define Heart_h
#include <Pinout.h>
#include <Arduino.h>

// #### Settings ####
//controlls how many measurements of the HandPosition
#define handPosition_no_of_measurements 2

//time in ms for each measurement
#define handPosition_timestepp 200


class Position_recognition_hand
{
private:

// #### Variables ####

//Digital values from hand position sensor in chest
bool handPosition_quality[handPosition_no_of_measurements]; 
//inflation array counter
int handPosition_count =0;

//timestamp used for timer
unsigned long handPosition_millis_new=0;
unsigned long handPosition_millis_old=0;

int pin_sensor1 = position_recognition_hand_pin1;
int pin_sensor2 = position_recognition_hand_pin2;

public:
//Object-Constructor
Position_recognition_hand();

// Querying the touchsensors to see if both are active, return true if both touchsensors are high
bool compare_sensorsignals();

// calulates the average of an array, used to smooth out the signal
int hand_rolling_average();

//used to save sensor reading from hand position quality to handPosition_quality array to calculate rolling average
void save_handPosition(bool datapoint);

//function to evaluate hand position. Sends data to RPie via USB after each read. Reads are taken according to handPosition_timestepp
void log_positionQuality();

//init function to setup pins in void setup()
void init();

};

#endif 

