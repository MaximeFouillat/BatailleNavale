
#include "Arduino.h"
#include "Led.h"
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 60

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
// leds arrangement.
FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);

// methode allumer_led(id, couleur) : allume la led désirée de la couleur
//                                    désirée
void Led::allumer_led(id, couleur){
  switch (couleur){
    case b://bleu
      leds[id] = CRGB(66, 194, 244);
      break;
    case j://jaune
      leds[id] = CRGB(224, 220, 8);
      break;
    case o://orange
      leds[id] = CRGB(244, 143, 65);
      break;
    case r://rouge
      leds[id] = CRGB(252, 15, 15);
      break;
    case v://vert
      leds[id] = CRGB(7, 183, 10);
      break;
    case i://violet
      leds[id] = CRGB(160, 11, 193);
      break;
  }
  FastLED.show();
}

// methode eteindre_led(id) : eteind la led désirée
void Led::eteindre_led(id){
  leds[id] = CRGB::Black;
  FastLED.show();
}
