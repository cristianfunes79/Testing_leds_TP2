#include "leds.h"

static uint16_t* puerto_virtual;

void leds_init(uint16_t* direccion)
{
    puerto_virtual = direccion;
   *direccion = 0x0000; 
}

void leds_turn_on_single(int led)
{

}