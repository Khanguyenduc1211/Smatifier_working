#pragma once

#include <CST816S.h>

// Module này chỉ nhận diện gesture (vuốt/cử chỉ), không xử lý tap, double tap, triple tap hoặc long press.
// Bạn phải tạo đối tượng CST816S touch(TOUCH_SDA, TOUCH_SCL, TOUCH_RST, TOUCH_INT); ở file main.cpp và gọi touch.begin() trước khi sử dụng module này.

class GestureModule {
public:
    // Giá trị trả về cho swipe:
    // 1: Swipe Down, 2: Swipe Up, 3: Swipe Left, 4: Swipe Right
    // 5: Single Tap
    // 0 hoặc giá trị khác: Không có gesture mới

    // Hàm này nên được gọi mỗi vòng lặp, chỉ trả về gestureID khác 0 nếu vừa có cử chỉ mới
    uint8_t getGesture(CST816S &touch) {
        static uint8_t last_gesture = 0;

        if (touch.available()) {
            uint8_t g = touch.data.gestureID;
            if (g != 0 && g != last_gesture) {
                last_gesture = g;
                // Chỉ trả về các gesture swipe và single tap
                if (g >= 1 && g <= 5) {
                    return g;
                }
            }
        } else {
            last_gesture = 0;
        }
        return 0;
    }

    // Trả về chuỗi mô tả tên gesture
    const char* gestureString(uint8_t gesture) {
        switch (gesture) {
            case 1: return "Swipe Up";
            case 2: return "Swipe Down";
            case 3: return "Swipe Left";
            case 4: return "Swipe Right";
            case 5: return "Single Tap";
            default: return nullptr;
        }
    }
};