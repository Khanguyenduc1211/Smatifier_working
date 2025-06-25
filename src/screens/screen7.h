#pragma once
#include "../modules/display_module.h"

#define BG7 0x4208  // Nâu đậm

inline void drawScreen7(DisplayModule &display, int x_offset, int y_offset) {
    int w = display.tft.width();
    int h = display.tft.height();
    display.tft.fillRect(x_offset, y_offset, w, h, BG7);
    display.tft.setFont(nullptr);
    display.tft.setTextDatum(middle_center);
    display.tft.setTextColor(TFT_BLUE, BG7);
    display.tft.setTextSize(3);
    display.tft.drawString("Hello 7", x_offset + w / 2, y_offset + h / 2);
    display.tft.setTextSize(1);
}