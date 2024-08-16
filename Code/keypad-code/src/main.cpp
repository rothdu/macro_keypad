#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include <Button.h>
#include <MIDI.h>

// LED pins
const uint8_t LED_NW = 0;
const uint8_t LED_SW = 1;
const uint8_t LED_NE = 14;
const uint8_t LED_SE = 15;

// Buttons
Button sw_mod(2);
Button sw_sel(3);
Button sw_0(4);
Button sw_1(5);
Button sw_2(6);
Button sw_3(7);
Button sw_4(8);
Button sw_5(9);
Button sw_6(10);
Button sw_7(11);
Button sw_8(12);
Button sw_9(13);

uint8_t led_states = 0b0;

void setup()
{
  pinMode(LED_NW, OUTPUT);
  pinMode(LED_SW, OUTPUT);
  pinMode(LED_NE, OUTPUT);
  pinMode(LED_SE, OUTPUT);

  sw_mod.begin();
  sw_sel.begin();
  sw_0.begin();
  sw_1.begin();
  sw_2.begin();
  sw_3.begin();
  sw_4.begin();
  sw_5.begin();
  sw_6.begin();
  sw_7.begin();
  sw_8.begin();
  sw_9.begin();
}

void loop()
{
}
