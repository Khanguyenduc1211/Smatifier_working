#include "rtos_module.h"
#include "wifi_module.h"
#include "ble_module.h"
#include <lvgl.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Định nghĩa các handle task
TaskHandle_t lvglTaskHandle = NULL;
TaskHandle_t wifiTaskHandle = NULL;
TaskHandle_t bleTaskHandle  = NULL;
TaskHandle_t lvglTickTaskHandle = NULL;

// ======= LVGL/UI TASK =======
void lvgl_task(void* pvParameters) {
    for (;;) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

// ======= WIFI TASK =======
void wifi_task(void* pvParameters) {
    for (;;) {
        wifi_update();
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

// ======= BLE TASK =======
void ble_task(void* pvParameters) {
    for (;;) {
        ble_update();
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

// ======= LVGL TICK TASK (1ms) =======
void lv_tick_task(void *arg) {
    while(1) {
        lv_tick_inc(1); // Tick mỗi 1ms cho animation mượt nhất
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

void rtos_tasks_create() {
    // Tạo task tick cho LVGL (chỉ tạo 1 lần duy nhất)
    if (lvglTickTaskHandle == NULL) {
        xTaskCreate(lv_tick_task, "LVGL Tick", 1024, NULL, 4, &lvglTickTaskHandle);
    }
    xTaskCreate(lvgl_task, "LVGL", 4096, NULL, 3, &lvglTaskHandle);
    xTaskCreate(wifi_task, "WiFi", 4096, NULL, 2, &wifiTaskHandle);
    xTaskCreate(ble_task , "BLE",  4096, NULL, 2, &bleTaskHandle);
}

void rtos_tasks_delete() {
    if (lvglTaskHandle)  { vTaskDelete(lvglTaskHandle);  lvglTaskHandle = NULL; }
    if (wifiTaskHandle)  { vTaskDelete(wifiTaskHandle);  wifiTaskHandle = NULL; }
    if (bleTaskHandle)   { vTaskDelete(bleTaskHandle);   bleTaskHandle = NULL; }
    if (lvglTickTaskHandle) { vTaskDelete(lvglTickTaskHandle); lvglTickTaskHandle = NULL; }
}