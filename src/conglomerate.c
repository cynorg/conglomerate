#include <pebble.h>
#include "libs/time/libtime.h"
#include "common.h"
#include "conglomerate.h"

static Window *window;
static TextLayer *text_layer;

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, (DEVICE_WIDTH/2)-DEVICE_INSET }, .size = { bounds.size.w, 20 } });
  text_layer_set_text(text_layer, "Hello World");
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
//  GSize mysize = text_layer_get_content_size(text_layer);
//  layer_set_frame( text_layer_get_layer(text_layer), GRect(0, ((DEVICE_WIDTH/2)-DEVICE_INSET) - (mysize.h - mysize.h%2)/2, bounds.size.w, mysize.h) );
  center_text_layer(text_layer,bounds);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
  init_time_layer(window_layer);
}

static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
}

static void init(void) {
  currentTime = get_time();

  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
  switch_tick_handler();
}

static void deinit(void) {
  window_destroy(window);
}

void handle_minute_tick(struct tm *tick_time, TimeUnits units_changed)
{
  *currentTime = *tick_time;
  update_time_text();
}

void handle_second_tick(struct tm *tick_time, TimeUnits units_changed)
{
  // redraw everything else if the minute changes...
  handle_minute_tick(tick_time, units_changed);
}

static void switch_tick_handler(void) {
  tick_timer_service_unsubscribe(); // safe to call even before we've subscribed
  seconds_shown = need_second_tick_handler();
  if (seconds_shown) {
    tick_timer_service_subscribe(SECOND_UNIT, &handle_second_tick);
//    if (debug.general) { app_log(APP_LOG_LEVEL_DEBUG, __FILE__, __LINE__, "Seconds handler enabled"); }
  } else {
    tick_timer_service_subscribe(MINUTE_UNIT, &handle_minute_tick);
//    if (debug.general) { app_log(APP_LOG_LEVEL_DEBUG, __FILE__, __LINE__, "Seconds handler disabled"); }
  }
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}
