#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void wifi_init(void);
void wifi_connect(void);
bool wifi_is_connected(void);
void wifi_update(void);

#ifdef __cplusplus
}
#endif