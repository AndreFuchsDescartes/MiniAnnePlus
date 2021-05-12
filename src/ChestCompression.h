#ifndef ChestCompression_h
#define ChestCompression_h
// #### Settings CPR ####
//controlls how many measurements of the cpr sensor are averaged together for the rolling average
#define cpr_no_of_measurements 4

//time in ms for each measurement
#define cpr_timestepp 100

//caps cprValues at this value. Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define cpr_range 150

//lung cpr values are multiplied with this value to amplify small readings
#define cpr_amplification 4

//values mesured below this value are concidered 0. This check is done after amplification is applied.Value between 0 and 1023. 0 is no reading 1023 is max reading.
#define cpr_lower_limit 20

//Limit of cpr. Values above this are concidered as "NO cpr is happening". Value between 0 and 1023. 1023 is no reading 0 is max reading.
#define cpr_threshold 975

//Class for cpr measurements
class Cpr
{
private:
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
    //used to save sensor reading from cpr to cprValues array to calculate rolling average
    void save_cpr(int datapoint);
    //used to calculate rolling average of sensor readings from cpr sensor
    int cpr_rolling_average();
    //reads analog voltage of cpr sensor and converts it to positive capped value in specified range
    int read_cpr(int input);
    
    
public:
    Cpr();
    //Initialises CPR object
    void init();
    //Measures CPR and outputs it to serial monitor
    void logCpr();
};
#endif 