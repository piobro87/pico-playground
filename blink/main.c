#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define UNIT_MS 150
#define LED_PIN PICO_DEFAULT_LED_PIN

static inline void led_on(void) { 
    gpio_put(LED_PIN, 1); }

static inline void led_off(void) { 
    gpio_put(LED_PIN, 0); }

static inline void delay_units(uint32_t units) { 
    sleep_ms(units * UNIT_MS); }

// Morse elements
static void dot(void) {
    led_on();
    delay_units(1);
    led_off();
    delay_units(1);
}

static void dash(void) {
    led_on();
    delay_units(3);
    led_off();
    delay_units(1);
}

static inline void letter_gap(void) {
    delay_units(2);
}

static inline void word_gap(void) {
    delay_units(6);
}

// Morse letters

static void morse_s(void) {
    dot(); dot(); dot();
}

static void morse_o(void) {
    dash(); dash(); dash();
}

int main(void)
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    led_off();

    while(1) {
        morse_s();
        letter_gap();
        morse_o();
        letter_gap();
        morse_s();
        word_gap();
    }
    return 0;
}