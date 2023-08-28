// PortaMob Shield Full Example
// By: Nathanne Isip
// 29 August 2023

#include <Adafruit_SSD1306.h>
#include <PortaMob.h>

void on_display_err();

Adafruit_SSD1306 display =
    PortaMob::portamob_display(on_display_err);

void setup() {
    Serial.begin(9600);
    PortaMob::init_buttons();
}

void loop() {

}

void on_display_err() {
    Serial.println("Cannot find OLED display.");
    while(true);
}