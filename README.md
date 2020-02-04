Grove current sensor   [![Build Status](https://travis-ci.com/Seeed-Studio/Grove_Current_Sensor.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Grove_Current_Sensor)
=================================  

![ACS70331](https://user-images.githubusercontent.com/41441945/44913532-42900300-ad60-11e8-8e51-bf8a2f2ab357.jpg)  


Introduction of sensor
----------------------------  
>1. 2.5A current sensor is a direct current measuring no more than 2.5A.
>2. 5A current sensor is a direct current and alternating current measuring no more than 5A.
>3. 10A current sensor is a direct current measuring no more than 10A.
    This can be used to measure system power consumption, realize current monitoring and so on.The current sensor outputs an analog voltage that varies linearly with current.

***
Usage:
==========  
Download all the source files. There are seven examples for user to use.
>1. examples/Grove_XXXA_Current_Sensor, here are three examples of products: 2.5A/5A/10A current sensor,open it in arduino IDE. Compile and download and run it on a arduino board.
>2. If you own an OLED, you can connect it to work with it.Open examples/Grove_xxxA_Current_Sensor_OLED in arduino IDE. Compile and download and run it on a arduino board.

****
Notice:
=========
>1. This examples/Grove_XXXA_Current_Sensor is just a simple display demo by the serial port monitor.
>2. When there is no load, the display is not 0 and the error is large. You need to calibrate according to the following steps.
    1. The value of the sensorValue is read when there is no current load.
    2. Print out the initial voltage and assign it to the Vref.
>3. The maximum range is 2.5A/5A/10A,notice short-circuit the connection.
    Get more detail from **doc/ACS70331-Datasheet.pdf** 



***
This software is written by Jenkin for seeed studio<br>
Email:zhengxing.lu@seeed.cc
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>
****
Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.
****
Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
