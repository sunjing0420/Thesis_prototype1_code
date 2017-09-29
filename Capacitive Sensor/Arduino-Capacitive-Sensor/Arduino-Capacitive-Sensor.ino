#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);

void setup()                    
{
   cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
   cs_2_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(9600);
   
}

void loop()                    
{

 long sensor1 =  cs_4_8.capacitiveSensor(50);
 long sensor2 =  cs_2_7.capacitiveSensor(50);

  if(sensor1>100 && sensor2<500){
    Serial.write("1");  // print sensor output
  }else if(sensor2>500 && sensor1<100){
    Serial.write("2");  // print sensor output 
  }
}
