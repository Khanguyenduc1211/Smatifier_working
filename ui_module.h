#pragma once

#include "display_module.h"

// Các màu nền tối khác nhau, bạn có thể thay tùy ý
#define BG1 0x18E3  // Xanh đậm
#define BG2 0x0822  // Tím đậm
#define BG3 0x39E7  // Lục đậm
#define BG4 0x1A86  // Lam đậm
#define BG5 0x18C4  // Đỏ đậm
#define BG6 0x0841  // Xanh xám
#define BG7 0x4208  // Nâu đậm
#define BG8 0x0020  // Xanh biển đậm

class UIModule {
public:
  void drawHello(DisplayModule &display, const char* txt, uint32_t color, int x_offset, int y_offset, uint32_t bg) {
    int w = display.tft.width();
    int h = display.tft.height();

    display.tft.fillRect(x_offset, y_offset, w, h, bg);

    // Font mặc định, chữ to nhất vừa 80% chiều ngang với "Hello 8"
    display.tft.setFont(nullptr);
    int longest = 7; // "Hello 8"
    int text_size = (int)((0.8 * w) / (longest * 6));
    if (text_size < 1) text_size = 1;

    display.tft.setTextDatum(middle_center);
    display.tft.setTextColor(color, bg);
    display.tft.setTextSize(text_size);

    display.tft.drawString(txt, x_offset + w / 2, y_offset + h / 2);

    display.tft.setTextSize(1); // Reset về mặc định
  }

  void showScreen1At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 1", TFT_WHITE, x_offset, y_offset, BG1);
  }
  void showScreen2At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 2", TFT_YELLOW, x_offset, y_offset, BG2);
  }
  void showScreen3At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 3", TFT_CYAN, x_offset, y_offset, BG3);
  }
  void showScreen4At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 4", TFT_ORANGE, x_offset, y_offset, BG4);
  }
  void showScreen5At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 5", TFT_GREEN, x_offset, y_offset, BG5);
  }
  void showScreen6At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 6", TFT_MAGENTA, x_offset, y_offset, BG6);
  }
  void showScreen7At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 7", TFT_BLUE, x_offset, y_offset, BG7);
  }
  void showScreen8At(DisplayModule &display, int x_offset, int y_offset) {
    drawHello(display, "Hello 8", TFT_RED, x_offset, y_offset, BG8);
  }

  // Animation cực nhanh, steps ít, mỗi bước delay cực nhỏ
  void slideAnimation(DisplayModule &display, int from, int to, const char* direction, int duration = 1) {
    const int w = display.tft.width();
    const int h = display.tft.height();
    const int steps = 6; // Càng ít càng nhanh (6 bước)
    int x_dir = 0, y_dir = 0;
    if (strcmp(direction, "left") == 0) x_dir = -1;
    else if (strcmp(direction, "right") == 0) x_dir = 1;
    else if (strcmp(direction, "up") == 0) y_dir = -1;
    else if (strcmp(direction, "down") == 0) y_dir = 1;

    for (int i = 0; i <= steps; ++i) {
      int x_ofs = (w * i * x_dir) / steps;
      int y_ofs = (h * i * y_dir) / steps;
      if(i < steps)
        drawScreenByIndex(display, from, x_ofs, y_ofs);
      else
        drawScreenByIndex(display, to, 0, 0);
      delay(duration); // 1ms mỗi bước, tổng ~6-7ms
    }
  }

  void drawScreenByIndex(DisplayModule &display, int idx, int x_offset, int y_offset) {
    switch(idx) {
      case 1: showScreen1At(display, x_offset, y_offset); break;
      case 2: showScreen2At(display, x_offset, y_offset); break;
      case 3: showScreen3At(display, x_offset, y_offset); break;
      case 4: showScreen4At(display, x_offset, y_offset); break;
      case 5: showScreen5At(display, x_offset, y_offset); break;
      case 6: showScreen6At(display, x_offset, y_offset); break;
      case 7: showScreen7At(display, x_offset, y_offset); break;
      case 8: showScreen8At(display, x_offset, y_offset); break;
      default: break;
    }
  }
};