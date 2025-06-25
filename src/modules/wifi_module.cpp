#include "wifi_module.h"
#include <WiFi.h> // Nếu dùng ESP8266 thì dùng: #include <ESP8266WiFi.h>

typedef struct {
    const char* ssid;
    const char* password;
} wifi_ap_t;

// Danh sách các mạng WiFi ưu tiên
static const wifi_ap_t wifi_list[] = {
    { "Heo Bay - Bún Thịt Nướng",      "99887766" },
    { "Home 2",              "99887766" },
    { "iPhone của Kha", "99887766" }
};

#define WIFI_LIST_SIZE (sizeof(wifi_list)/sizeof(wifi_list[0]))

void wifi_init() {
    WiFi.mode(WIFI_STA);
}

void wifi_connect() {
    for (size_t i = 0; i < WIFI_LIST_SIZE; ++i) {
        WiFi.begin(wifi_list[i].ssid, wifi_list[i].password);

        int retry = 0;
        while (WiFi.status() != WL_CONNECTED && retry < 20) { // ~10 giây
            delay(500);
            retry++;
        }

        if (WiFi.status() == WL_CONNECTED) {
            // Đã kết nối thành công
            break;
        } else {
            WiFi.disconnect(); // Ngắt kết nối nếu không thành công để thử mạng tiếp theo
            delay(500);
        }
    }
}

bool wifi_is_connected() {
    return WiFi.status() == WL_CONNECTED;
}

// Gọi hàm này trong task wifi_task
void wifi_update() {
    if (!wifi_is_connected()) {
        wifi_connect();
    }
}