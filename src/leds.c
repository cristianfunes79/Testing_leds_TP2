/*
    Driver de LEDs: Requisitos
        - Maneja 16 leds de dos estados (encendido y apagado).
        - Se puede cambiar el estado de un led sin afectar a los otros.
        - Se puede cambiar el estado de todos los led’s en una sola
          operación
        - Se puede recuperar el estado actual de un led.
        - Los led’s están mapeados en una palabra de 16 bits en
          memoria en una dirección a determinar.
        - Para encender el led se debe escribir un “1” en el bit y para
          apagarlo se debe escribir un “0”.
        - El led 1 corresponde al lsb y el led 16 al msb.
        - El reset de hardware no define un estado conocido de los
          led’s, estos deben ser apagados por software
*/

#include "leds.h"

// Macros y constantes --------------------
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF

static const int ledIndexOffset = 1;
static const int firstLedIndex = 1;
static const int lastLedIndex = 16;

// Variables Privadas ---------------------
static uint16_t* puerto_virtual;


// Funciones Privadas ---------------------
static uint16_t index_to_mask_(int led)
{
    return firstLedIndex << (led-ledIndexOffset);
}

// Funciones Publicas ---------------------
void leds_init(uint16_t* direccion)
{
    puerto_virtual = direccion;
   *direccion = ALL_LEDS_OFF; 
}

void leds_turn_on_single(int led)
{
    if (led >= firstLedIndex && led <= lastLedIndex)
      *puerto_virtual |= index_to_mask_(led);
}

void leds_turn_off_single(int led)
{
    if (led >= firstLedIndex && led <= lastLedIndex)
      *puerto_virtual &= ~index_to_mask_(led);
}

void leds_turn_on_all(void)
{
    *puerto_virtual = ALL_LEDS_ON;
}

void leds_turn_off_all(void)
{
    *puerto_virtual = ALL_LEDS_OFF;
}

bool leds_get_state(int led)
{
    return (*puerto_virtual & (index_to_mask_(led))) > 0;
}