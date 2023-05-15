#ifndef __LEDS_H__
#define __LEDS_H__

#include <stdint.h>
#include <stdbool.h>

void leds_init(uint16_t* direccion);
void leds_turn_on_single(int led);
void leds_turn_off_single(int led);
void leds_turn_on_all(void);
void leds_turn_off_all(void);
bool leds_get_state(int led);

#endif