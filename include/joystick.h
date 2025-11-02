#if !defined(JOYSTICK_H)
#define JOYSTICK_H

// Direção que o joystick está apontado
typedef enum JOYSTICK_DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STABLE
} JOYSTICK_DIRECTION;

// Inicialização do ADC do joystick
void joystick_init();
// Obter direção atual
JOYSTICK_DIRECTION joystick_get_direction();

#endif // JOYSTICK_H
