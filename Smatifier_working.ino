#include "src/modules/globals.h"
#include "src/modules/boot_module.h"
#include "src/modules/rtos_module.h"
#include "include/hardware_config.h"
#include <lvgl.h>
#include <Wire.h>
TouchModule touch(TOUCH_SDA, TOUCH_SCL, TOUCH_RST, TOUCH_INT);
// Khởi tạo duy nhất ở đây!
DisplayModule display;
UIModule ui;
GestureModule gesture;
int currentScreen = 1;
SwipeModule swipe(
    &currentScreen,
    &display,
    &ui,
    &gesture,
    &touch
);

void setup() {
    boot_system();
    rtos_tasks_create();
    Wire.begin(TOUCH_SDA, TOUCH_SCL);
}

void loop() {
    lv_timer_handler(); // PHẢI CÓ
    swipe.handleSwipe();
    delay(5);           // hoặc vTaskDelay(5 / portTICK_PERIOD_MS);
}