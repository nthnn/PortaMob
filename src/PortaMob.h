#ifndef PORTAMOB_H
#define PORTAMOB_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#define PORTAMOB_KEY_1 2
#define PORTAMOB_KEY_2 3
#define PORTAMOB_KEY_3 4
#define PORTAMOB_KEY_4 5
#define PORTAMOB_KEY_5 6
#define PORTAMOB_KEY_6 7
#define PORTAMOB_KEY_7 8
#define PORTAMOB_KEY_8 9
#define PORTAMOB_KEY_9 10

#define PORTAMOB_EEPROM_ADDR 0x50

class PortaMob {
public:
    static Adafruit_SSD1306 portamob_display(
        void (*on_error)()
    );

    static void init_buttons(void);
    static bool is_button_pressed(uint8_t button);

    static void init_i2c();
    static void eeprom_write(
        uint8_t addr,
        uint8_t value
    );

    static uint8_t eeprom_read(uint8_t addr);
    static bool has_eeprom();
};

#endif