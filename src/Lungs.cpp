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
    //filling face_ventilation with zeroes
    for (int i = 0; i < ventilation_no_of_measurements; i++)
    {
        face_ventilation[i]=0;
    }
     

}

//function to measure ventilation. Sends data to RPie via USB after each read. Reads are taken according to lung_timestepp
void Lungs::log_inflation (){
    lung_millis_new = millis();
    int inflation_temp = 0;
    int ventilation_temp = 0;
    if (lung_millis_new - lung_millis_old>= lung_timestepp)
    {
        ventilation_temp = analogRead(ventilation_input);
        save_ventilation(ventilation_temp);
        ventilation_temp = ventilation_rolling_average();
            if (ventilation_temp<= ventilation_threshold)
            {
                save_inflation(read_inflation());
            }   
            else{
                save_inflation(0);
            } 
        inflation_temp = inflation_rolling_average(); 
        if (inflation_temp <= inflation_lower_limit || ventilation_temp > ventilation_threshold)
        {
            inflation_temp = 0;
        }
        
        Serial.print(F("inflation average: ")); 
        Serial.println(inflation_temp);
        
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
         
        Serial.print("ventilation average: ");
        Serial.println(ventilation_temp);
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

//used to save sensor reading from face to face_ventilation array to calculate rolling average
void Lungs::save_ventilation(int datapoint){
    if (ventilation_count<ventilation_no_of_measurements)
    {
        face_ventilation[ventilation_count]= datapoint;
        ventilation_count++;
    }
    else
    {
        ventilation_count=0;
        face_ventilation[ventilation_count]= datapoint;
        ventilation_count++;
    }
}

//used to calculate rolling average of sesnor readings from lungs
int Lungs::inflation_rolling_average(){
    int average =0;
    for (int i = 0; i < lung_no_of_measurements; i++)
    {
        average = average + lung_inflation[i];
    }
    average = average/lung_no_of_measurements;
    return average;
}

//used to calculate rolling average of sesnor readings from face
int Lungs:: ventilation_rolling_average(){    
    int average =0;
    for (int i = 0; i < ventilation_no_of_measurements; i++)
    {
        average = average + face_ventilation[i];
    }
    average = average/ventilation_no_of_measurements;
    return average;
}