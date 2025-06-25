#pragma once
#include "../modules/display_module.h"

#define BG3 0x39E7  // Lục đậm

inline void drawScreen3(DisplayModule &display, int x_offset, int y_offset) {
    int w = display.tft.width();
    int h = display.tft.height();
    display.tft.fillRect(x_offset, y_offset, w, h, BG3);
    display.tft.setFont(nullptr);
    display.tft.setTextDatum(middle_center);
    display.tft.setTextColor(TFT_CYAN, BG3);
    display.tft.setTextSize(3);
    display.tft.drawString("Hello 3", x_offset + w / 2, y_offset + h / 2);
    display.tft.setTextSize(1);
}