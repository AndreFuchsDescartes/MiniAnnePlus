#ifndef Heart_h
#define Heart_h
#include <Pinout.h>
#include <Arduino.h>

// #### Settings ####
//controlls how many measurements of the HandPosition
#define handPosition_no_of_measurements 3


class Position_recognition_hand
{
private:

// #### Variables ####

//Digital values from hand position sensor in chest
bool handPosition_quality[handPosition_no_of_measurements]; 
//inflation array counter
int handPosition_count =0;

int pin_sensor1 = position_recognition_hand_pin1;
int pin_sensor2 = position_recognition_hand_pin2;

public:
Position_recognition_hand();
// Querying the touchsensors to see if both are active, return true if both touchsensors are high
bool compare_sensorsignals();
int rolling_average();
void save_handPosition(bool datapoint);

};
#endif 