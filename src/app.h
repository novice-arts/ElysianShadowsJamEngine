#ifndef APP_H
#define APP_H

static inline void (app_update)(void);

static inline bool (app_setup)(void);

static inline void (app_teardown)(void);

#define APP_SCREEN_WIDTH 640
#define APP_SCREEN_HEIGHT 480

#include "app/project_stub.h"



#endif //APP_H