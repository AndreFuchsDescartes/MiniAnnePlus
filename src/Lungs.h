// #### Settings ####

//Upper limit of lung inflation. Values above this are concidered too little ventilation.
double lung_inflation_threshold_upper = 0;
//Lower limit of lung inflation. Values below this are concidered too much ventilation.
double lung_inflation_threshold_lower = 0;
//Limit of ventilation. Values above this are concidered as "NO ventilation is happening".
double ventilation_threshold = 0;

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


