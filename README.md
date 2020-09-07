# simpleGPS
For ESP32: Header file to get bare minimum GPS data from GPS module using Arduino IDE

    #include "simplegps.h"

Create simplegps object

    simplegps gps;

Initialize

    gps.initialize(9600);

call simplegps::update_data() to read from module

    gps.update_data();

Read data from variables....
    
    int hours = gps.time_hours
    int minutes = gps.time_minutes
    float seconds = gps.time_seconds
    int lattitude_degrees = gps.lattitude_degrees
    float lattitude_minutes = gps.lattitude_minutes
    
....etc.
