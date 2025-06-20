#pragma once

#include <LovyanGFX.hpp>

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
  LGFX(void) {
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
};

class DisplayModule {
public:
  LGFX tft;

  void begin() {
    tft.begin();
    tft.setRotation(0);
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
  }

  void showScanning() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setFont(&fonts::Font0);
    tft.setCursor(10, 110);
    tft.print("Dang scan BLE...");
  }

  void displayDevices(const String deviceName[], int deviceCount, int maxDevices = 5) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(middle_left);
    tft.setFont(&fonts::Font0);

    int y0 = 35;
    int line_h = 30;
    tft.setCursor(10, 2);
    tft.print("DANH SACH BLE:");

    for (int i = 0; i < maxDevices; i++) {
      tft.setCursor(10, y0 + i * line_h);
      if (i < deviceCount)
        tft.print(String(i + 1) + ". " + deviceName[i]);
      else
        tft.print(" ");
    }
  }
};