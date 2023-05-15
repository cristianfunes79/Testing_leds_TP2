#ifndef __LEDS_H__
#define __LEDS_H__

#include <stdint.h>
#include <stdbool.h>

/// @brief Inicializa el driver de leds.
/// @param direccion Direccion de memoria del driver.
void leds_init(uint16_t* direccion);

/// @brief Enciende un led.
/// @param led Indice del led a encender.
void leds_turn_on_single(int led);

/// @brief Apaga un led.
/// @param led Indice del led a apagar.
void leds_turn_off_single(int led);

/// @brief Enciende todos los leds
/// @param  None
void leds_turn_on_all(void);

/// @brief Apaga todos los leds.
/// @param  None
void leds_turn_off_all(void);

/// @brief Retorna el estado actual de un led.
/// @param led Indice del led a leer.
/// @return True si el led se encuentra encendido. False si el led se encuentra apagado.
bool leds_get_state(int led);

#endif