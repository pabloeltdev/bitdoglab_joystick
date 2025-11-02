// Bibliotecas do C
#include <stdio.h>

// bibliotecas da sdk
#include "pico/stdlib.h"
#include "hardware/adc.h"

// Pinos e canais do ADC para o joystick
#define JOYSTICK_Y_PIN 26
#define JOYSTICK_Y_CHANNEL 0 
#define JOYSTICK_X_PIN 27
#define JOYSTICK_X_CHANNEL 1

#include "pico/stdlib.h"

#include "joystick.h"

void joystick_init() {
    // inicializa o joytick e configura os pinos gpio do mesmo
    adc_init();
    adc_gpio_init(JOYSTICK_Y_PIN);
}
// Le os valores do ADC do Joystick e returna uma direção {JOYSTICK_DIRECTION}
JOYSTICK_DIRECTION joystick_get_direction() {
    // le os valores do joystick
    adc_select_input(JOYSTICK_Y_CHANNEL);
    const uint16_t joystick_y = adc_read();
    adc_select_input(JOYSTICK_X_CHANNEL);
    const uint16_t joystick_x = adc_read();
    // meio-termo (thumbstick parado) e um offset para ignorar valores proximos
    const uint middle = 2048;
    const uint offset = 1200;
    // Returna a direção do joystick
    if (joystick_x > middle + offset) return RIGHT;
    else if (joystick_x < middle - offset) return LEFT;
    else if (joystick_y  > middle + offset) return UP;
    else if (joystick_y < middle - offset) return DOWN;
    else return STABLE;
}