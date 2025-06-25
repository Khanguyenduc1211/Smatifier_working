#include "gesture_module.h"

uint8_t GestureModule::getGesture(CST816S &touch) {
    static uint8_t last_gesture = 0;

    if (touch.available()) {
        uint8_t g = touch.data.gestureID;
        if (g != 0 && g != last_gesture) {
            last_gesture = g;
            // Trả về đúng các gesture mong muốn
            if (g == 0x01 || g == 0x02 || g == 0x03 || g == 0x04 ||
                g == 0x05 || g == 0x0B || g == 0x0C) {
                return g;
            }
        }
    } else {
        last_gesture = 0;
    }
    return 0;
}

const char* GestureModule::gestureString(uint8_t gesture) {
    switch (gesture) {
        case 0x01: return "SWIPE: DOWN";
        case 0x02: return "SWIPE: UP";
        case 0x03: return "SWIPE: LEFT";
        case 0x04: return "SWIPE: RIGHT";
        case 0x05: return "SINGLE TAP";
        case 0x0B: return "DOUBLE TAP";
        case 0x0C: return "LONG PRESS";
        default:   return nullptr;
    }
}