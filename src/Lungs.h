// #### Settings ####

//Upper limit of lung inflation. Values above this are concidered too little ventilation.
double lung_inflation_threshold_upper = 0;
//Lower limit of lung inflation. Values below this are concidered too much ventilation.
double lung_inflation_threshold_lower = 0;
//Limit of ventilation. Values above this are concidered as "NO ventilation is happening".
double ventilation_threshold = 650;
//Int variable for analog read from lung inflation sensor
int lung_inflation_input;
//Int variable for analog read from ventilation sensor
int ventilation_input;

// #### Variables ####

//Analog voltage from lung sensor in chest
double lung_inflation; 
//Indicates wheter lungs are inflated properley based on lung_inflation_threshold
bool lung_inflation_is_good; 
//Analog voltage from ventilation sensor in face
double ventilation;
//Timestamp to determine elapsed time between measurements
int lung_millis_old;
//Timestamp to determine elapsed time between measurements
int lung_millis_new;

// #### Functions ####

//lungs setup function
void lungs_setup(){
    //assigning analog input pin to corresponding integer for inflation analog read
    lung_inflation_input = lung_inflation_input_pin;
    //assigning analog input pin to corresponding integer for ventilation analog read
    ventilation_input = ventilation_input_pin;
    //saving current millis to use in timestamping of lung sensor data
    lung_millis_old = millis();

}

//function to measure ventilation. Sends data to RPie via USB after each read. Reads are taken every 0.1s
void measure_ventilation (){
    lung_millis_new = millis();
    if (lung_millis_new >= 100)
    {
        ventilation = analogRead(ventilation_input);
        Serial.print("inflation: ");
            if (ventilation_threshold<= ventilation)
            {
                Serial.println(analogRead(lung_inflation_input));
            }   
            else{
                Serial.println(0);
            }
        
    }
    else{

    }
    
}