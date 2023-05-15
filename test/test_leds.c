/*
    - Después de la inicialización todos los LEDs deben quedar apagados.
    - Se puede prender un LED individual.
    - Se puede apagar un LED individual.
    - Se pueden prender y apagar múltiples LED’s.
    - Se pueden prender todos los LEDs de una vez.
    - Se pueden apagar todos los LEDs de una vez.
    - Se puede consultar el estado de un LED.
*/

#include "unity.h"

#include "leds.h"

#include <stdint.h>

// Al inicializar la biblioteca, todos los leds quedan apagados.
void test_todos_los_leds_inician_apagados(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_encender_un_solo_led_con_los_demas_apagados(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    leds_turn_on_single(2);

    TEST_ASSERT_EQUAL_HEX16(0x0002, puerto_virtual);
}

void test_encender_y_apagar_un_solo_led_con_los_demas_apagados(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    leds_turn_on_single(3);
    TEST_ASSERT_EQUAL_HEX16(0x0004, puerto_virtual);

    leds_turn_off_single(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_encender_y_apagar_varios_leds(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    leds_turn_on_single(3);
    TEST_ASSERT_EQUAL_HEX16(0x0004, puerto_virtual);

    leds_turn_on_single(5);
    TEST_ASSERT_EQUAL_HEX16(0x0014, puerto_virtual);

    leds_turn_off_single(3);
    TEST_ASSERT_EQUAL_HEX16(0x0010, puerto_virtual);

    leds_turn_on_single(7);
    TEST_ASSERT_EQUAL_HEX16(0x0050, puerto_virtual);

    leds_turn_off_single(7);
    TEST_ASSERT_EQUAL_HEX16(0x0010, puerto_virtual);
}

void test_encender_un_solo_led_y_leer_estado(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    leds_turn_on_single(15);
    TEST_ASSERT_EQUAL_HEX16(0x4000, puerto_virtual);
    TEST_ASSERT_TRUE(leds_get_state(15));
    TEST_ASSERT_FALSE(leds_get_state(1));
}

void test_apagar_un_solo_led_y_leer_estado(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);

    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);

    leds_turn_off_single(7);
    TEST_ASSERT_FALSE(leds_get_state(7));
    TEST_ASSERT_TRUE(leds_get_state(2));
}

void test_encender_todos_los_leds(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

void test_apagar_todos_los_leds(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);

    leds_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_encender_led_fuera_de_rango_superior_e_inferior(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);

    leds_turn_on_single(0);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);

    leds_turn_on_single(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);

    leds_turn_on_single(-240);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_apagar_led_fuera_de_rango_superior_e_inferior(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_init(&puerto_virtual);

    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);

    leds_turn_off_single(0);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);

    leds_turn_off_single(17);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);

    leds_turn_off_single(-240);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);

}