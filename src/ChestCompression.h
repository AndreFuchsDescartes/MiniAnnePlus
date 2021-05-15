#ifndef ChestCompression_h
#define ChestCompression_h

#include <Arduino.h>
#include <Pinout.h>

// #### Settings CPR ####
//controlls how many measurements of the cpr sensor are averaged together for the rolling average
#define cpr_no_of_measurements 3

//time in ms for each measurement
#define cpr_timestepp 100

//caps cprValues at this value. Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define cpr_range 1200

//lung cpr values are multiplied with this value to amplify small readings
#define cpr_amplification 2

//values mesured below this value are concidered 0. This check is done after amplification is applied.Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define cpr_lower_limit 20

//Limit of cpr. Values above this are concidered as "NO cpr is happening". Value between 0 and 1023. 1023 is no reading 0 is max reading.
#define cpr_threshold 1023


    //Analog voltages from CPR sensor in chest
    int cprValues[cpr_no_of_measurements]; 
    //CPR array counter
    int cprCount;
    //Int variable for analog read from cpr sensor
    int cprInput;
    //Timestamp to determine elapsed time between measurements
    unsigned long cpr_millis_old;
    //Timestamp to determine elapsed time between measurements
    unsigned long cpr_millis_new;
    //used to save cpr rolling average
    int cprRollingAverage;


//Initialises CPR object
void cpr_init(){
    ////saving current millis to used in timestamping of cpr sensor data
    cpr_millis_old=millis();
    //Assigning input pin to Int variable
    cprInput=cprInputPin;
    cprRollingAverage=0;
    
    cprCount=0;
    //filling cprValues with zeroes
    for (int i = 0; i < cpr_no_of_measurements; i++)
    {
        cprValues[i]=0;
    }
}



//used to save sensor reading from cpr to cprValues array to calculate rolling average
void cpr_save(int datapoint){
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
int cpr_rolling_average(){
    int average =0;
    for (int i = 0; i<cpr_no_of_measurements; i++)
    {
        average = average + cprValues[i];
    }
    average = average/cpr_no_of_measurements;
    return average;
}

//reads analog voltage of cpr sensor and converts it to positive capped value in specified range
int cpr_read(int input){
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

//Measures CPR and outputs it to serial monitor
void cpr_logCpr(){
    cpr_millis_new = millis();
    int cpr_temp = 0;
    if (cpr_millis_new - cpr_millis_old>= cpr_timestepp)
    {
        cpr_temp = analogRead(cprInput);
        //save_cpr(cpr_temp);
        //cpr_temp = cpr_rolling_average();
        if (cpr_temp<= cpr_threshold)
         {
             cpr_save(cpr_read(cpr_temp));
         }   
         else{
              cpr_save(0);
         } 
        cpr_temp = cpr_rolling_average(); 
        if (cpr_temp <= cpr_lower_limit)
        {
            cpr_temp = 0;
        }
        
        cprRollingAverage=cpr_temp;
        Serial.print(F("cpr")); 
        Serial.println(cprRollingAverage);
        
        
        cpr_millis_old=cpr_millis_new;

        
    }
    else{

    }

}
#endif