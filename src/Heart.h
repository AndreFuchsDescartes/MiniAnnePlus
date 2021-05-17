#ifndef Heart_h
#define Heart_h
#include <Pinout.h>
#include <Arduino.h>
#include <Heart.h>

// #### Settings ####
//controlls how many measurements of the HandPosition
#define handPosition_no_of_measurements 2

//time in ms for each measurement
#define handPosition_timestepp 200


// #### Variables ####

//Digital values from hand position sensor in chest
bool handPosition_quality[handPosition_no_of_measurements]; 
//inflation array counter
int handPosition_count =0;
// used to save hand position rolling average
bool posAverage;

//timestamp used for timer
unsigned long handPosition_millis_new=0;
unsigned long handPosition_millis_old=0;

int pin_sensor1 = position_recognition_hand_pin1;
int pin_sensor2 = position_recognition_hand_pin2;

//compares the signals of the 2 sensors and returns true if both are HIGH
bool hand_compare_sensorsignals()
{
    bool control_result = false;
    int state_sensor1 = LOW;
    int state_sensor2 = LOW;
    state_sensor1 = digitalRead(pin_sensor1);
    state_sensor2 = digitalRead(pin_sensor2);
    if (state_sensor1 == HIGH && state_sensor2 == HIGH)
    {
        control_result = true;
    }

    return control_result;
}

// calulates the average of an array, used to smooth out the signal
int hand_rolling_average()
{
    int average = 0;
    for (int i = 0; i < handPosition_no_of_measurements; i++)
    {
        average = average + (int) handPosition_quality[i];
    }
    average = average / handPosition_no_of_measurements;
    return average;
}

//used to save sensor reading from hand position quality to handPosition_quality array to calculate rolling average
void hand_save_handPosition(bool datapoint){
    if (handPosition_count<handPosition_no_of_measurements)
    {
        handPosition_quality[handPosition_count]= datapoint;
        handPosition_count++;
    }
    else
    {
        handPosition_count=0;
        handPosition_quality[handPosition_count]= datapoint;
        handPosition_count++;
    }
    
}

//function to evaluate hand position. Sends data to RPie via USB after each read. Reads are taken according to handPosition_timestepp
void hand_log_positionQuality (){
    handPosition_millis_new = millis();
    if (handPosition_millis_new - handPosition_millis_old>= handPosition_timestepp)
    {
        
       bool result = hand_compare_sensorsignals();
       hand_save_handPosition(result);
       posAverage=hand_rolling_average();
    handPosition_millis_old=handPosition_millis_new;

        
    }
}

//init function to setup pins in void setup()
void hand_init(){
    pinMode(pin_sensor1,INPUT);
    pinMode(pin_sensor2,INPUT);

}

#endif 

