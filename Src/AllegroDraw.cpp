#include "AllegroDraw.h"
#include "Interface.h"
#include <map>

DrawingClass::DrawingClass (int w, int h, Interface *interface) {
  al_init();
  mDisplay = al_create_display(w, h);
  al_set_window_title(mDisplay, "Tower Defense");
  mEventQueue = al_create_event_queue();
  mTimer = al_create_timer (ConstFps);

  mInterface = interface;

  al_init_primitives_addon();
  al_install_mouse();
  al_install_keyboard();

  al_register_event_source(mEventQueue, al_get_display_event_source(mDisplay));
  al_register_event_source(mEventQueue, al_get_timer_event_source(mTimer));
  al_register_event_source(mEventQueue, al_get_mouse_event_source());
  al_register_event_source(mEventQueue, al_get_keyboard_event_source());
}

DrawingClass::~DrawingClass () {
  al_destroy_display(mDisplay);
  al_destroy_event_queue(mEventQueue);
  al_destroy_timer(mTimer);
}

void DrawingClass::Run () {
  bool done = false, redraw = false;

  al_start_timer(mTimer);
  while (!done) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(mEventQueue, &ev);

    if (ev.type == ALLEGRO_EVENT_TIMER) {
      mInterface->Update();
      redraw = true;
    } else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      done = true;
    else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
    } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch (ev.keyboard.keycode) {
        case ALLEGRO_KEY_ESCAPE:
        case ALLEGRO_KEY_Q:
          done = true;
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
