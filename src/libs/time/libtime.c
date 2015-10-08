#include "libs/time/libtime.h"

// todo - instantiate time layer here?

static int8_t seconds_shown = 0;

void update_time_text() {
  // Need to be static because used by the system later.
  static char time_text[] = "00:00";

  char *time_format;

  if (clock_is_24h_style()) {
    time_format = "%R";
  } else {
    time_format = "%I:%M";
  }

  strftime(time_text, sizeof(time_text), time_format, currentTime);

  // Kludge to handle lack of non-padded hour format string
  // for twelve hour clock.
  if (!clock_is_24h_style() && (time_text[0] == '0')) {
    memmove(time_text, &time_text[1], sizeof(time_text) - 1);
  }

  // I would love to just use clock_copy_time_string, but it refuses to center properly in 12-hour time (see Kludge above).
  //clock_copy_time_string(time_text, sizeof(time_text));
  text_layer_set_text(time_layer, time_text);

}

int need_second_tick_handler(void) {
  return 0; 
}

void init_time_layer(Layer *parent) {
  time_layer = text_layer_create( GRect(0, 0, DEVICE_WIDTH - 2, 20) ); // see position_time_layer()
//  time_layer = text_layer_create( GRect(REL_CLOCK_TIME_LEFT, REL_CLOCK_TIME_TOP, DEVICE_WIDTH - 2, REL_CLOCK_TIME_HEIGHT) ); // see position_time_layer()
//  set_layer_attr_cfont(time_layer, RESOURCE_ID_FONT_FUTURA_CONDENSED_48, GTextAlignmentCenter);
//  position_time_layer(); // make use of our whitespace, if we have it...
  update_time_text();
  layer_add_child(parent, text_layer_get_layer(time_layer));
}
