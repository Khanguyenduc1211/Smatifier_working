#include "swipe_module.h"
#include "ui_module.h"
#include "gesture_module.h"
#include "touch_module.h"
#include "brightness_module.h"
#include "lvgl.h"

// Hàm mapping hướng swipe theo bảng đã khai báo trong UIModule
static int getNextScreen(int cur, uint8_t swipeG) {
    // gestureID: 1=Down, 2=Up, 3=Left, 4=Right
    switch (swipeG) {
        case 1: // Down
            switch(cur) {
                case SCREEN_SETTINGWIFI:         return SCREEN_SETTINGSCREENTIME;
                case SCREEN_SETTINGWIFI2:        return cur; // không chuyển
                case SCREEN_SETTINGWIFI3:        return cur; // không chuyển
                case SCREEN_BRIGHTNESS:          return SCREEN_SETTINGWIFI;
                case SCREEN_NOTIFICATION:        return cur; // giữ nguyên
                case SCREEN_HOME1:               return SCREEN_BRIGHTNESS;
                case SCREEN_NAVIGATION:          return cur; // giữ nguyên
                case SCREEN_SETTINGBLE1:         return SCREEN_HOME1;
                case SCREEN_SETTINGBLE2:         return cur; // không chuyển
                case SCREEN_SETTINGSCREENTIME:   return SCREEN_SETTINGBLE1;
                default:                         return cur;
            }
        case 2: // Up
            switch(cur) {
                case SCREEN_SETTINGWIFI:         return SCREEN_BRIGHTNESS;
                case SCREEN_SETTINGWIFI2:        return cur; // không chuyển
                case SCREEN_SETTINGWIFI3:        return cur; // không chuyển
                case SCREEN_BRIGHTNESS:          return SCREEN_HOME1;
                case SCREEN_NOTIFICATION:        return cur; // giữ nguyên
                case SCREEN_HOME1:               return SCREEN_SETTINGBLE1;
                case SCREEN_NAVIGATION:          return cur; // giữ nguyên
                case SCREEN_SETTINGBLE1:         return SCREEN_SETTINGSCREENTIME;
                case SCREEN_SETTINGBLE2:         return cur; // không chuyển
                case SCREEN_SETTINGSCREENTIME:   return SCREEN_SETTINGWIFI;
                default:                         return cur;
            }
        case 3: // Left
            switch(cur) {
                case SCREEN_SETTINGWIFI:         return SCREEN_SETTINGWIFI2;
                case SCREEN_SETTINGWIFI2:        return SCREEN_SETTINGWIFI3;
                case SCREEN_SETTINGWIFI3:        return SCREEN_SETTINGWIFI;
                case SCREEN_BRIGHTNESS:          return cur; // giữ nguyên
                case SCREEN_NOTIFICATION:        return SCREEN_HOME1;
                case SCREEN_HOME1:               return SCREEN_NAVIGATION;
                case SCREEN_NAVIGATION:          return SCREEN_NOTIFICATION;
                case SCREEN_SETTINGBLE1:         return SCREEN_SETTINGBLE2;
                case SCREEN_SETTINGBLE2:         return SCREEN_SETTINGBLE1;
                case SCREEN_SETTINGSCREENTIME:   return cur; // không chuyển
                default:                         return cur;
            }
        case 4: // Right
            switch(cur) {
                case SCREEN_SETTINGWIFI:         return SCREEN_SETTINGWIFI3;
                case SCREEN_SETTINGWIFI2:        return SCREEN_SETTINGWIFI;
                case SCREEN_SETTINGWIFI3:        return SCREEN_SETTINGWIFI2;
                case SCREEN_BRIGHTNESS:          return cur; // giữ nguyên
                case SCREEN_NOTIFICATION:        return SCREEN_NAVIGATION;
                case SCREEN_HOME1:               return SCREEN_NOTIFICATION;
                case SCREEN_NAVIGATION:          return SCREEN_HOME1;
                case SCREEN_SETTINGBLE1:         return SCREEN_SETTINGBLE2;
                case SCREEN_SETTINGBLE2:         return SCREEN_SETTINGBLE1;
                case SCREEN_SETTINGSCREENTIME:   return cur; // không chuyển
                default:                         return cur;
            }
        default: return cur;
    }
}

SwipeModule::SwipeModule(
    int* pCurrentScreen,
    DisplayModule* pDisplay,
    UIModule* pUi,
    GestureModule* pGesture,
    TouchModule* pTouch
) : currentScreen(pCurrentScreen),
    display(pDisplay),
    ui(pUi),
    gesture(pGesture),
    touch(pTouch)
{}

void SwipeModule::handleSwipe() {
    uint8_t swipeG = gesture->getGesture(touch->getCST816S());
    int cur = *currentScreen;
    int next = cur;
    lv_scr_load_anim_t anim = LV_SCR_LOAD_ANIM_NONE;

    // Tăng/giảm độ sáng ở màn hình brightness
    if (cur == SCREEN_BRIGHTNESS) {
        if (swipeG == 3) { // Left: giảm độ sáng
            BrightnessModule::decrease(10); // mỗi lần giảm 10%
            // (Tuỳ chọn) cập nhật UI slider hoặc số % ở đây
            return;
        }
        if (swipeG == 4) { // Right: tăng độ sáng
            BrightnessModule::increase(10); // mỗi lần tăng 10%
            // (Tuỳ chọn) cập nhật UI slider hoặc số % ở đây
            return;
        }
    }

    // Phần còn lại xử lý chuyển màn hình như cũ
    if (swipeG == 1) { // Down
        next = getNextScreen(cur, swipeG);
        anim = LV_SCR_LOAD_ANIM_MOVE_BOTTOM;
    } else if (swipeG == 2) { // Up
        next = getNextScreen(cur, swipeG);
        anim = LV_SCR_LOAD_ANIM_MOVE_TOP;
    } else if (swipeG == 3) { // Left
        next = getNextScreen(cur, swipeG);
        anim = LV_SCR_LOAD_ANIM_MOVE_LEFT;
    } else if (swipeG == 4) { // Right
        next = getNextScreen(cur, swipeG);
        anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
    } else if (swipeG == 0x0C && cur != SCREEN_HOME1) { // Long Press về HOME
        next = SCREEN_HOME1;
        anim = LV_SCR_LOAD_ANIM_FADE_ON;
    }

    if (next != cur) {
        ui->drawScreenByIndex(next, anim);
        *currentScreen = next;
        delay(40); // Đảm bảo hiệu ứng animation hiển thị
    }
}