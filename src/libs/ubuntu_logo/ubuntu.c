#include "libs/ubuntu_logo/ubuntu.h"

void draw_ubuntu_logo(GRect bounds, GContext *ctx, GColor foreground, GColor background) {
// assumes the background is colored appropriately, we're not going to just coat the bounds w/ the appropriate background color.

//TODO: perfect ratio/sizes - they're not quite right yet, but the positioning with these new functions is tricky...

#if defined(PBL_RECT)
  int16_t bounds_inset = 20;
  int16_t logo_inset = 20;
  int16_t logo_fgdot_box = 22;
  int16_t logo_bgline_size = 4; // ring
#elif defined(PBL_ROUND)
  int16_t bounds_inset = 25;
  int16_t logo_inset = 24;
  int16_t logo_fgdot_box = 26;
  int16_t logo_bgline_size = 5; // ring
#endif
  int16_t logo_bgdot_box = logo_fgdot_box + 2*logo_bgline_size;
  int16_t logo_fgdot_size = logo_fgdot_box; // circle

  GRect frame = grect_inset(bounds, GEdgeInsets(bounds_inset));

  graphics_context_set_fill_color(ctx, background);
  graphics_fill_radial(ctx, bounds, GOvalScaleModeFitCircle, bounds.size.w, 0, TRIG_MAX_ANGLE); // roundel

  graphics_context_set_fill_color(ctx, foreground);
  graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, logo_inset, 0, TRIG_MAX_ANGLE); // circle of friends, arms

  // CoF 'heads'
  GRect fgdot1 = grect_centered_from_polar(grect_crop(bounds,bounds_inset-5), GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(30), GSize(logo_fgdot_box,logo_fgdot_box) );
  GRect bgdot1 = grect_centered_from_polar(grect_crop(bounds,bounds_inset-5), GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(30), GSize(logo_bgdot_box,logo_bgdot_box) );
  GRect fgdot2 = grect_centered_from_polar(grect_crop(bounds,bounds_inset-5), GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(150), GSize(logo_fgdot_box,logo_fgdot_box) );
  GRect bgdot2 = grect_centered_from_polar(grect_crop(bounds,bounds_inset-5), GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(150), GSize(logo_bgdot_box,logo_bgdot_box) );
  GRect fgdot3 = grect_centered_from_polar(grect_crop(bounds,bounds_inset-5), GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(270), GSize(logo_fgdot_box,logo_fgdot_box) );
  GRect bgdot3 = grect_centered_from_polar(grect_crop(bounds,bounds_inset-5), GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(270), GSize(logo_bgdot_box,logo_bgdot_box) );

  graphics_context_set_fill_color(ctx, background);
  graphics_fill_radial(ctx, bgdot1, GOvalScaleModeFitCircle, logo_bgline_size, 0, TRIG_MAX_ANGLE);
  graphics_fill_radial(ctx, bgdot2, GOvalScaleModeFitCircle, logo_bgline_size, 0, TRIG_MAX_ANGLE);
  graphics_fill_radial(ctx, bgdot3, GOvalScaleModeFitCircle, logo_bgline_size, 0, TRIG_MAX_ANGLE);

  graphics_context_set_fill_color(ctx, foreground);
  graphics_fill_radial(ctx, fgdot1, GOvalScaleModeFitCircle, logo_fgdot_size, 0, TRIG_MAX_ANGLE);
  graphics_fill_radial(ctx, fgdot2, GOvalScaleModeFitCircle, logo_fgdot_size, 0, TRIG_MAX_ANGLE);
  graphics_fill_radial(ctx, fgdot3, GOvalScaleModeFitCircle, logo_fgdot_size, 0, TRIG_MAX_ANGLE);

  // stroke, stroke width, AA
  GPoint center = grect_center_point(&bounds);
  int16_t second_hand_length = bounds.size.w;

  GPoint line1end = gpoint_from_polar(frame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(90));
  GPoint line2end = gpoint_from_polar(frame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(210));
  GPoint line3end = gpoint_from_polar(frame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(330));

/*
  GPoint line1end = {
    .x = (int16_t)(sin_lookup(0) * bounds.size.w / TRIG_MAX_RATIO) + center.x,
    .y = (int16_t)(-cos_lookup(0) * bounds.size.w / TRIG_MAX_RATIO) + center.y,
  };

  GPoint line2end = {
    .x = (int16_t)(sin_lookup(120) * bounds.size.w / TRIG_MAX_RATIO) + center.x,
    .y = (int16_t)(-cos_lookup(120) * bounds.size.w / TRIG_MAX_RATIO) + center.y,
  };

  GPoint line3end = {
    .x = (int16_t)(sin_lookup(240) * bounds.size.w / TRIG_MAX_RATIO) + center.x,
    .y = (int16_t)(-cos_lookup(240) * bounds.size.h / TRIG_MAX_RATIO) + center.y,
  };
*/

  graphics_context_set_antialiased(ctx, true); 
  graphics_context_set_stroke_width(ctx, logo_bgline_size);
  graphics_context_set_stroke_color(ctx, background);
  //graphics_context_set_stroke_color(ctx, GColorRed);
  graphics_draw_line(ctx, line1end, center);
  //graphics_context_set_stroke_color(ctx, GColorGreen);
  graphics_draw_line(ctx, line2end, center);
  //graphics_context_set_stroke_color(ctx, GColorBlue);
  graphics_draw_line(ctx, line3end, center);
}
