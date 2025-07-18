#ifndef LV_CONF_H
#define LV_CONF_H

/*====================
   COLOR SETTINGS
 *====================*/
#define LV_COLOR_DEPTH          16
#define LV_COLOR_16_SWAP        0

/*====================
   DISPLAY SETTINGS
 *====================*/
#define LV_HOR_RES_MAX          240
#define LV_VER_RES_MAX          240

/*====================
   MEMORY SETTINGS
 *====================*/
#define LV_MEM_SIZE             (48U * 1024U)   // [bytes] 48KB cho giao diện animation mượt hơn

/*====================
   FEATURE SET
 *====================*/
#define LV_USE_LOG              0
#define LV_USE_ASSERT_NULL      1
#define LV_USE_GPU              0
#define LV_USE_PERF_MONITOR     0
#define LV_USE_MEM_MONITOR      0

/*====================
   MISC SETTINGS
 *====================*/
#define LV_TICK_CUSTOM          0   // SỬA LẠI: Để LVGL tự dùng tick mặc định (KHÔNG tự gọi lv_tick_inc() ngoài code nữa)

#endif // LV_CONF_H