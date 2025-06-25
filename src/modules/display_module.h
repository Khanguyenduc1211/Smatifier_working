#pragma once
#include <lvgl.h> 
#include <LovyanGFX.hpp>

// Định nghĩa các chân kết nối LCD
#define TFT_MOSI 7
#define TFT_MISO -1
#define TFT_CLK  6
#define TFT_CS   10
#define TFT_DC   2
#define TFT_RST  -1
#define TFT_BL   3
#define SCREEN_SIZE 240

class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_GC9A01 _panel_instance;
  lgfx::Bus_SPI _bus_instance;
public:
  LGFX(void);
};

class DisplayModule {
public:
  LGFX tft;

  void begin();
  // Hàm hỗ trợ LVGL
  static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
};