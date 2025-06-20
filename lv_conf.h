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
#define LV_MEM_SIZE             (32U * 1024U)   // [bytes] Default: 32KB

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
#define LV_TICK_CUSTOM          0

#endif // LV_CONF_H