# maxPhoton5

A Particle project named maxPhoton5

Maxbotix serial sensor reading. Uses 7092 sensor with RS232 output converted
to TTL with MAX3232 breakout.

Code detects the 'R' in the sensor's data 'word' and then reads the ascii numerals into an array.
atoi function is used to convert char array to an integer range value.
