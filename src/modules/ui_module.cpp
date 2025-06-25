#include "ui_module.h"
#include <lvgl.h>

UIModule& UIModule::instance() {
    static UIModule inst;
    return inst;
}

void UIModule::drawScreenByIndex(int idx, lv_scr_load_anim_t animDir) {
    lv_obj_t* scr = nullptr;
    switch(idx) {
        case UI_SCREEN_NOTIFICATION:   scr = ui_Notification1; break;
        case UI_SCREEN_HOME:           scr = ui_home; break;
        case UI_SCREEN_NAVIGATION:     scr = ui_Navigation1; break;
        case UI_SCREEN_BRIGHTNESS:     scr = ui_settingbrightness; break;
        case UI_SCREEN_SCREENTIME:     scr = ui_settingscreentime; break;
        case UI_SCREEN_WIFI:           scr = ui_settingwifi; break;
        case UI_SCREEN_WIFI2:          scr = ui_settingwifi2; break;
        case UI_SCREEN_WIFI3:          scr = ui_settingwifi3; break;
        case UI_SCREEN_BLE1:           scr = ui_settingble1; break;
        case UI_SCREEN_BLE2:           scr = ui_settingble2; break;
        default:                       scr = ui_home; animDir = LV_SCR_LOAD_ANIM_FADE_ON; break;
    }
    if(scr) lv_scr_load_anim(scr, animDir, 300, 0, false);
    currentScreen = idx;
}