//GPS module RX and TX conneced to ESP32 GPIO 16 and 17

#include "simplegps.h"

char buf[SENTENCE_BUFFER_SIZE]; // defined in simplegps.h, the length of the array used to read each NMEA sentence.

simplegps gps;

void setup()
{
  gps.initialize(9600);
  Serial.begin(9600);
}

void loop()
{  
  gps.update_data();

  Serial.print("\nTime... ");
  Serial.print(gps.time_hours); Serial.print(":"); Serial.print(gps.time_minutes); Serial.print(":"); Serial.print(gps.time_seconds); Serial.print("\n");
  Serial.print("Latitude... ");
  Serial.print(gps.latitude_degrees); Serial.print("*"); Serial.print(gps.latitude_minutes); Serial.print("'"); Serial.print(gps.latitude_format); Serial.print("\n");
  Serial.print("Longitude... ");
  Serial.print(gps.longitude_degrees); Serial.print("*"); Serial.print(gps.longitude_minutes); Serial.print("'"); Serial.print(gps.longitude_format); Serial.print("\n");
  Serial.print("Altitude... ");
  Serial.print(gps.altitude); Serial.print(gps.altitude_format); Serial.print("\n");

  delay(500);
}
