#include <FastLED.h>

// Número de leds a utilizar
#define NUM_LEDS 16

#define DATA_PIN 5
// #define CLOCK_PIN 13
#define joyX 4
#define joyY 33

// Define el arreglo de leds
CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS); 
  Serial.begin(115200);
}
int XXant = 0;
void loop()
{
  // Enciende los leds y luego pausa.
  int XX = analogRead(joyX);
  XX = XX / 4095.0 * NUM_LEDS;
  Serial.println(XX);
  if (XX != XXant)
  {
    for (int i = 0; i < XX; i++)
    {
      leds[i] = CRGB(0, 13, 255);
      FastLED.show();
      delay(50);
    }
    for (int i = 0; i < (NUM_LEDS-XX); i++)
    {
      leds[NUM_LEDS-i] = CRGB::Black;
      FastLED.show();
      delay(50);
    }
    XXant = XX;
  }

  delay(250);
}
