#pragma once

#include <CST816S.h>

// Nhận diện tap/double/triple/long press dựa vào trạng thái raw (không dùng gestureID của CST816S)

class GestureOtherModule {
public:
    // 5: Single Tap, 6: Double Tap, 7: Long Press, 8: Triple Tap
    // 0: Không có gesture mới

    uint8_t getGesture(CST816S &touch) {
        static bool lastTouching = false;
        static uint32_t lastTouchTime = 0;
        static uint32_t pressStartTime = 0;
        static uint8_t tapCount = 0;
        static bool longPressFired = false;
        static const uint16_t tapWindow = 400;      // ms, thời gian tối đa giữa các lần tap
        static const uint16_t longPressTime = 1000; // ms, thời gian giữ để nhận long press

        // Đọc trạng thái cảm ứng (raw): đang chạm hay không
        bool touching = (touch.data.x > 0 && touch.data.y > 0);

        uint32_t now = millis();

        // Khi bắt đầu chạm
        if (touching && !lastTouching) {
            pressStartTime = now;
            longPressFired = false;
        }
        // Khi đang giữ chạm
        if (touching && !longPressFired && (now - pressStartTime > longPressTime)) {
            longPressFired = true;
            // Reset tap count, không nhận tap sau long press
            tapCount = 0;
            return 7; // Long Press
        }

        // Khi vừa nhả ra khỏi màn hình
        if (!touching && lastTouching) {
            uint32_t pressDuration = now - pressStartTime;
            if (!longPressFired && pressDuration < longPressTime) {
                // Đếm tap (tap nhanh)
                if (now - lastTouchTime < tapWindow) {
                    tapCount++;
                } else {
                    tapCount = 1;
                }
                lastTouchTime = now;

                if (tapCount == 3) {
                    tapCount = 0;
                    return 8; // Triple Tap
                } else if (tapCount == 2) {
                    // Chờ thêm 1 thời gian ngắn để xác định có phải triple tap không
                    // Nếu không có tap nữa trong tapWindow thì sẽ trả về double tap ở dưới
                }
            }
            longPressFired = false; // reset trạng thái long press khi nhả tay
        }

        // Nếu vừa kết thúc chuỗi tap mà không có tap tiếp trong tapWindow, nhận double/single tap
        if (!touching && !lastTouching && tapCount > 0 && (now - lastTouchTime >= tapWindow)) {
            uint8_t ret = 0;
            if (tapCount == 1) ret = 5;        // Single Tap
            else if (tapCount == 2) ret = 6;   // Double Tap
            tapCount = 0;
            return ret;
        }

        lastTouching = touching;
        return 0;
    }

    // Trả về chuỗi mô tả tên gesture
    const char* gestureString(uint8_t gesture) {
        switch(gesture) {
            case 5: return "Single Tap";
            case 6: return "Double Tap";
            case 7: return "Long Press";
            case 8: return "Triple Tap";
            default: return nullptr;
        }
    }
};