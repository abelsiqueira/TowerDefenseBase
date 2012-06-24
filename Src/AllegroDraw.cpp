#include "AllegroDraw.h"
#include "Interface.h"
#include <map>

DrawingClass::DrawingClass (int w, int h, Interface *interface) {
  al_init();
  mDisplay = al_create_display(w, h);
  al_set_window_title(mDisplay, "Tower Defense");
  mEventQueue = al_create_event_queue();
  mTimer = al_create_timer (1.0/((float)ConstFps));

  mInterface = interface;

  al_init_font_addon();
  al_init_ttf_addon();
  al_init_primitives_addon();
  al_install_mouse();
  al_install_keyboard();

  al_register_event_source(mEventQueue, al_get_display_event_source(mDisplay));
  al_register_event_source(mEventQueue, al_get_timer_event_source(mTimer));
  al_register_event_source(mEventQueue, al_get_mouse_event_source());
  al_register_event_source(mEventQueue, al_get_keyboard_event_source());

  float tileSize = interface->GetTileSize();
  mBigFont = al_load_font("DejaVuSans.ttf", tileSize, 0);
  mFont = al_load_font("DejaVuSans.ttf", tileSize/2, 0);
  mSmallFont = al_load_font("DejaVuSans.ttf", tileSize/4, 0);
}

DrawingClass::~DrawingClass () {
  al_destroy_font(mBigFont);
  al_destroy_font(mFont);
  al_destroy_font(mSmallFont);
  al_destroy_timer(mTimer);
  al_destroy_event_queue(mEventQueue);
  al_destroy_display(mDisplay);
}

void DrawingClass::Run () {
  bool redraw = false;

  al_start_timer(mTimer);
  while (!mDone) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(mEventQueue, &ev);

    if (ev.type == ALLEGRO_EVENT_TIMER) {
      mInterface->Update();
      redraw = true;
    } else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      mDone = true;
    else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
    } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch (ev.keyboard.keycode) {
        case ALLEGRO_KEY_ESCAPE:
        case ALLEGRO_KEY_Q:
          mDone = true;
          break;
        default:
          break;
      }
    }

    if (redraw && al_is_event_queue_empty(mEventQueue)) {
      redraw = false;
      al_clear_to_color(al_map_rgb(0,0,0));

      mInterface->Draw();

      al_flip_display();
    }
  }
}


void DrawingClass::BigWrite (float x0, float y0, std::string str, int r, int g, int b,
    FontAlignment fa) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  switch (fa) {
    case FA_left:
      al_draw_text(mBigFont, color, x0, y0, ALLEGRO_ALIGN_LEFT, str.c_str());
      break;
    case FA_center:
      al_draw_text(mBigFont, color, x0, y0, ALLEGRO_ALIGN_CENTRE, str.c_str());
      break;
    case FA_right:
      al_draw_text(mBigFont, color, x0, y0, ALLEGRO_ALIGN_RIGHT, str.c_str());
      break;
  }
}

void DrawingClass::SmallWrite (float x0, float y0, std::string str, int r, int g, int b,
    FontAlignment fa) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  switch (fa) {
    case FA_left:
      al_draw_text(mSmallFont, color, x0, y0, ALLEGRO_ALIGN_LEFT, str.c_str());
      break;
    case FA_center:
      al_draw_text(mSmallFont, color, x0, y0, ALLEGRO_ALIGN_CENTRE, str.c_str());
      break;
    case FA_right:
      al_draw_text(mSmallFont, color, x0, y0, ALLEGRO_ALIGN_RIGHT, str.c_str());
      break;
  }
}

void DrawingClass::Write (float x0, float y0, std::string str, int r, int g, int b,
    FontAlignment fa) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  switch (fa) {
    case FA_left:
      al_draw_text(mFont, color, x0, y0, ALLEGRO_ALIGN_LEFT, str.c_str());
      break;
    case FA_center:
      al_draw_text(mFont, color, x0, y0, ALLEGRO_ALIGN_CENTRE, str.c_str());
      break;
    case FA_right:
      al_draw_text(mFont, color, x0, y0, ALLEGRO_ALIGN_RIGHT, str.c_str());
      break;
  }
}

void DrawingClass::DrawLine (float x0, float y0, float x1, float y1, int r, 
    int g, int b, int thick) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_line(x0, y0, x1, y1, color, thick);
}

void DrawingClass::DrawRectangle (float x0, float y0, float x1, float y1, int r, 
    int g, int b, int thick) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_rectangle(x0, y0, x1, y1, color, thick);
}

void DrawingClass::DrawFilledRectangle (float x0, float y0, float x1, float y1, 
    int r, int g, int b) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_filled_rectangle(x0, y0, x1, y1, color);
}

void DrawingClass::DrawCircle (float cx, float cy, float radius, int r, int g,
    int b, int thick) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_circle(cx, cy, radius, color, thick);
}

void DrawingClass::DrawFilledCircle (float cx, float cy, float radius, int r, 
    int g, int b) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_filled_circle(cx, cy, radius, color);
}

void DrawingClass::DrawTriangle (float x0, float y0, float x1, float y1,
    float x2, float y2, int r, int g, int b, float thick) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_triangle(x0, y0, x1, y1, x2, y2, color, thick);
}

void DrawingClass::DrawFilledTriangle (float x0, float y0, float x1, float y1,
    float x2, float y2, int r, int g, int b) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_filled_triangle(x0, y0, x1, y1, x2, y2, color);
}

void DrawingClass::DrawRoundedRectangle (float x0, float y0, float x1,
    float y1, float rx, float ry, int r, int g, int b, float thick) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_rounded_rectangle(x0, y0, x1, y1, rx, ry, color, thick);
}

void DrawingClass::DrawFilledRoundedRectangle (float x0, float y0, float x1,
    float y1, float rx, float ry, int r, int g, int b) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_filled_rounded_rectangle(x0, y0, x1, y1, rx, ry, color);
}

void DrawingClass::DrawEllipse (float x0, float y0, float rx, float ry,
    int r, int g, int b, float thick) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_ellipse(x0, y0, rx, ry, color, thick);
}

void DrawingClass::DrawFilledEllipse (float x0, float y0, float rx, float ry,
    int r, int g, int b) {
  ALLEGRO_COLOR color = al_map_rgb(r, g, b);
  al_draw_filled_ellipse(x0, y0, rx, ry, color);
}
