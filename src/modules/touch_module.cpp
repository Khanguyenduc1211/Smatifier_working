#include "touch_module.h"

TouchModule::TouchModule(int sda, int scl, int rst, int int_pin)
    : touch(sda, scl, rst, int_pin), sda(sda), scl(scl), rst(rst), int_pin(int_pin) {}

void TouchModule::begin() {
    Wire.begin(sda, scl);
    Wire.setClock(400000);
    pinMode(rst, OUTPUT);
    digitalWrite(rst, LOW); delay(30);
    digitalWrite(rst, HIGH); delay(150);
    touch.begin();
    touch.disable_auto_sleep();
}

bool TouchModule::getTouch(int &x, int &y) {
    if (touch.available()) {
        x = touch.data.x;
        y = touch.data.y;
        return true;
    }
    return false;
}

CST816S& TouchModule::getCST816S() {
    return touch;
}