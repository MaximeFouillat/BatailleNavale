/*
  Sensor.h - Library for flashing Sensor code.
*/
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class Sensor
{
  public:
    Sensor(int in_pin_sensor);
    int read_sensor(int in_pin_sensor);
  private:
    int _in_pin_sensor; // sensor's output : 60 sensors in the game
    int _is_shooter = HIGH;  // HIGH MEANS NO Shooter
}
