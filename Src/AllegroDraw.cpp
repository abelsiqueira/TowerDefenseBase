#include "AllegroDraw.h"
#include <map>

DrawingClass::DrawingClass (int w, int h) {
  al_init();
  mDisplay = al_create_display(w, h);
  al_set_window_title(mDisplay, "Tower Defense");
  mEventQueue = al_create_event_queue();
  mTimer = al_create_timer (1.0/30.0);

  mDrawFunction = 0;
  mKeyboardFunction = 0;
  mMouseFunction = 0;
  mTimerFunction = 0;

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
      redraw = CallTimerFunction();
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

      CallDrawFunction();

      al_flip_display();
    }
  }
}

