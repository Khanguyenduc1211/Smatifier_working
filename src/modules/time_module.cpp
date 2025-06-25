#include <lvgl.h>
#include "time_module.h"
#include <WiFi.h>
#include <stdio.h>

#define TIMEZONE_OFFSET  (7 * 3600) // GMT+7 cho Việt Nam
#define NTP_SERVER       "pool.ntp.org"
static void time_start_periodic_ntp_update();
static bool time_synced = false;
static lv_obj_t *clock_label = NULL;
static lv_timer_t *clock_timer = NULL;
static lv_timer_t *ntp_update_timer = NULL;

// Hàm đồng bộ NTP
void time_sync_ntp(void) {
    configTime(TIMEZONE_OFFSET, 0, NTP_SERVER);
    int retry = 0;
    time_t now = 0;
    while ((now = time(NULL)) < 100000 && retry < 30) {
        delay(500);
        retry++;
    }
    time_synced = (now >= 100000);
}

// Lấy giờ hệ thống
void time_get_local(struct tm* t) {
    time_t now = time(NULL);
    localtime_r(&now, t);
}

bool time_is_synced(void) {
    return time_synced;
}

// Callback khi wifi vừa kết nối lại
void time_on_wifi_connected(void) {
    if (WiFi.status() == WL_CONNECTED) {
        time_sync_ntp();
        time_synced = false; // Đánh dấu lại, sẽ cập nhật sau khi sync xong
        // Đảm bảo luôn có timer cập nhật NTP định kỳ
        time_start_periodic_ntp_update();
    }
}

// Callback timer cập nhật NTP định kỳ mỗi 2 tiếng
static void ntp_update_timer_cb(lv_timer_t *timer) {
    if (WiFi.status() == WL_CONNECTED) {
        time_sync_ntp();
    }
}

// Khởi tạo timer cập nhật NTP định kỳ
void time_start_periodic_ntp_update() {
    if (!ntp_update_timer) {
        // 2 tiếng = 7200000 ms
        ntp_update_timer = lv_timer_create(ntp_update_timer_cb, 120000, NULL);
    }
}

// Sửa hàm này để nháy nháy dấu :
static void update_label_cb(lv_timer_t * timer) {
    static bool blink = false;
    if (!clock_label) return;
    struct tm t;
    time_get_local(&t);
    char buf[6];
    if (blink)
        snprintf(buf, sizeof(buf), "%02d %02d", t.tm_hour, t.tm_min); // Ẩn :
    else
        snprintf(buf, sizeof(buf), "%02d:%02d", t.tm_hour, t.tm_min); // Hiện :
    lv_label_set_text(clock_label, buf);
    blink = !blink;
}

void time_init_clock_label(lv_obj_t *label) {
    clock_label = label;
    if (!clock_timer)
        clock_timer = lv_timer_create(update_label_cb, 1000, NULL);
    time_start_periodic_ntp_update(); // đảm bảo luôn có timer cập nhật NTP định kỳ
}

void get_current_time_str(char* buf, int len) {
    struct tm t;
    time_get_local(&t);
    snprintf(buf, len, "%02d:%02d", t.tm_hour, t.tm_min);
}