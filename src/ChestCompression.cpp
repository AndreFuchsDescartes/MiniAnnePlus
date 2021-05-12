#include <ChestCompression.h>
#include <Arduino.h>
#include <Pinout.h>
//Class for cpr measurements
Cpr::Cpr(){
    
}
//Initialises CPR object
void Cpr::init(){
    ////saving current millis to used in timestamping of cpr sensor data
    cpr_millis_old=millis();
    //Assigning input pin to Int variable
    cprInput=cprInputPin;
    
    cprCount=0;
    //filling cprValues with zeroes
    for (int i = 0; i < cpr_no_of_measurements; i++)
    {
        cprValues[i]=0;
    }
}

//Measures CPR and outputs it to serial monitor
void Cpr::logCpr(){
    cpr_millis_new = millis();
    int cpr_temp = 0;
    if (cpr_millis_new - cpr_millis_old>= cpr_timestepp)
    {
        cpr_temp = analogRead(cprInput);
        //save_cpr(cpr_temp);
        //cpr_temp = cpr_rolling_average();
        if (cpr_temp<= cpr_threshold)
         {
             save_cpr(read_cpr(cpr_temp));
         }   
         else{
              save_cpr(0);
         } 
        cpr_temp = cpr_rolling_average(); 
        if (cpr_temp <= cpr_lower_limit)
        {
            cpr_temp = 0;
        }
        
        Serial.print("cpr average: "); 
        Serial.println(cpr_temp);
        
        cpr_millis_old=cpr_millis_new;

        
    }
    else{

    }

}

//used to save sensor reading from cpr to cprValues array to calculate rolling average
void Cpr::save_cpr(int datapoint){
    if (cprCount<cpr_no_of_measurements)
    {
        cprValues[cprCount]= datapoint;
        cprCount++;
    }
    else
    {
        cprCount=0;
        cprValues[cprCount]= datapoint;
        cprCount++;
    }
}

//used to calculate rolling average of sensor readings from cpr sensor
int Cpr::cpr_rolling_average(){
    int average =0;
    for (int i = 0; i<cpr_no_of_measurements; i++)
    {
        average = average + cprValues[i];
    }
    average = average/cpr_no_of_measurements;
    return average;
}

//reads analog voltage of cpr sensor and converts it to positive capped value in specified range
int Cpr::read_cpr(int input){
    int temp = 0;
    temp = abs(input-1023)*cpr_amplification;
    if (temp <= cpr_range)
    {
        if (temp <= cpr_lower_limit)
        {
            temp = 0;
        }
    }
    else{
        temp = cpr_range;
    }
    return temp;
}