#pragma once
#include <cstdint>

class BrightnessModule {
public:
    // Khởi tạo module (gọi ở khởi động hệ thống)
    static void init();

    // Thiết lập độ sáng (%), giá trị từ 0 đến 100
    static void set(uint8_t percent);

    // Tăng độ sáng lên step phần trăm (ví dụ step = 10)
    static void increase(uint8_t step);

    // Giảm độ sáng xuống step phần trăm (ví dụ step = 10)
    static void decrease(uint8_t step);

    // Lấy giá trị độ sáng hiện tại (%)
    static uint8_t get();

private:
    static void apply(uint8_t percent);
    static uint8_t brightness_percent;
};