#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/i2c.h"    //espresif  library

#include "Adafruit_ADS1X15.h" 


#include <stdlib.h>
#include <string.h>

/*=========================================================================
    I2C ADDRESS/BITS
    -----------------------------------------------------------------------*/
#define ADS1015_ADDRESS_0 (0x48) /// (ADDR = GND)      ADS1015  (12 bits) address
#define ADS1015_ADDRESS_1 (0x49) /// (ADDR = VIN)
#define ADS1015_ADDRESS_2 (0x4A) /// (ADDR = SDA)      
#define ADS1015_ADDRESS_3 (0x4B) /// (ADDR = SCL)

////////////////////////////////////////////////////////////////////////////

#define I2C_SDA_0             GPIO_NUM_23
#define I2C_SCL_0             GPIO_NUM_22
#define I2C_FREQ_0            100000           // 100kHz

#define TAG "adc_test"

 
Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */


//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
static void init_i2C_0()
{
    i2c_config_t conf;
    // I2C
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_SDA_0;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = I2C_SCL_0;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_FREQ_0;
    i2c_param_config(I2C_NUM_0, &conf);
    i2c_driver_install(I2C_NUM_0, conf.mode, 0, 0, 0);
}

//////////////////////////////////////////////////////////////////////
// TO BE IMPLEMENTED for I2C second channel ...
/*
static void init_i2C_1()
{
    i2c_config_t conf;
    // I2C
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_SDA_1;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = I2C_SCL_1;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_FREQ_1;
    i2c_param_config(I2C_NUM_0, &conf);
    i2c_driver_install(I2C_NUM_1, conf.mode, 0, 0, 0);
}

*/

//////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  bool found_Device;

  init_i2C_0();    
  // init_i2C_1();  
  
  Serial.begin(115200);
  delay (3000);
  Serial.println("\nI2C ADC 1015");

  //******************************************* 
  //*******************************************   
  found_Device = ads.begin (ADS1015_ADDRESS_0, I2C_NUM_0);           // device address & I2C channel
  //*******************************************   

  if (!found_Device){
      Serial.println("Device NOT found");
      while (1){

        // To be implemented.....
       }
    }



}



void loop() {


    int16_t adc0, adc1, adc2, adc3;
  float volts0, volts1, volts2, volts3;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);

  volts0 = ads.computeVolts(adc0);
  volts1 = ads.computeVolts(adc1);
  volts2 = ads.computeVolts(adc2);
  volts3 = ads.computeVolts(adc3);

  Serial.println("-----------------------------------------------------------");
  Serial.print("AIN0: "); Serial.print(adc0); Serial.print("  "); Serial.print(volts0); Serial.println("V");
  Serial.print("AIN1: "); Serial.print(adc1); Serial.print("  "); Serial.print(volts1); Serial.println("V");
  Serial.print("AIN2: "); Serial.print(adc2); Serial.print("  "); Serial.print(volts2); Serial.println("V");
  Serial.print("AIN3: "); Serial.print(adc3); Serial.print("  "); Serial.print(volts3); Serial.println("V");

  

  delay(3000);
    
}
