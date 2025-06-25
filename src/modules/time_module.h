#ifndef TIME_MODULE_H
#define TIME_MODULE_H

#include <lvgl.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

void get_current_time_str(char* buf, int len);
void time_sync_ntp(void);
bool time_is_synced(void);
void time_init_clock_label(lv_obj_t *label);
void time_get_local(struct tm* t); // <- thêm dòng này!

#ifdef __cplusplus
}
#endif

#endif // TIME_MODULE_H