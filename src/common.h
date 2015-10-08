#include <pebble.h>

// primary coordinates
#if defined(PBL_RECT)
#define DEVICE_WIDTH        144
#define DEVICE_HEIGHT       168
#define DEVICE_INSET          0
#elif defined(PBL_ROUND)
#define DEVICE_WIDTH        180
#define DEVICE_HEIGHT       180
#define DEVICE_INSET          2
#endif

struct tm *currentTime;

struct tm *get_time();

void center_text_layer(TextLayer *mylayer, GRect bounds);
