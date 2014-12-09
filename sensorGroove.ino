#define ELECTRICITY_SENSOR A0 

float amplitude_current;               
float effective_value;      
void setup() 
{
        Serial.begin(9600); 
        pins_init();
}
void loop() 
{
        int sensor_max;
        sensor_max = getMaxValue();
        Serial.print("sensor_max = ");
        Serial.println(sensor_max);
        amplitude_current=(float)sensor_max/1024*5/800*2000000;
        effective_value=amplitude_current/1.414;
                                                
        Serial.println("The amplitude of the current is(in mA)");
        Serial.println(amplitude_current,1);
        Serial.println("The effective value of the current is(in mA)");
        Serial.println(effective_value,1);
}
void pins_init()
{
        pinMode(ELECTRICITY_SENSOR, INPUT);
}
int getMaxValue()
{
        int sensorValue;             
        int sensorMax = 0;
        uint32_t start_time = millis();
        while((millis()-start_time) < 1000)
        {
                sensorValue = analogRead(ELECTRICITY_SENSOR);
                if (sensorValue > sensorMax) 
                {
                        sensorMax = sensorValue;
                }
        }
        return sensorMax;
}
