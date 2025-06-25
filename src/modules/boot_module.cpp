#include "display_module.h"
#include "ui_module.h"
#include "gesture_module.h"
#include "swipe_module.h"
#include "touch_module.h"
#include "wifi_module.h"
#include "time_module.h"
#include "ble_module.h"
#include "include/hardware_config.h"
#include "brightness_module.h"    // <-- Bổ sung include này
#include <lvgl.h>
#include <Wire.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "time_module.h"
#include <stdio.h>
// Các biến toàn cục (đã định nghĩa ở file khác, chỉ extern nếu dùng ở nơi khác)
extern DisplayModule display;
extern UIModule ui;
extern GestureModule gesture;
extern TouchModule touch;
extern int currentScreen;
extern SwipeModule swipe;

// LVGL buffer và driver
static lv_color_t buf1[SCREEN_SIZE * 40];
static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;

// 1. Tick timer cho LVGL
static TimerHandle_t lvgl_tick_timer = NULL;
static void lvgl_tick_cb(TimerHandle_t xTimer) {
    lv_tick_inc(1);
}

// 2. Task LVGL
static TaskHandle_t lvglTaskHandle = NULL;
static void lvgl_task(void *pvParameters) {
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

static void lvgl_setup() {
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, SCREEN_SIZE * 40);
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = SCREEN_SIZE;
    disp_drv.ver_res = SCREEN_SIZE;
    disp_drv.flush_cb = DisplayModule::my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
}

void boot_system() {
    Serial.begin(115200);

    // Khởi tạo màn hình trước
    display.begin();

    // Khởi tạo độ sáng màn hình (nếu cần)
    BrightnessModule::init();

    // Khởi tạo WiFi
    wifi_init();
    wifi_connect();
    if (wifi_is_connected()) {
        Serial.println("WiFi connected!");
        time_sync_ntp();
        if (time_is_synced())
            Serial.println("Time synced by NTP!");
        else
            Serial.println("NTP sync failed, using MCU time.");
    } else {
        Serial.println("WiFi failed to connect!");
    }

    // Khởi tạo BLE
    ble_init();

    // Khởi tạo LVGL + driver
    lvgl_setup();

    // Tạo timer tick cho LVGL (1ms)
    if (lvgl_tick_timer == NULL) {
        lvgl_tick_timer = xTimerCreate("lvgl_tick", pdMS_TO_TICKS(1), pdTRUE, NULL, lvgl_tick_cb);
        xTimerStart(lvgl_tick_timer, 0);
    }

    // Tạo task LVGL (5ms)
    if (lvglTaskHandle == NULL) {
        xTaskCreate(lvgl_task, "LVGL", 4096, NULL, 2, &lvglTaskHandle);
    }

    // Khởi tạo cảm ứng
    touch.begin();

    // Khởi tạo UI (từ SquareLine)
    ui_init();

    // Hiện màn hình đầu tiên
    ui.drawScreenByIndex(currentScreen);
}