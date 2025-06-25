#pragma once
#include "../modules/display_module.h"

#define BG2 0x0822  // Tím đậm

inline void drawScreen2(DisplayModule &display, int x_offset, int y_offset) {
    int w = display.tft.width();
    int h = display.tft.height();
    display.tft.fillRect(x_offset, y_offset, w, h, BG2);
    display.tft.setFont(nullptr);
    display.tft.setTextDatum(middle_center);
    display.tft.setTextColor(TFT_YELLOW, BG2);
    display.tft.setTextSize(3);
    display.tft.drawString("Hello 2", x_offset + w / 2, y_offset + h / 2);
    display.tft.setTextSize(1);
}