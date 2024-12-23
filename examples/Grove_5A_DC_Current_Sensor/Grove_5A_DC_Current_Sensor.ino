/*
    Seeed_ACS70331_basis_Demo.ino
    Driver for 5A DC/AC Current Sensor (ACS70331)

    Copyright (c) 2018 Seeed Technology Co., Ltd.
    Website    : www.seeed.cc
    Author     : Jenkin
    Create Time: August 2018
    Change Log :

    The MIT License (MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifdef NRF52840_XXAA
#ifdef USE_TINYUSB
#include <Adafruit_TinyUSB.h>
#endif
#endif

#ifdef SEEED_XIAO_M0
    #define RefVal 5.0
    #define SER Serial
#elif defined(ARDUINO_SAMD_VARIANT_COMPLIANCE)
    #define RefVal 3.3
    #define SER SerialUSB
#else
    #define RefVal 5.0
    #define SER Serial
#endif
//An OLED Display is required here
//use pin A0

#if defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_ARCH_RP2350) || defined(CONFIG_IDF_TARGET_ESP32C3) || defined(CONFIG_IDF_TARGET_ESP32C6) 
#define Pin D5
#else
#define Pin A5
#endif

// Take the average of 500 times

const int averageValue = 500;

long int sensorValue = 0;

float sensitivity = 1000.0 / 200.0; //1000mA per 200mV

/******************************************************************************
 ***************************    Notice   **************************************
 ******************************************************************************
     Output voltage with no current: 250mV , but there are errors because of
    the different boards.When we use UNO/Seeeduino v4, the approximate value is
    244mV; When we use the M0 series, the approximate value is 265mV;If you use
    other boards, follow these steps.
    1. The value of the sensorValue is read when there is no current load.
    2. Print out the initial voltage and assign it to the Vref.
 ******************************************************************************/

//float Vref = 244;
float Vref = 1508;

void setup() {
    SER.begin(9600);
}

void loop() {
    // Read the value 500 times:
    for (int i = 0; i < averageValue; i++) {
        sensorValue += analogRead(Pin);

        // wait 2 milliseconds before the next loop
        delay(2);

    }

    sensorValue = sensorValue / averageValue;


    // The on-board ADC is 10-bits
    // Different power supply will lead to different reference sources
    // example: 2^10 = 1024 -> 5V / 1024 ~= 4.88mV
    //          unitValue= 5.0 / 1024.0*1000 ;
    float unitValue = RefVal / 1024.0 * 1000 ;
    float voltage = unitValue * sensorValue;

    //When no load,Vref=initialValue
    SER.print("initialValue: ");
    SER.print(voltage);
    SER.println("mV");

    // Calculate the corresponding current
    float current = (voltage - Vref) * sensitivity;

    // Print display voltage (mV)
    // This voltage is the pin voltage corresponding to the current
    /*
        voltage = unitValue * sensorValue-Vref;
        SER.print(voltage);
        SER.println("mV");
    */

    // Print display current (mA)
    SER.print(current);
    SER.println("mA");

    SER.print("\n");

    // Reset the sensorValue for the next reading
    sensorValue = 0;
    // Read it once per second
    delay(1000);
}
