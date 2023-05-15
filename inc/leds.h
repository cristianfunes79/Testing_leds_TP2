#ifndef __LEDS_H__
#define __LEDS_H__

#include <stdint.h>

void leds_init(uint16_t* direccion);
void leds_turn_on_single(int led);

#endif