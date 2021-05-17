#ifndef Lungs_h
#define Lungs_h

#include <Arduino.h>
#include <Pinout.h>
#include <ChestCompression.h>


// #### Settings ####

//controlls timestepp between measurements of lung inflation in millisecconds
#define lung_timestepp 100
//controlls how many measurements of the lung are averaged to gether to smooth out signal. The time between measurements is set with lung_timestepp
#define lung_no_of_measurements 3
//caps lung_inflation at this value. Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define inflation_range 500
//lung inflation values are multiplied with this value to amplify small readings
#define inflation_amplification 3
//values mesured below this value are concidered 0. This check is done after amplification is applied.Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define inflation_lower_limit 30

// #### Variables ####

//Analog voltages from lung sensor in chest
int lung_inflation[lung_no_of_measurements]; 
//inflation array counter
int inflation_count =0;
//Indicates wheter lungs are inflated properley based on lung_inflation_threshold
bool lung_inflation_is_good; 
//Timestamp to determine elapsed time between measurements
unsigned long lung_millis_old;
//Timestamp to determine elapsed time between measurements
unsigned long lung_millis_new;
//Int variable for analog read from lung inflation sensor
int lung_inflation_input;
//used to store inflation value
int inf;
    
    



//lungs setup function
void lungs_setup()
{
    //assigning analog input pin to corresponding integer for inflation analog read
    lung_inflation_input = lung_inflation_input_pin;
    //saving current millis to use in timestamping of lung sensor data
    lung_millis_old = millis();
    //filling lung_inflation with zeroes
    for (int i = 0; i < lung_no_of_measurements; i++)
    {
        lung_inflation[i]=0;
    }
     

}

//reads analog voltage of lung sensor and converts it to positive capped value in specified range
int lungs_read_inflation(){
    int temp = 0;
    temp = abs(analogRead(lung_inflation_input)-1023)*inflation_amplification;
    if (temp <= inflation_range)
    {
        if (temp <= inflation_lower_limit)
        {
            temp = 0;
        }
    }
    else{
        temp = inflation_range;
    }
    return temp;
}

//used to save sensor reading from lungs to lung_inflation array to calculate rolling average
void lungs_save_inflation(int datapoint){
    if (inflation_count<lung_no_of_measurements)
    {
        lung_inflation[inflation_count]= datapoint;
        inflation_count++;
    }
    else
    {
        inflation_count=0;
        lung_inflation[inflation_count]= datapoint;
        inflation_count++;
    }
    
}

//used to calculate rolling average of sesnor readings from lungs
int lungs_inflation_rolling_average(){
    int average =0;
    for (int i = 0; i < lung_no_of_measurements; i++)
    {
        average = average + lung_inflation[i];
    }
    average = average/lung_no_of_measurements;
    return average;
}

//function to measure ventilation. Sends data to RPie via USB after each read. Reads are taken according to lung_timestepp
void lungs_log_inflation (){
    lung_millis_new = millis();
    int inflation_temp = 0;
    int cpr_temp = 0;
    if (lung_millis_new - lung_millis_old>= lung_timestepp)
    {
        cpr_temp=cprRollingAverage;
            if (cpr_temp==0 )
            {
                lungs_save_inflation(lungs_read_inflation());
            }   
            else{
                lungs_save_inflation(0);
            } 
        inflation_temp = lungs_inflation_rolling_average(); 
        if (inflation_temp <= inflation_lower_limit || cpr_temp > inflation_range)
        {
            inflation_temp = 0;
        }
        inf=inflation_temp;
        lung_millis_old=lung_millis_new;

        
    }
    else{

    }
}


#endif