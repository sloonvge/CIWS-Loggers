#AggieWater Smart Water Metering Project

This repository contains files and documentation for a smart water metering solution being researched and developed by the Utah Water Research Laboratory at Utah State University using low cost commercially available computers and sensors. This system can turn most possitive displacement water meters with detachable register into a smart water meter with capabilities to store high frequency flowrate data for up to a week in a battery run. 


![alt tag](https://github.com/UCHIC/WaterMonitor/blob/master/doc/images/AGGIEWATER_SYSTEM_CLOSEUP3.png)

1- Datalogger using Raspberry pi and custom made pi hat.  
2- Hall effect senser wired to the datalogger.  
3- Battery pack.  
4- Power on and off connector.  
5- Weather proof case.   
#Getting Started
![alt tag](https://github.com/UCHIC/WaterMonitor/blob/master/doc/images/AGGIEWATER_PACK.png)
###Setting up and starting the system
To start using the this system just plug the power on/off connector and wait 20 seconds for the system to boot. Make sure your battery is fully charge to extract the most of the data collection run. Once the system is up, plug an ethernet cable between the Raspberry and a laptop computer and follow the intructions below.

####Change laptop computer network adapter ip address

Right-click on the network adapter you want to assign an IP address and click Properties. Highlight Internet Protocol Version 4 (TCP/IPv4) then click the Properties button. Now change the IP, Subnet mask, Default Gateway, and DNS Server Addresses. When you're finished click OK. This setting is only  needed once if the same laptop computer is used to communicate to the AggieWater system.

![alt tag](https://github.com/UCHIC/WaterMonitor/blob/master/doc/images/static_ip.png)

####SSH into the Raspberry Pi
We have assigned an unique static IP address to all the prototypes we have created that can be found in a label on the lid of the weather proof case. The label also contains user and password information to access the Raspberry Pi.
#####Windows
Use Putty or any other terminal emulator.  

![alt tag](https://github.com/UCHIC/WaterMonitor/blob/master/doc/images/putty.png)
#####Mac and linux
Use the system default terminal type the following and hit enter:  

   <pre>
   ssh pi@192.168.0.XX
   </pre>

When prompted for credentials type the password provided and hit enter.  Once a connection is stablished, all the following settings will happen in the Raspberry Pi.

####Set system date
The system do not have a backpup power supply to hold the date when power cycled. Use the following command to set the date when the system is powered:

<pre>
date -s "2 OCT 2006 18:00:00"
</pre>

####Set conf.xml file
We have created an .xml file that contains the basic set up information for the system to start the datalogging routine. This file can be used to add the required METADATA for the identification of the site and variables.
```
<data>
    <items>
        <item name="Datalogger:" value = "Raspberry pi"></item>
        <item name="Sitename:" value = "Site name goes here."></item>
        <item name="Port1:" value = "adc1" initial_value = "11500"></item>
        <item name="Port2:" value = "adc2" initial_value = "11500"></item>
        <item name="Port3:" value = "adc3" initial_value = "11500"></item>
        <item name="Port4:" value = "adc4" initial_value = "11500"></item>
                <item name="Site_description" value= "Brief site description goes here"></item>
                <item name="Time_support" value= "4"></item>
                <item name="Data_directory" value="/home/pi/Datalog/"></item>
    </items>
</data>
```
Use the following instructions to modify the conf.xml file.  

Type on the terminal:
```
nano conf.xml
```
![alt tag](https://github.com/UCHIC/WaterMonitor/blob/master/doc/images/conf.png)

Modify conf.xml accordignly. When finished use the hotkey (<kbd>CTRL</kbd>+<kbd>X</kbd>), hit (<kbd>Y</kbd>) to accept modifications, verify filename and hit (<kbd>ENTER</kbd>) to save the file.

We are now ready to start logging data.

####Run sensor_module.py
This is the main script that will be running while collecting data. Use the following command to start the sensor_module.py script:
```
cd WaterMonitor/src/
sudo python sensor_module.py &
```

####Stop sensor_module.py
```
sudo killall python
```

####Using the listener.py
###Calibration
###Data retrieval



##License


##Sponsors and Credit



