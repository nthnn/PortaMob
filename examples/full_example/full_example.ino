#include <Adafruit_SSD1306.h>
#include <PortaMob.h>

Adafruit_SSD1306 display =
    PortaMob::portamob_display();

void setup() {
    Serial.begin(9600);
    PortaMob::init_buttons();
}

void loop() {

}