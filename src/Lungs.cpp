#include <Arduino.h>
#include <Lungs.h>
#include <Pinout.h>

Lungs:: Lungs() 
{

}
//lungs setup function
void Lungs::setup()
{
    //assigning analog input pin to corresponding integer for inflation analog read
    lung_inflation_input = lung_inflation_input_pin;
    //assigning analog input pin to corresponding integer for ventilation analog read
    ventilation_input = ventilation_input_pin;
    //saving current millis to use in timestamping of lung sensor data
    lung_millis_old = millis();
    //filling lung_inflation with zeroes
    for (int i = 0; i < lung_no_of_measurements; i++)
    {
        lung_inflation[i]=0;
    }
     

}

//function to measure ventilation. Sends data to RPie via USB after each read. Reads are taken according to lung_timestepp
void Lungs::log_ventilation (){
    lung_millis_new = millis();
    if (lung_millis_new - lung_millis_old>= lung_timestepp)
    {
        ventilation = analogRead(ventilation_input);
            if (ventilation<= ventilation_threshold)
            {
                save_inflation(read_inflation());
            }   
            else{
                //Serial.println("NO Ventilation");
                save_inflation(0);
            }
        Serial.print("inflation average: ");   
        Serial.println(rolling_average());
        //for testing purposes only. uncomment to see how much time elapses between reads.
        /*
        Serial.print("set timestepp: ");
        Serial.println(lung_timestepp);
        Serial.print("Actual timestepp: ");
        Serial.println(lung_millis_new - lung_millis_old);
        Serial.print("Averaged across: ");
        Serial.print(lung_no_of_measurements);
        Serial.println(" values");
        Serial.print("Time to calculate: ");
        Serial.println(millis()-lung_millis_new);
        
        Serial.print("inflation: ");   
        Serial.println(analogRead(lung_inflation_input));
        Serial.print("ventilation: ");
        Serial.println(ventilation);
        Serial.println();
        */
    
        lung_millis_old=lung_millis_new;

        
    }
    else{

    }
}

//reads analog voltage of lung sensor and converts it to positive capped value in specified range
int Lungs::read_inflation(){
    int temp = 0;
    temp = inflation_amplification * abs(analogRead(lung_inflation_input)-1023);
    if (temp >= inflation_range)
     {
        temp = inflation_range;
     }
    
    return temp;
}

//used to save sensor reading from lungs to lung_inflation array to calculate rolling average
void Lungs::save_inflation(int datapoint){
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
int Lungs::rolling_average(){
    int average =0;
    for (int i = 0; i < lung_no_of_measurements; i++)
    {
        average = average + lung_inflation[i];
    }
    average = average/lung_no_of_measurements;
    return average;
}