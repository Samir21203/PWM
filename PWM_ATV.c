#include "pico/stdlib.h"
#include "hardware/pwm.h"

const uint SERVO_GPIO = 22;  // GPIO onde o servo está conectado (12 para teste do LED)
uint16_t MIN_PULSE_WIDTH = 500;   // Pulso mínimo em microsegundos (0 graus)
uint16_t MID_PULSE_WIDTH = 1470;  // Pulso médio em microsegundos (90 graus)
uint16_t MAX_PULSE_WIDTH = 2400;  // Pulso máximo em microsegundos (180 graus)
const uint16_t PWM_WRAP = 19999; // Wrap para 50Hz de frequência PWM
const uint16_t STEP_SIZE = 5;  // Incremento para suavização

#define DELAY_MS 10  // Atraso entre incrementos


int main() {
    stdio_init_all();

    // Configuração do PWM
    gpio_set_function(SERVO_GPIO, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(SERVO_GPIO);
    pwm_set_clkdiv(slice, 125.0f);
    pwm_set_wrap(slice, PWM_WRAP);
    pwm_set_enabled(slice, true);

    // Sequência de posições
    pwm_set_gpio_level(SERVO_GPIO, MAX_PULSE_WIDTH);
    sleep_ms(5000);

    pwm_set_gpio_level(SERVO_GPIO, MID_PULSE_WIDTH);
    sleep_ms(5000);

    pwm_set_gpio_level(SERVO_GPIO, MIN_PULSE_WIDTH);
    sleep_ms(5000);

    // Movimentação suave entre 0° e 180°
    while (true) {
        for (uint16_t pos = MIN_PULSE_WIDTH; pos < MAX_PULSE_WIDTH; pos += STEP_SIZE) {
            pwm_set_gpio_level(SERVO_GPIO, pos);
            sleep_ms(DELAY_MS);
        }
        for (uint16_t pos = MAX_PULSE_WIDTH; pos > MIN_PULSE_WIDTH; pos -= STEP_SIZE) {
            pwm_set_gpio_level(SERVO_GPIO, pos);
            sleep_ms(DELAY_MS);
        }
    }
}
