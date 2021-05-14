#include <Pinout.h>
#include <Arduino.h>
#include <Heart.h>

Position_recognition_hand::Position_recognition_hand()
{
}
//compares the signals of the 2 sensors and returns true if both are HIGH
bool Position_recognition_hand::compare_sensorsignals()
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
int Position_recognition_hand::hand_rolling_average()
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
void Position_recognition_hand::save_handPosition(bool datapoint){
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
void Position_recognition_hand::log_positionQuality (){
    handPosition_millis_new = millis();
    if (handPosition_millis_new - handPosition_millis_old>= handPosition_timestepp)
    {
        
       bool result = compare_sensorsignals();
       save_handPosition(result);
      
        Serial.print(F("Position average: "));   
        Serial.println(hand_rolling_average());
       
        handPosition_millis_old=handPosition_millis_new;

        
    }
}

//init function to setup pins in void setup()
void Position_recognition_hand::init(){
    pinMode(pin_sensor1,INPUT);
    pinMode(pin_sensor2,INPUT);

}

