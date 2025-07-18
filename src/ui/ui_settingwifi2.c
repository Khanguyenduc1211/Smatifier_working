// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.3
// LVGL version: 8.3.11
// Project name: Project

#include "ui.h"

lv_obj_t *uic_connectstatus;
lv_obj_t *uic_resetbluetooth;
lv_obj_t *uic_iconwifi;
lv_obj_t *uic_selectssid;
lv_obj_t *uic_ssid_5;
lv_obj_t *uic_ssid_4;
lv_obj_t *uic_ssid_3;
lv_obj_t *uic_ssid_2;
lv_obj_t *uic_ssid_1;
lv_obj_t *uic_settingwifi2;
lv_obj_t *ui_settingwifi2 = NULL;lv_obj_t *ui_ssid_1 = NULL;lv_obj_t *ui_ssid_2 = NULL;lv_obj_t *ui_ssid_3 = NULL;lv_obj_t *ui_ssid_4 = NULL;lv_obj_t *ui_ssid_5 = NULL;lv_obj_t *ui_selectssid = NULL;lv_obj_t *ui_iconwifi = NULL;lv_obj_t *ui_iconwificonnect = NULL;lv_obj_t *ui_resetbluetooth = NULL;lv_obj_t *ui_bleconnectstatussmall = NULL;lv_obj_t *ui_bleconnectsucess = NULL;lv_obj_t *ui_settingmask4 = NULL;
// event funtions

// build funtions

void ui_settingwifi2_screen_init(void)
{
ui_settingwifi2 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_settingwifi2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_settingwifi2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_settingwifi2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ssid_1 = lv_label_create(ui_settingwifi2);
lv_obj_set_width( ui_ssid_1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ssid_1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ssid_1, -5 );
lv_obj_set_y( ui_ssid_1, 0 );
lv_obj_set_align( ui_ssid_1, LV_ALIGN_CENTER );
lv_label_set_text(ui_ssid_1,"Bun thit nuong");
lv_obj_set_style_text_color(ui_ssid_1, lv_color_hex(0xF4E7E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ssid_1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_ssid_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_ssid_1, &ui_font_SVNAvo16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ssid_2 = lv_label_create(ui_settingwifi2);
lv_obj_set_width( ui_ssid_2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ssid_2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ssid_2, -5 );
lv_obj_set_y( ui_ssid_2, 24 );
lv_obj_set_align( ui_ssid_2, LV_ALIGN_CENTER );
lv_label_set_text(ui_ssid_2,"Wifi free");
lv_obj_set_style_text_color(ui_ssid_2, lv_color_hex(0xF4E7E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ssid_2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_ssid_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_ssid_2, &ui_font_SVNAvo16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ssid_3 = lv_label_create(ui_settingwifi2);
lv_obj_set_width( ui_ssid_3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ssid_3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ssid_3, -5 );
lv_obj_set_y( ui_ssid_3, 48 );
lv_obj_set_align( ui_ssid_3, LV_ALIGN_CENTER );
lv_label_set_text(ui_ssid_3,"Ca phe den");
lv_obj_set_style_text_color(ui_ssid_3, lv_color_hex(0xF4E7E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ssid_3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_ssid_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_ssid_3, &ui_font_SVNAvo16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ssid_4 = lv_label_create(ui_settingwifi2);
lv_obj_set_width( ui_ssid_4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ssid_4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ssid_4, -5 );
lv_obj_set_y( ui_ssid_4, -24 );
lv_obj_set_align( ui_ssid_4, LV_ALIGN_CENTER );
lv_label_set_text(ui_ssid_4,"Ca phe den");
lv_obj_set_style_text_color(ui_ssid_4, lv_color_hex(0xF4E7E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ssid_4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_ssid_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_ssid_4, &ui_font_SVNAvo16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ssid_5 = lv_label_create(ui_settingwifi2);
lv_obj_set_width( ui_ssid_5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ssid_5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ssid_5, -5 );
lv_obj_set_y( ui_ssid_5, -48 );
lv_obj_set_align( ui_ssid_5, LV_ALIGN_CENTER );
lv_label_set_text(ui_ssid_5,"Viettel_5G");
lv_obj_set_style_text_color(ui_ssid_5, lv_color_hex(0xF4E7E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ssid_5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_ssid_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_ssid_5, &ui_font_SVNAvo16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_selectssid = lv_label_create(ui_settingwifi2);
lv_obj_set_width( ui_selectssid, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_selectssid, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_selectssid, -5 );
lv_obj_set_y( ui_selectssid, 0 );
lv_obj_set_align( ui_selectssid, LV_ALIGN_CENTER );
lv_label_set_text(ui_selectssid,"Bun thit nuong");
lv_obj_set_style_text_color(ui_selectssid, lv_color_hex(0xFF9B45), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_selectssid, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_selectssid, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_selectssid, &ui_font_SVNAvo16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_iconwifi = lv_img_create(ui_settingwifi2);
lv_img_set_src(ui_iconwifi, &ui_img_iconwifi_small_png);
lv_obj_set_width( ui_iconwifi, LV_SIZE_CONTENT);  /// 20
lv_obj_set_height( ui_iconwifi, LV_SIZE_CONTENT);   /// 15
lv_obj_set_x( ui_iconwifi, 0 );
lv_obj_set_y( ui_iconwifi, -90 );
lv_obj_set_align( ui_iconwifi, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_iconwifi, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_iconwifi, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_iconwificonnect = lv_img_create(ui_iconwifi);
lv_img_set_src(ui_iconwificonnect, &ui_img_iconwifi_connect_small_png);
lv_obj_set_width( ui_iconwificonnect, LV_SIZE_CONTENT);  /// 20
lv_obj_set_height( ui_iconwificonnect, LV_SIZE_CONTENT);   /// 15
lv_obj_set_align( ui_iconwificonnect, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_iconwificonnect, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_iconwificonnect, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_resetbluetooth = lv_img_create(ui_settingwifi2);
lv_img_set_src(ui_resetbluetooth, &ui_img_ngocnhonlen_png);
lv_obj_set_width( ui_resetbluetooth, LV_SIZE_CONTENT);  /// 6
lv_obj_set_height( ui_resetbluetooth, LV_SIZE_CONTENT);   /// 6
lv_obj_set_x( ui_resetbluetooth, 0 );
lv_obj_set_y( ui_resetbluetooth, 90 );
lv_obj_set_align( ui_resetbluetooth, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_resetbluetooth, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_resetbluetooth, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_bleconnectstatussmall = lv_img_create(ui_settingwifi2);
lv_img_set_src(ui_bleconnectstatussmall, &ui_img_loading_png);
lv_obj_set_width( ui_bleconnectstatussmall, LV_SIZE_CONTENT);  /// 16
lv_obj_set_height( ui_bleconnectstatussmall, LV_SIZE_CONTENT);   /// 16
lv_obj_set_x( ui_bleconnectstatussmall, -75 );
lv_obj_set_y( ui_bleconnectstatussmall, 0 );
lv_obj_set_align( ui_bleconnectstatussmall, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_bleconnectstatussmall, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_bleconnectstatussmall, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_bleconnectsucess = lv_img_create(ui_bleconnectstatussmall);
lv_img_set_src(ui_bleconnectsucess, &ui_img_connect_success_small_png);
lv_obj_set_width( ui_bleconnectsucess, LV_SIZE_CONTENT);  /// 15
lv_obj_set_height( ui_bleconnectsucess, LV_SIZE_CONTENT);   /// 15
lv_obj_set_x( ui_bleconnectsucess, 0 );
lv_obj_set_y( ui_bleconnectsucess, -1 );
lv_obj_set_align( ui_bleconnectsucess, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_bleconnectsucess, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_bleconnectsucess, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_settingmask4 = lv_img_create(ui_settingwifi2);
lv_img_set_src(ui_settingmask4, &ui_img_setting_mask_png);
lv_obj_set_width( ui_settingmask4, LV_SIZE_CONTENT);  /// 241
lv_obj_set_height( ui_settingmask4, LV_SIZE_CONTENT);   /// 241
lv_obj_set_align( ui_settingmask4, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_settingmask4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_settingmask4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

uic_settingwifi2 = ui_settingwifi2;
uic_ssid_1 = ui_ssid_1;
uic_ssid_2 = ui_ssid_2;
uic_ssid_3 = ui_ssid_3;
uic_ssid_4 = ui_ssid_4;
uic_ssid_5 = ui_ssid_5;
uic_selectssid = ui_selectssid;
uic_iconwifi = ui_iconwifi;
uic_resetbluetooth = ui_resetbluetooth;
uic_connectstatus = ui_bleconnectstatussmall;

}

void ui_settingwifi2_screen_destroy(void)
{
   if (ui_settingwifi2) lv_obj_del(ui_settingwifi2);

// NULL screen variables
uic_settingwifi2= NULL;
ui_settingwifi2= NULL;
uic_ssid_1= NULL;
ui_ssid_1= NULL;
uic_ssid_2= NULL;
ui_ssid_2= NULL;
uic_ssid_3= NULL;
ui_ssid_3= NULL;
uic_ssid_4= NULL;
ui_ssid_4= NULL;
uic_ssid_5= NULL;
ui_ssid_5= NULL;
uic_selectssid= NULL;
ui_selectssid= NULL;
uic_iconwifi= NULL;
ui_iconwifi= NULL;
ui_iconwificonnect= NULL;
uic_resetbluetooth= NULL;
ui_resetbluetooth= NULL;
uic_connectstatus= NULL;
ui_bleconnectstatussmall= NULL;
ui_bleconnectsucess= NULL;
ui_settingmask4= NULL;

}

void ui_settingwifi2_screen_relocalize(void)
{
// label widgets on screen

}
