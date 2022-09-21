# ESP32_I2C_ADC_1015

Hardware used:

	Adafruit ESP32 feather
	Adafruit ADS1015

Source software:

	singleended.ino       (Adafruit)
	Adafruit_ADS1X15.h  library

Target:
Replace the arduino wire.h library with the espresif "driver/i2c.h" library.   


Task implemented:
Basically I modified two functions from the Adafruit_ADS1X15.h library 
	-  void Adafruit_ADS1X15::writeRegister(uint8_t reg, uint16_t value)
	- uint16_t Adafruit_ADS1X15::readRegister(uint8_t reg)

 I have replaced the calls to wire.h by  calls to the espresif library as explained in the espresif guide. 


 Notes:
      1-  The I2C initialization is done in the set-up section of I2C_espressif_ADC_1015.ino sketch.
           Which makes it easier to make changes such as the I2C speed.
      2-  I have not changed the names of the Adafruit files Adafruit_ADS1X15.cpp  and Adafruit_ADS1X15.h

 How to try it:
      Copy the three files  I2C_espressif_ADC_1015.ino, Adafruit_ADS1X15.cpp  and Adafruit_ADS1X15.h  into a   I2C_espressif_ADC_1015   folder and compile.
  
