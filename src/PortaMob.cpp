/*
 * This file is part of the PortaMob Shield Arduino library.
 * Copyright (c) 2023 Nathanne Isip
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#include "PortaMob.h"

Adafruit_SSD1306 PortaMob::portamob_display(void (*on_error)()) {
    Adafruit_SSD1306 display(128, 32, &Wire, -1);

    if(!display.begin(
        SSD1306_SWITCHCAPVCC,
        PORTAMOB_SCREEN_ADDRESS
    )) on_error();

    display.clearDisplay();
    return display;
}

void PortaMob::init_buttons(void) {
    pinMode(PORTAMOB_KEY_1, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_2, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_3, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_4, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_5, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_6, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_7, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_8, INPUT_PULLUP);
    pinMode(PORTAMOB_KEY_9, INPUT_PULLUP);
}

bool PortaMob::is_button_pressed(uint8_t button) {
    return digitalRead(button) == LOW;
}

void PortaMob::init_i2c() {
    Wire.begin();
}

void PortaMob::eeprom_write(
    uint8_t addr,
    uint8_t value
) {
    Wire.beginTransmission(PORTAMOB_EEPROM_ADDR);

    Wire.write((int)(addr >> 8));
    Wire.write((int)(addr & 0xFF));
    Wire.write(value);

    Wire.endTransmission();
}

uint8_t PortaMob::eeprom_read(uint8_t addr) {
    byte data = 0xFF;
    Wire.beginTransmission(PORTAMOB_EEPROM_ADDR);

    Wire.write((int)(addr >> 8));
    Wire.write((int)(addr & 0xFF));

    Wire.endTransmission();
    Wire.requestFrom(PORTAMOB_EEPROM_ADDR, 1);

    if(Wire.available())
        data = Wire.read();
    return data;
}

bool PortaMob::has_eeprom() {
    Wire.beginTransmission(PORTAMOB_EEPROM_ADDR);

    return Wire.endTransmission(
        PORTAMOB_EEPROM_ADDR
    ) == 0;
}
