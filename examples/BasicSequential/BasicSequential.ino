/*
 * Copyright (c) 2026 Jorge Iván Salinas Baltazar
 * SPDX-License-Identifier: MIT
 */

#include <Arduino.h>
#include <vector>

const int LED_1 = 4;
const int LED_5 = 19;

void setup() {
  pinMode(4, OUTPUT);  
  pinMode(16, OUTPUT); 
  pinMode(17, OUTPUT); 
  pinMode(18, OUTPUT); 
  pinMode(19, OUTPUT); 
}

class Led {
public:

  Led() = default;

  void light(int led) {
    digitalWrite(led, HIGH);
  }

  void off(int led) {
    digitalWrite(led, LOW);
  }

  void multi_led(int led_inicio, int led_final, long int milisegundos) {
    for (int i = led_inicio; i <= led_final; i++) {
      if (i >= 6 && i <= 11) continue; 
      digitalWrite(i, HIGH);
      delay(milisegundos);
      digitalWrite(i, LOW);
      delay(milisegundos);
    }
  }

  void multi_led_simulataneo(int led_inicio, int led_final, long int milisegundos) {
    std::vector<int> leds;
    leds.reserve((led_final - led_inicio) + 1);

    for (int i = led_inicio; i <= led_final; i++) {
      if (i >= 6 && i <= 11) continue;
      leds.push_back(i);
    }
    
    for (int led : leds) {
      digitalWrite(led, HIGH);
    }
    delay(milisegundos);
    
    for (int led : leds) {
      digitalWrite(led, LOW);
    }
    delay(milisegundos);
  }

  void multi_led_vector(const std::vector<int>& leds, long int milisegundos) {
    for (int led : leds) {
      digitalWrite(led, HIGH);
    }
    delay(milisegundos);
    
    for (int led : leds) {
      digitalWrite(led, LOW);
    }
    delay(milisegundos);
  }
};


Led miLed;

void loop() {

  miLed.multi_led_simulataneo(4, 7, 1000); 
}
