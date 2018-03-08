
#include "Arduino.h";
class Led
{
  public:
    Led();
    void allumer_led(int id, char couleur);
    void eteindre(int id);
    int id;
    char couleur;
}
