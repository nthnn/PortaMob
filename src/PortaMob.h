#ifndef PORTAMOB_H
#define PORTAMOB_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#define PORTAMOB_KEY_1 D2
#define PORTAMOB_KEY_2 D3
#define PORTAMOB_KEY_3 D4
#define PORTAMOB_KEY_4 D5
#define PORTAMOB_KEY_5 D6
#define PORTAMOB_KEY_6 D7
#define PORTAMOB_KEY_7 D8
#define PORTAMOB_KEY_8 D9
#define PORTAMOB_KEY_9 D10

#define PORTAMOB_EEPROM_ADDR 0x50

class PortaMob {
public:
    static Adafruit_SSD1306 portamob_display(void (on_error*)());

    static void init_buttons(void);
    static bool is_button_pressed(uint8_t button);

    static void init_i2c();
    static void eeprom_write(uint8_t addr, uint8_t value);
    static uint8_t eeprom_read(uint8_t addr);
    static bool has_eeprom();
};

#endif