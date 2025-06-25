#include "swipe_module.h"
#include "ui_module.h"
#include "gesture_module.h"
#include "touch_module.h"
#include "lvgl.h"

// Hàm mapping hướng swipe theo bảng đã khai báo trong UIModule
static int getNextScreen(int cur, uint8_t swipeG) {
    // gestureID: 1=Down, 2=Up, 3=Left, 4=Right
    switch (swipeG) {
        case 1: // Down
            switch(cur) {
                case UI_SCREEN_WIFI:         return SCREEN_SETTINGSCREENTIME;
                case UI_SCREEN_WIFI2:        return cur; // không chuyển
                case UI_SCREEN_WIFI3:        return cur; // không chuyển
                case UI_SCREEN_BRIGHTNESS:   return UI_SCREEN_WIFI;
                case UI_SCREEN_NOTIFICATION: return cur; // giữ nguyên
                case UI_SCREEN_HOME:         return UI_SCREEN_BRIGHTNESS;
                case UI_SCREEN_NAVIGATION:   return cur; // giữ nguyên
                case UI_SCREEN_BLE1:         return UI_SCREEN_HOME;
                case UI_SCREEN_BLE2:         return cur; // không chuyển
                case SCREEN_SETTINGSCREENTIME: return UI_SCREEN_BLE1;
                default:                     return cur;
            }
        case 2: // Up
            switch(cur) {
                case UI_SCREEN_WIFI:         return UI_SCREEN_BRIGHTNESS;
                case UI_SCREEN_WIFI2:        return cur; // không chuyển
                case UI_SCREEN_WIFI3:        return cur; // không chuyển
                case UI_SCREEN_BRIGHTNESS:   return UI_SCREEN_HOME;
                case UI_SCREEN_NOTIFICATION: return cur; // giữ nguyên
                case UI_SCREEN_HOME:         return UI_SCREEN_BLE1;
                case UI_SCREEN_NAVIGATION:   return cur; // giữ nguyên
                case UI_SCREEN_BLE1:         return SCREEN_SETTINGSCREENTIME;
                case UI_SCREEN_BLE2:         return cur; // không chuyển
                case SCREEN_SETTINGSCREENTIME: return UI_SCREEN_WIFI;
                default:                     return cur;
            }
        case 3: // Left
            switch(cur) {
                case UI_SCREEN_WIFI:         return UI_SCREEN_WIFI2;
                case UI_SCREEN_WIFI2:        return UI_SCREEN_WIFI3;
                case UI_SCREEN_WIFI3:        return UI_SCREEN_WIFI;
                case UI_SCREEN_BRIGHTNESS:   return cur; // giữ nguyên
                case UI_SCREEN_NOTIFICATION: return UI_SCREEN_HOME;
                case UI_SCREEN_HOME:         return UI_SCREEN_NAVIGATION;
                case UI_SCREEN_NAVIGATION:   return UI_SCREEN_NOTIFICATION;
                case UI_SCREEN_BLE1:         return UI_SCREEN_BLE2;
                case UI_SCREEN_BLE2:         return UI_SCREEN_BLE1;
                case SCREEN_SETTINGSCREENTIME: return cur; // không chuyển
                default:                     return cur;
            }
        case 4: // Right
            switch(cur) {
                case UI_SCREEN_WIFI:         return UI_SCREEN_WIFI3;
                case UI_SCREEN_WIFI2:        return UI_SCREEN_WIFI;
                case UI_SCREEN_WIFI3:        return UI_SCREEN_WIFI2;
                case UI_SCREEN_BRIGHTNESS:   return cur; // giữ nguyên
                case UI_SCREEN_NOTIFICATION: return UI_SCREEN_NAVIGATION;
                case UI_SCREEN_HOME:         return UI_SCREEN_NOTIFICATION;
                case UI_SCREEN_NAVIGATION:   return UI_SCREEN_HOME;
                case UI_SCREEN_BLE1:         return UI_SCREEN_BLE2;
                case UI_SCREEN_BLE2:         return UI_SCREEN_BLE1;
                case SCREEN_SETTINGSCREENTIME: return cur; // không chuyển
                default:                     return cur;
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

    // Swipe
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
    } else if (swipeG == 0x0C && cur != UI_SCREEN_HOME) { // Long Press về HOME
        next = UI_SCREEN_HOME;
        anim = LV_SCR_LOAD_ANIM_FADE_ON;
    }

    if (next != cur) {
        ui->drawScreenByIndex(next, anim);
        *currentScreen = next;
        delay(40); // Đảm bảo hiệu ứng animation hiển thị
    }
}