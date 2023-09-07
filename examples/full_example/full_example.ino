// PortaMob Shield Full Example
// By: Nathanne Isip
// 29 August 2023

#include <Adafruit_SSD1306.h>
#include <PortaMob.h>

void on_display_err();

int index = 0;
const int greetings_count = 7;
String greetings[greetings_count] = {
    "Hello, world!",
    "Kamusta?",
    "Konnichiwa",
    "Nihao",
    "Marahib",
    "Como esta?",
    "Salam alaykum"
};

void setup() {
    Serial.begin(9600);
    PortaMob::init_buttons();

    auto display = PortaMob::portamob_display(on_display_err);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(14, 22);
    display.print(greetings[index++]);
    display.display();

    while(true)
      if(PortaMob::is_button_pressed(PORTAMOB_KEY_5)) {
        if(index == greetings_count)
          index = 0;

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE, BLACK);
        display.setCursor(10, 10);
        display.print(greetings[index++]);
        display.display();

        delay(1000);
      }
}

void loop() { }

void on_display_err() {
    Serial.println("Cannot find OLED display.");
    while(true);
}