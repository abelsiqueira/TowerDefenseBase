/* Copyright 2012 - Abel Soares Siqueira
 * 
 * This file is part of TowerDefenseBase.
 * 
 * TowerDefenseBase is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * TowerDefenseBase is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with TowerDefenseBase.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "AllegroDraw.h"
#include "Interface.h"
#include <map>

std::map <int,KeyCode> KeyMap;

void CreateMap () {
  KeyMap[ALLEGRO_KEY_A] = KeyA;
  KeyMap[ALLEGRO_KEY_B] = KeyB;
  KeyMap[ALLEGRO_KEY_C] = KeyC;
  KeyMap[ALLEGRO_KEY_D] = KeyD;
  KeyMap[ALLEGRO_KEY_E] = KeyE;
  KeyMap[ALLEGRO_KEY_F] = KeyF;
  KeyMap[ALLEGRO_KEY_G] = KeyG;
  KeyMap[ALLEGRO_KEY_H] = KeyH;
  KeyMap[ALLEGRO_KEY_I] = KeyI;
  KeyMap[ALLEGRO_KEY_J] = KeyJ;
  KeyMap[ALLEGRO_KEY_K] = KeyK;
  KeyMap[ALLEGRO_KEY_L] = KeyL;
  KeyMap[ALLEGRO_KEY_M] = KeyM;
  KeyMap[ALLEGRO_KEY_N] = KeyN;
  KeyMap[ALLEGRO_KEY_O] = KeyO;
  KeyMap[ALLEGRO_KEY_P] = KeyP;
  KeyMap[ALLEGRO_KEY_Q] = KeyQ;
  KeyMap[ALLEGRO_KEY_R] = KeyR;
  KeyMap[ALLEGRO_KEY_S] = KeyS;
  KeyMap[ALLEGRO_KEY_T] = KeyT;
  KeyMap[ALLEGRO_KEY_U] = KeyU;
  KeyMap[ALLEGRO_KEY_V] = KeyV;
  KeyMap[ALLEGRO_KEY_X] = KeyX;
  KeyMap[ALLEGRO_KEY_W] = KeyW;
  KeyMap[ALLEGRO_KEY_Y] = KeyY;
  KeyMap[ALLEGRO_KEY_Z] = KeyZ;
  KeyMap[ALLEGRO_KEY_0] = Key0;
  KeyMap[ALLEGRO_KEY_1] = Key1;
  KeyMap[ALLEGRO_KEY_2] = Key2;
  KeyMap[ALLEGRO_KEY_3] = Key3;
  KeyMap[ALLEGRO_KEY_4] = Key4;
  KeyMap[ALLEGRO_KEY_5] = Key5;
  KeyMap[ALLEGRO_KEY_6] = Key6;
  KeyMap[ALLEGRO_KEY_7] = Key7;
  KeyMap[ALLEGRO_KEY_8] = Key8;
  KeyMap[ALLEGRO_KEY_9] = Key9;
  KeyMap[ALLEGRO_KEY_ESCAPE] = KeyEscape;
}

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
  assert(al_install_audio());
  assert(al_init_acodec_addon());
  assert(al_reserve_samples(1));


  al_register_event_source(mEventQueue, al_get_display_event_source(mDisplay));
  al_register_event_source(mEventQueue, al_get_timer_event_source(mTimer));
  al_register_event_source(mEventQueue, al_get_mouse_event_source());
  al_register_event_source(mEventQueue, al_get_keyboard_event_source());

  float tileSize = interface->GetTileSize();
  mBigFont = al_load_font("DejaVuSans.ttf", tileSize, 0);
  mFont = al_load_font("DejaVuSans.ttf", tileSize/2, 0);
  mSmallFont = al_load_font("DejaVuSans.ttf", tileSize/4, 0);
  mMusic = al_load_audio_stream("Audio/Samples/bu-the-green-wizards.it", 4, 1024);
  al_attach_audio_stream_to_mixer(mMusic, al_get_default_mixer());
  al_set_audio_stream_playing(mMusic, true);

  CreateMap();
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
    } else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      mDone = true;
    } else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
               ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
      mMousePosition.x = ev.mouse.x;
      mMousePosition.y = ev.mouse.y;
    } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
      mInterface->Mouse(MouseUp);
    } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      mInterface->Keyboard(KeyMap[ev.keyboard.keycode]);
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
