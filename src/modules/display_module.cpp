#include "display_module.h"
#include <Arduino.h>
#include <lvgl.h>

LGFX::LGFX(void) {
  auto cfg = _bus_instance.config();
  cfg.spi_host = SPI2_HOST;
  cfg.spi_mode = 0;
  cfg.freq_write = 40000000;
  cfg.freq_read = 16000000;
  cfg.spi_3wire = false;
  cfg.use_lock = true;
  cfg.dma_channel = 1;
  cfg.pin_sclk = TFT_CLK;
  cfg.pin_mosi = TFT_MOSI;
  cfg.pin_miso = TFT_MISO;
  cfg.pin_dc   = TFT_DC;
  _bus_instance.config(cfg);
  _panel_instance.setBus(&_bus_instance);

  auto pcfg = _panel_instance.config();
  pcfg.pin_cs = TFT_CS;
  pcfg.pin_rst = TFT_RST;
  _panel_instance.config(pcfg);
  setPanel(&_panel_instance);
}

void DisplayModule::begin() {
  tft.begin();
  tft.invertDisplay(true);
  tft.setRotation(0);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
}

// Hàm flush cho LVGL
void DisplayModule::my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  // Lấy con trỏ đến DisplayModule từ user_data (nếu bạn cần)
  // DisplayModule *instance = static_cast<DisplayModule *>(disp->user_data);

  // Lưu ý: tft là biến toàn cục hoặc singleton, hoặc truyền instance vào user_data nếu quản lý đa màn hình
  extern DisplayModule display; // Đảm bảo biến display toàn cục được khai báo ở ngoài

  display.tft.startWrite();
  display.tft.setAddrWindow(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1);
  display.tft.pushColors((uint16_t *)color_p, (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1), true);
  display.tft.endWrite();
  lv_disp_flush_ready(disp);
}