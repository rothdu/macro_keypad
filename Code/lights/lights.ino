#include <Arduino.h>
// LED definitions
const uint8_t LED_NW = 0;
const uint8_t LED_SW = 1;
const uint8_t LED_NE = 14;
const uint8_t LED_SE = 15;

const uint8_t LEDs[] = {LED_NW, LED_SW, LED_NE, LED_SE};

// SW definitions
const uint8_t SW_1 = 2;
const uint8_t SW_2 = 3;
const uint8_t SW_3 = 4;
const uint8_t SW_4 = 5;
const uint8_t SW_5 = 6;
const uint8_t SW_6 = 7;
const uint8_t SW_7 = 8;
const uint8_t SW_8 = 9;
const uint8_t SW_9 = 10;
const uint8_t SW_10 = 11;
const uint8_t SW_11 = 12;
const uint8_t SW_12 = 13;

const uint8_t SWs[] = {SW_1, SW_2, SW_3, SW_4, SW_5, SW_6, SW_7, SW_8, SW_9, SW_10, SW_11, SW_12};
const uint8_t SW_NUMs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void writeLeds(uint8_t pattern) {
  digitalWrite(LED_NW, pattern & 0b1000);
  digitalWrite(LED_SW, pattern&0b0100);
  digitalWrite(LED_NE, pattern&0b0010);
  digitalWrite(LED_SE, pattern&0b0001);
}

void setup() {
  // init LEDs
  for (uint8_t i = 0; i < sizeof(LEDs)/sizeof(LEDs[0]); i++) {
    pinMode(LEDs[i], OUTPUT);
  }
  // init switches
  for (uint8_t i = 0; i < sizeof(SWs)/sizeof(SWs[0]); i++) {
    pinMode(SWs[i], INPUT_PULLUP);
  }
}

void loop() {
  uint8_t led_pattern = 0b0;

  for (uint8_t i = 0; i < sizeof(SWs)/sizeof(SWs[0]); i++) {
    // if current switch is being being held
    if(!digitalRead(SWs[i])) {
      // check which switch and engage relevant lights
      switch (SW_NUMs[i]) {
        case 1: led_pattern |= 0b1100; break;
        case 2: led_pattern |= 0b0011; break;
        case 3: led_pattern |= 0b1000; break;
        case 4: led_pattern |= 0b1110; break;
        case 5: led_pattern |= 0b1010; break;
        case 6: led_pattern |= 0b1011; break;
        case 7: led_pattern |= 0b0010; break;
        case 8: led_pattern |= 0b0100; break;
        case 9: led_pattern |= 0b1101; break;
        case 10: led_pattern |= 0b0101; break;
        case 11: led_pattern |= 0b0111; break;
        case 12: led_pattern |= 0b0001; break;
      }
    }
  }

  // write the pattern to the LEDs
  writeLeds(led_pattern);
}
