#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
const int BTN_PIN = 28;
const int BTN_PIN_G = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {
  static int red = 0;
  static int green = 0;
  stdio_init_all();
  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);
  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);
  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  while (true) {
    if(!gpio_get(BTN_PIN)) {
      if(red==0) {
        printf("LED R ON\n");
        gpio_put(LED_PIN_R, 1);
        red = 1;
      } else {
        printf("LED R OFF\n");
        gpio_put(LED_PIN_R, 0);
        red = 0;
      }
      while(!gpio_get(BTN_PIN)) {
      };
    }
    if(!gpio_get(BTN_PIN_G)) {
      if(green==0) {
        gpio_put(LED_PIN_G, 1);
        green = 1;
      } else {
        gpio_put(LED_PIN_G, 0);
        green = 0;
      }
      while(!gpio_get(BTN_PIN_G)) {
      };
    }
  }
}
