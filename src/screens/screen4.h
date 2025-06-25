#pragma once
#include "../modules/display_module.h"

#define BG4 0x1A86  // Lam đậm

inline void drawScreen4(DisplayModule &display, int x_offset, int y_offset) {
    int w = display.tft.width();
    int h = display.tft.height();
    display.tft.fillRect(x_offset, y_offset, w, h, BG4);
    display.tft.setFont(nullptr);
    display.tft.setTextDatum(middle_center);
    display.tft.setTextColor(TFT_ORANGE, BG4);
    display.tft.setTextSize(3);
    display.tft.drawString("Hello 4", x_offset + w / 2, y_offset + h / 2);
    display.tft.setTextSize(1);
}