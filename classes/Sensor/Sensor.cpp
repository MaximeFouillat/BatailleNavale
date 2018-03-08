#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int in_pin_sensor){
  pinMode(pin, INPUT);
  _in_pin_sensor = in_pin_sensor;
  _is_shooter = HIGH;
}

int Sensor::read_sensor()
{
  _is_shooter = digitalRead(_in_pin_sensor);
  if (_is_shooter == LOW)
  {
    Serial.println("SHOOTER PRESENT!!");
  }
  else
  {
    Serial.println("clear");
  }
  delay(200);
  return _is_shooter;
}  
