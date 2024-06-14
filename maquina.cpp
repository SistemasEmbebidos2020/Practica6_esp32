#include <FastLED.h>
// Leds a utilizar
#define NUM_LEDS 60

// Definición de los pines
#define DATA_PIN 5
#define joyX 4
#define joyY 35

// Define el arreglo de los LEDS
CRGB leds[NUM_LEDS];
// Variables para el joystick
int XX = 0;
int YY = 0;
int XXant = 0;
// combinación de colores para tira led
int coloress[5] = {0x00ff00, 0x0000ff, 0xff0000, 0x0f0f0f, 0x000000};

// Enum de los estados para la máquina de estados
enum State
{
  IDLE,
  UPDATING_LED,
  DELAY_BEFORE_NEXT_READ
};

// Estado Inicial
State currentState = IDLE;

void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); // 
  Serial.begin(115200);
}

void loop()
{
  switch (currentState)
  {
  case IDLE:
    // Lee el eje X del joystick
    XX = analogRead(joyX);
    // Normaliza XX al rango de los Leds
    XX = map(XX, 0, 4095, 0, NUM_LEDS);

    // Comprueba si XX cambió
    if (XX != XXant)
    {
      currentState = UPDATING_LED;
    }
    else
    {
      currentState = DELAY_BEFORE_NEXT_READ;
    }
    break;

  case UPDATING_LED:
    // Actualiza los leds basandose en el valor de XX
    for (int i = 0; i < XX; i++)
    {
      leds[i] = CRGB(coloress[1]);
      FastLED.show();
    }
    for (int i = XX; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(coloress[4]);
      FastLED.show();
    }
    XXant = XX;

    currentState = DELAY_BEFORE_NEXT_READ;
    break;

  case DELAY_BEFORE_NEXT_READ:
    // Añade un delay antes de la siguiente lectura
    delay(50);
    currentState = IDLE;
    break;
  }
}
