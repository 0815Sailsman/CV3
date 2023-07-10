# CV3
Weltherrschaft 2024

Includes:
 - a basic websocket server, designed to feed data into html visualizer
 - sensor and motor scanner (autodetect port, mode etc)

## Custom communication protocol on top of the websocket (EV3/Server -> Client):
  Message structure:  
    portname, device-name, [*device-specific-data*] | ...

    
  Whitespaces have to be removed

  
  Device specific data:  
    Includes all kinds of data that this device can provide. Keys dont have to be provided to identify the data. This will be hardcoded on the client. Example:

    Lets say a color sensor offers color and reflection. The device specific data will look something like this:  
    [colorR, colorG, colorB, reflection]  or with concrete data  [100, 555, 1000, 69]  
    The receiving device then sees the device-name and can deduce the meaning of the specific values.  

  List of implemented devices, modes and how they have to be handled:  
   - [Lego Color Sensor](https://docs.ev3dev.org/projects/lego-linux-drivers/en/ev3dev-stretch/sensor_data.html#lego-ev3-color)
     - [x] Color
     - [x] Raw Color
     - [x] Reflection
     - [x] Ambient Color

     Example block:  

    in1,lego-ev3-color,[0,0,0,0,0,0]

   - [Lego US Sensor](https://docs.ev3dev.org/projects/lego-linux-drivers/en/ev3dev-stretch/sensor_data.html#lego-ev3-us)
     - [ ] Distance CM
   - [Lego Touch Sensor](https://docs.ev3dev.org/projects/lego-linux-drivers/en/ev3dev-stretch/sensor_data.html#lego-ev3-us)
     - [ ] Pressed

  ### TODO
   - [ ] Make it whitespace insensitive
   - [ ] Move away from strings to improve performance

Port can be expressed through Byte
Type should be able to be expressed through byte (we dont need to support all possible)
Every value will be 1 or at most 2 bytes
         
This should improved performance by alot since we dont need expensive string operations but only simple nr ops
