#include <pebble.h>
#include "../../common.h"

static TextLayer *time_layer;

static int8_t seconds_shown;

void update_time_text();

int need_second_tick_handler(void);

void init_time_layer();
