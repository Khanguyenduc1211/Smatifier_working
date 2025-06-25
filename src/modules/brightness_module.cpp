#include "brightness_module.h"
#include "hardware_config.h"

// Khởi tạo giá trị mặc định
uint8_t BrightnessModule::brightness_percent = 100;

// Hàm này cần thay thế để điều khiển PWM/backlight thực tế của bạn
void BrightnessModule::apply(uint8_t percent) {
    // Ví dụ giả lập: Gửi tín hiệu PWM tới chân TFT_BL
    // pwm_set_duty(TFT_BL, percent);
    // TODO: Thay bằng hàm thực tế của bạn
}

void BrightnessModule::init() {
    // TODO: Nếu cần khởi tạo PWM cho TFT_BL thì thêm code ở đây
    set(brightness_percent);
}

void BrightnessModule::set(uint8_t percent) {
    if (percent > 100) percent = 100;
    brightness_percent = percent;
    apply(brightness_percent);
}

void BrightnessModule::increase(uint8_t step) {
    if (brightness_percent + step > 100)
        brightness_percent = 100;
    else
        brightness_percent += step;
    apply(brightness_percent);
}

void BrightnessModule::decrease(uint8_t step) {
    if (brightness_percent < step)
        brightness_percent = 0;
    else
        brightness_percent -= step;
    apply(brightness_percent);
}

uint8_t BrightnessModule::get() {
    return brightness_percent;
}