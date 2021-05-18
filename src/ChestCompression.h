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
#define cpr_range 1000

//lung cpr values are multiplied with this value to amplify small readings
#define cpr_amplification 2

//values mesured below this value are concidered 0. This check is done after amplification is applied.Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define cpr_lower_limit 20

//Limit of cpr. Values above this are concidered as "NO cpr is happening". Value between 0 and 1023. 1023 is no reading 0 is max reading.
#define cpr_threshold 1023

//time in ms that gets captured in frequencyArray[], used to calculate size of frequencyArray[]
#define frequencyArray_time 2500


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

    //### frequency measurement ###

    //frequency of pushes during cpr
    double frequency = 0;

    //Size for frequency measurement
    const int frequencyArraySize = frequencyArray_time/cpr_timestepp+1;
    //array for frequency measurement
    int frequencyArray [frequencyArraySize];
    //current position in the frequency arry
    int frequencyArray_counter=0;
    //stores individual durations of squarewaves from the cpr_output
    int time_Storage [frequencyArraySize/2];
    int counter = 0;

void reset_frequencyArrays(){
    //fill timeStorage with 0s
    for (size_t i = 0; i < frequencyArraySize/2; i++)
    {
        time_Storage[i] = 0;
    }
    //resetting frequencyArray
    for (size_t i = 0; i < frequencyArraySize; i++)
    {
        frequencyArray[i]=0;
    }
}

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
    reset_frequencyArrays();
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

void measureFrequency(){
    int n1 = 0;
    int n2 = 0;
    bool found = false;

    //find falling edges of the sqarewave produced by schmittrigger, which indicate the end of a wave, and store them int time_Storage
    for (size_t i = 0; i < frequencyArraySize-1; i++)
    {
        if(frequencyArray[i]==1 && frequencyArray[i+1]==0)
        {
           if(!found){
            n1 = i;
            if(n2!=0){
            time_Storage[counter] = ((n1-n2)*cpr_timestepp)+1;
            counter++;
            }
            
            found = true;
           }else{
            n2 = i;

            time_Storage[counter] = ((n2-n1)*cpr_timestepp)+1;
            counter++;

            found = false;
           }
        }
    }
    
    //find out average wave duration
    double waveDuration = 0; 
    for (size_t i = 0; i < counter; i++)
    {
        waveDuration = waveDuration + time_Storage[i];
    }
    
    //calculate frequency
    if(waveDuration!=0)
    {
        waveDuration = waveDuration/counter;
        //convert to seconds
        waveDuration=waveDuration/1000;
        frequency = 1.0/ waveDuration;
    }else{
    frequency = 0.0;
    }
    counter=0;
}


void convertCprToBinary(){
    int schmittMedian = cpr_range/2;

    if(cprRollingAverage > schmittMedian){
        frequencyArray[frequencyArray_counter] = 1;

    }else {
        frequencyArray[frequencyArray_counter] = 0;
    }

    frequencyArray_counter++;

    if(frequencyArray_counter==frequencyArraySize){
        measureFrequency();
        reset_frequencyArrays();
        frequencyArray_counter = 0;
        Serial.println();
    }

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
        cpr_millis_old=cpr_millis_new;
        convertCprToBinary();
    }
    else{

    }
}

#endif