// Uses third Serial Port (Serial Port 2) on the ESP32. For me this was on pins 16 & 17.
// Serial Port 0 is shared with USB.
// Writing to Serial Port 1 will crash the ESP32.

#include <HardwareSerial.h>
#include <stdlib.h>

#define SENTENCE_BUFFER_SIZE    2048

#define TIME_WORD               1 // Time is the 1st word after $GPGGA
#define TIME_HOURS_CHAR         0 // Hours starts 0 characters into Time
#define TIME_MINUTES_CHAR       2 // Minutes starts 2 characters into Time
#define TIME_SECONDS_CHAR       4 // Seconds starts 4 characters into Time

#define LATITUDE_WORD          2 // Latitude is the 2nd word after $GPGGA
#define LATITUDE_DEGREES_CHAR  0 // Degrees starts 0 characters into Latitude
#define LATITUDE_MINUTES_CHAR  2 // Minutes starts 0 characters into Latitude
#define LATITUDE_FORMAT_WORD   3 // 3rd word after $GPGGA is 'N' for North or presumably 'S' for South

#define LONGITUDE_WORD          4 // Longitude is the 4th word after $GPGGA
#define LONGITUDE_DEGREES_CHAR  0 // Degrees starts 0 characters into Longitude
#define LONGITUDE_MINUTES_CHAR  3 // Minutes starts 0 characters into Longitude
#define LONGITUDE_FORMAT_WORD   5 // 5th word after $GPGGA is 'W' for West or presumably 'E' for East

#define ALTITUDE_WORD           9 // Altitude is the 9th word after $GPGGA
#define ALTITUDE_FORMAT_WORD    10 // 10th word after $GPGGA is 'M' for meters or presumably 'F' for feet

class simplegps
{
  uint8_t sentence[SENTENCE_BUFFER_SIZE];
  char* word_ptrs[50];
  int no_of_words;
  int word_length[50];
  int sentence_length;
  void getsentence();
  void getwords();
  
public:
  
  // Use these variables to access data.
  int time_hours, // UTC time
      time_minutes,
      latitude_degrees,
      longitude_degrees;
  double time_seconds,
         latitude_minutes,
         longitude_minutes,
         altitude;
  char latitude_format, // 'N' or 'S' for North or South
       longitude_format, // 'E' or 'W' for East or West
       altitude_format; // Shoould be 'M' for meters

  // Start comm. on Serial Port 2 and initialize public variables above to 0 and '\0' as applicable
  void initialize(int baud_rate);

  // Get data from GPS module
  void update_data();
};
