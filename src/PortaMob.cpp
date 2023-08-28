#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#include "PortaMob.h"

Adafruit_SSD1306 PortaMob::portamob_display(void (on_error*)()) {
    Adafruit_SSD1306 display(128, 32, &Wire, -1);

    if(!display.begin(
        SSD1306_SWITCHCAPVCC,
        SCREEN_ADDRESS
    )) on_error();

    display.clearDisplay();
    display.display();

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
