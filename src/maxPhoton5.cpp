#include "application.h"
#line 1 "/Users/raventt/MBP_Projects/arduino/maxPhoton5/src/maxPhoton5.ino"
/*
 * Project maxPhoton4
 * Description: Interface Maxbotix serial sensor to Particle Photon or Arduino compatible
 * Author: David Richards / ravenIoT LLC
 * Date: May 22, 2019
 */

// Using hardware UART on Photon, Electron, Fio
// Maxbotix sensor with RS232 conversion to TTL with MAX3232

void setup();
void loop();
uint16_t maxRead();
#line 11 "/Users/raventt/MBP_Projects/arduino/maxPhoton5/src/maxPhoton5.ino"
void setup()
{
  Serial.begin(57600);
  while (!Serial)
  {
    ; // wait for serial port to connect.
  }
  Serial.println("Serial open");
  // set the data rate from the sensor
  Serial1.begin(9600, SERIAL_8N1); // Default but set explicitly anyway
  while (!Serial1)
  {
    ; // wait for Serial1 port to connect.
  }
  Serial.println("Sensor connected");
}

void loop()
{
  delay(100);
  uint16_t range = maxRead();
  Serial.print("Range: ");
  Serial.println(range);
  delay(1000);
}

uint16_t maxRead()
{
char inChar;                        // type for data read
const uint8_t length = 3;           // number of ascii numeric characters in sensor data
char charArray[length];             // array to store range data
uint8_t i = 0;                      // initialize counter

  while (Serial1.available()) {
    inChar = Serial1.read();        // continuously read sensor input in while loop
    if (inChar == 'R') {            // test if char == R for beginning data
      Serial.println("Got an R");
      while (i < length) {
        charArray[i] = Serial1.read(); // assign input char to charArray index
        Serial.print("char: ");
        Serial.println(charArray[i]);
        i++;
      }
    }
  }

  for (i = 0; i < 3; i++){
  Serial.print("charArray: ");
  Serial.println(charArray[i]);
  }
  return atoi(charArray);            // extract integer range from char charArray
}

// void clearInputBuffer()             // Sensor continuously outputs data to built-in buffer
// {                                   // This code is intended to empty sensor buffer
//   // Serial1.flush();
//   if (Serial1.available() != 0)
//   {
//     Serial1.read();
//   }
// }

// int maxRead()
// {
//   while (Serial1.available() >= 0)
//   {
//     inChar = Serial1.read();
//     if (inChar == 82)
//     {
//       Serial.println("Got 82");
//       range = Serial1.parseInt();
//       // Serial.println(range);
//     }
//   }
//   return range;
// }