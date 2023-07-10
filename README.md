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
  

  ### TODO
   - [ ] Make it whitespace insensitive
