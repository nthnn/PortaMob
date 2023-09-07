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

/**
 * 
 * @file PortaMob.h
 * @brief The PortaMob Arduino Shield Library
 *
 * The %PortaMob library facilitates the interaction
 * with the %PortaMob Shield components, including the
 * 3x3 push button grid, monochromatic 0.96 inch OLED
 * display, and an EEPROM memory. This library empowers
 * developers with a comprehensive yet easy-to-use set
 * of functions to harness the shield's capabilities
 * for prototyping, educational demonstrations, and
 * interactive simulations.
 *
 * @author [Nathanne Isip](https://github.com/nthnn)
 * @date 29 August 2023
 */

#ifndef PORTAMOB_H
#define PORTAMOB_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#define PORTAMOB_KEY_1 2     ///< Digital pin number for button 1
#define PORTAMOB_KEY_2 5     ///< Digital pin number for button 2
#define PORTAMOB_KEY_3 8     ///< Digital pin number for button 3
#define PORTAMOB_KEY_4 9     ///< Digital pin number for button 4
#define PORTAMOB_KEY_5 3    ///< Digital pin number for button 5
#define PORTAMOB_KEY_6 6    ///< Digital pin number for button 6
#define PORTAMOB_KEY_7 4     ///< Digital pin number for button 7
#define PORTAMOB_KEY_8 7     ///< Digital pin number for button 8
#define PORTAMOB_KEY_9 10    ///< Digital pin number for button 9

#define PORTAMOB_EEPROM_ADDR 0x50       ///< EEPROM I2C address
#define PORTAMOB_SCREEN_ADDRESS 0x3C    ///< OLED screen I2C address

/**
 * 
 * @class PortaMob
 * 
 * @brief A class that provides comprehensive
 *        functionalities to interact with the
 *        %PortaMob Shield components.
 * 
 */
class PortaMob {
public:
    /**
     * 
     * @brief Initializes the %PortaMob display.
     *
     * This function initializes the monochromatic
     * OLED display and sets up a display callback
     * function to handle initialization errors.
     * Then, it returns an `Adafruit_SSD1306` object
     * representing the %PortaMob display, which can
     * be further configured for various visual outputs.
     *
     * @param on_error A callback function to handle
     *                 display initialization errors.
     * 
     * @return `Adafruit_SSD1306` An object representing
     *         the %PortaMob display.
     * 
     */
    static Adafruit_SSD1306 portamob_display(
        void (*on_error)()
    );

    /**
     * 
     * @brief Initializes the push buttons on
     *        the %PortaMob Shield.
     *
     * This function initializes the digital pins
     * for the push buttons, preparing them for
     * input detection. Once initialized, the
     * buttons can be checked for their status
     * using the `is_button_pressed()` function.
     * 
     */
    static void init_buttons(void);

    /**
     * 
     * @brief Checks if a specific button is pressed.
     *
     * This function checks the status of a specified
     * button and returns a boolean indicating whether
     * the button is currently pressed or not. It takes
     * the pin number of the button as a parameter (e.g.,
     * `PORTAMOB_KEY_1`) and returns `true` if the button
     * is pressed, otherwise `false`.
     *
     * @param button The button pin to check (e.g.,
     *               PORTAMOB_KEY_1).
     * 
     * @return bool Returns `true` if the button is
     *         pressed, `false` otherwise.
     * 
     */
    static bool is_button_pressed(uint8_t button);

    /**
     * 
     * @brief Initializes the I2C communication.
     *
     * This function initializes the I2C communication
     * for the %PortaMob Shield, enabling communication
     * with external devices such as EEPROM and the
     * OLED display.
     * 
     */
    static void init_i2c();

    /**
     * 
     * @brief Writes a value to the EEPROM memory.
     *
     * This function writes a single byte value
     * to the specified address in the EEPROM
     * memory. It takes the memory address and
     * the value to be written as parameters.
     *
     * @param addr The address in the EEPROM
     *             memory to write to.
     * @param value The byte value to write.
     * 
     */
    static void eeprom_write(
        uint8_t addr,
        uint8_t value
    );

    /**
     * 
     * @brief Reads a value from the EEPROM memory.
     *
     * This function reads a single byte value
     * from the specified address in the EEPROM
     * memory. It takes the memory address as
     * a parameter and returns the byte value
     * read from the EEPROM.
     *
     * @param addr The address in the EEPROM memory
     *             to read from.
     * 
     * @return uint8_t The byte value read from the
     *         EEPROM memory.
     * 
     */
    static uint8_t eeprom_read(uint8_t addr);

    /**
     * 
     * @brief Checks if the EEPROM memory is present.
     *
     * This function checks if the EEPROM memory is
     * detected on the I2C bus by attempting to
     * communicate with it. It returns `true` if the
     * EEPROM is detected, otherwise `false`.
     *
     * @return bool Returns `true` if the EEPROM memory
     *         is detected, `false` otherwise.
     * 
     */
    static bool has_eeprom();
};

#endif