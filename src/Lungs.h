#ifndef Lungs_h
#define Lungs_h

// #### Settings ####

//Upper limit of lung inflation. Values above this are concidered too little ventilation. Value between 0 and 1023. 1023 is no reading 0 is max reading.
#define lung_inflation_threshold_upper 0
//Lower limit of lung inflation. Values below this are concidered too much ventilation. Value between 0 and 1023. 1023 is no reading 0 is max reading.
#define lung_inflation_threshold_lower 0
//Limit of ventilation. Values above this are concidered as "NO ventilation is happening". Value between 0 and 1023. 1023 is no reading 0 is max reading.
#define ventilation_threshold 990
//controlls timestepp between measurements of lung inflation in millisecconds
#define lung_timestepp 100
//controlls how many measurements of the lung are averaged to gether to smooth out signal. The time between measurements is set with lung_timestepp
#define lung_no_of_measurements 3
//caps lung_inflation at this value. Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define inflation_range 200
//lung inflation values are multiplied with this value to amplify small readings
#define inflation_amplification 2



class Lungs 
{
private:
    // #### Variables ####

    //Analog voltages from lung sensor in chest
    int lung_inflation[lung_no_of_measurements]; 
    //inflation array counter
    int inflation_count =0;
    //Indicates wheter lungs are inflated properley based on lung_inflation_threshold
    bool lung_inflation_is_good; 
    //Analog voltage from ventilation sensor in face
    int ventilation;
    //Timestamp to determine elapsed time between measurements
    unsigned long lung_millis_old;
    //Timestamp to determine elapsed time between measurements
    unsigned long lung_millis_new;
    //Int variable for analog read from lung inflation sensor
    int lung_inflation_input;
    //Int variable for analog read from ventilation sensor
    int ventilation_input;

    // #### Functions ####

    //used to save sensor reading from lungs to lung_inflation array to calculate rolling average
    void save_inflation(int datapoint);
    //used to calculate rolling average of sesnor readings from lungs
    int rolling_average();
    //reads analog voltage of lung sensor and converts it to positive capped value in specified range
    int read_inflation();

    


public:
    // #### Functions ####
    //Constructor
    Lungs();
    //lungs setup function
    void setup();
    //function to measure ventilation. Sends data to RPie via USB after each read. Reads are taken every 0.1s
    void log_ventilation ();
};








#endif