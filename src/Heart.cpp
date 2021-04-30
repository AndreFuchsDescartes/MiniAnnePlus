#include <Pinout.h>
#include <Arduino.h>
#include <Heart.h>

Position_recognition_hand::Position_recognition_hand()
{
}

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

int Position_recognition_hand::rolling_average()
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

//function to measure ventilation. Sends data to RPie via USB after each read. Reads are taken according to lung_timestepp
void Position_recognition_hand::log_ventilation (){
    lung_millis_new = millis();
    if (lung_millis_new - lung_millis_old>= lung_timestepp)
    {
        
       bool result = compare_sensorsignals();
       save_handPosition(result);
      
        Serial.print("inflation average: ");   
        Serial.println(rolling_average());
       
        lung_millis_old=lung_millis_new;

        
    }
    else{

    }
}