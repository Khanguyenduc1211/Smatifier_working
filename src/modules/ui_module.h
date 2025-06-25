#pragma once

#include "../ui/ui.h"
#include <lvgl.h>

enum UIScreenIndex {
    UI_SCREEN_HOME = 1,
    UI_SCREEN_BRIGHTNESS = 2,
    UI_SCREEN_NOTIFICATION = 3,
    UI_SCREEN_NAVIGATION = 4,
    UI_SCREEN_SCREENTIME = 5,
    UI_SCREEN_WIFI = 6,
    UI_SCREEN_WIFI2 = 7,
    UI_SCREEN_WIFI3 = 8,
    UI_SCREEN_BLE1 = 9,
    UI_SCREEN_BLE2 = 10,
};

class UIModule {
public:
    static UIModule& instance();
    void drawScreenByIndex(int idx, lv_scr_load_anim_t animDir = LV_SCR_LOAD_ANIM_FADE_ON);
    int getCurrentScreen() const { return currentScreen; }
private:
    int currentScreen = UI_SCREEN_HOME;
};