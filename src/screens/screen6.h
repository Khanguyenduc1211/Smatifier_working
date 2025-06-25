#pragma once
#include "../modules/display_module.h"

#define BG6 0x0841  // Xanh xám

inline void drawScreen6(DisplayModule &display, int x_offset, int y_offset) {
    int w = display.tft.width();
    int h = display.tft.height();
    display.tft.fillRect(x_offset, y_offset, w, h, BG6);
    display.tft.setFont(nullptr);
    display.tft.setTextDatum(middle_center);
    display.tft.setTextColor(TFT_MAGENTA, BG6);
    display.tft.setTextSize(3);
    display.tft.drawString("Hello 6", x_offset + w / 2, y_offset + h / 2);
    display.tft.setTextSize(1);
}