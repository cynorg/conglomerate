#include "common.h"

struct tm *get_time() {
    time_t tt = time(0);
    return localtime(&tt);
}

void center_text_layer(TextLayer *mylayer, GRect bounds) {
  GSize mysize = text_layer_get_content_size(mylayer);
  layer_set_frame( text_layer_get_layer(mylayer), GRect(0, (bounds.size.h/2) - (mysize.h - mysize.h%2)/2, bounds.size.w, mysize.h) );
}

