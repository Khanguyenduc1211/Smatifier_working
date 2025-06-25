#pragma once

#include "display_module.h"
#include "ui_module.h"
#include "gesture_module.h"
#include "touch_module.h"

// Enum mapping theo sơ đồ của bạn
#define SCREEN_HOME1           1
#define SCREEN_NAVIGATION      4
#define SCREEN_NOTIFICATION    3
#define SCREEN_SETTINGWIFI     6
#define SCREEN_SETTINGWIFI2    7
#define SCREEN_SETTINGWIFI3    8
#define SCREEN_BRIGHTNESS      2
#define SCREEN_SETTINGBLE1     9
#define SCREEN_SETTINGBLE2     10
#define SCREEN_SETTINGSCREENTIME 5

class SwipeModule {
public:
    SwipeModule(
        int* pCurrentScreen,
        DisplayModule* pDisplay,
        UIModule* pUi,
        GestureModule* pGesture,
        TouchModule* pTouch
    );
    void handleSwipe();

private:
    int* currentScreen;
    DisplayModule* display;
    UIModule* ui;
    GestureModule* gesture;
    TouchModule* touch;
};