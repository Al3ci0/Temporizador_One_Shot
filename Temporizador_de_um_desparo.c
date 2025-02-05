#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Define os pinos dos LEDs e do botão
#define RED_LED 12
#define BLUE_LED 11
#define GREEN_LED 13
#define BUTTON 5

// Variáveis globais para controle do estado dos LEDs e debounce do botão
volatile bool led_active = false;
volatile int led_state = 0;
volatile uint32_t last_button_press = 0;

// Função chamada pelo temporizador para desligar os LEDs progressivamente
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (led_state == 0) {
        gpio_put(GREEN_LED, 0); // Desliga o LED verde
        led_state++;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (led_state == 1) {
        gpio_put(BLUE_LED, 0); // Desliga o LED azul
        led_state++;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (led_state == 2) {
        gpio_put(RED_LED, 0); // Desliga o LED vermelho
        led_active = false;
    }
    return 0;
}

// Função de callback acionada quando o botão é pressionado
void button_callback(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if ((current_time - last_button_press) < 200) {
        return; // Ignora bouncing com um tempo de debounce de 200ms
    }
    last_button_press = current_time;
    
    if (!led_active) {
        led_active = true;
        led_state = 0;
        gpio_put(RED_LED, 1); // Liga o LED vermelho
        gpio_put(BLUE_LED, 1); // Liga o LED azul
        gpio_put(GREEN_LED, 1); // Liga o LED verde
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();
    
    // Configuração dos LEDs como saída
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_init(BLUE_LED);
    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    
    // Configuração do botão como entrada com pull-up
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    
    // Configuração da interrupção para detectar pressionamento do botão
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    
    while (1) {
        printf("Esperando clique do botão...\n");
        sleep_ms(1000); // Aguarda 1 segundo antes de imprimir novamente
    }
}
