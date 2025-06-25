#pragma once
#include <Arduino.h>

// Extern các task handle
extern TaskHandle_t lvglTaskHandle;
extern TaskHandle_t wifiTaskHandle;
extern TaskHandle_t bleTaskHandle;

// Khởi tạo các task RTOS
void rtos_tasks_create();
void rtos_tasks_delete();