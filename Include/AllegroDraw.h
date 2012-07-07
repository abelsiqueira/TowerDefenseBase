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
#ifndef allegro_draw_h
#define allegro_draw_h

typedef void (*pVoidFVoid) (void);

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "Vectors.h"
#include "Definitions.h"

class Interface;

class DrawingClass {
  public:
    DrawingClass (int, int, Interface *);
    ~DrawingClass ();

    void Run ();

    Vector2f GetMousePosition () { return mMousePosition; }

    // Primitives
    void BigWrite (float x0, float y0, std::string str, int r, int g, int b,
        FontAlignment fa = FA_left);
    void SmallWrite (float x0, float y0, std::string str, int r, int g, int b,
        FontAlignment fa = FA_left);
    void Write (float x0, float y0, std::string str, int r, int g, int b,
        FontAlignment fa = FA_left);
    void DrawLine (float x0, float y0, float x1, float y1, int r, int g, int b,
        int thick);
    void DrawRectangle (float x0, float y0, float x1, float y1, int r, int g,
        int b, int thick);
    void DrawFilledRectangle (float x0, float y0, float x1, float y1, int r, 
        int g, int b);
    void DrawFilledRectangle (float x0, float y0, float x1, float y1, int r, 
        int g, int b, int a);
    void DrawCircle (float cx, float cy, float radius, int r, int g, int b, int thick);
    void DrawFilledCircle (float cx, float cy, float radius, int r, int g, int b);
    void DrawTriangle (float x0, float y0, float x1, float y1, float x2, float y2,
        int r, int g, int b, float thick);
    void DrawFilledTriangle (float x0, float y0, float x1, float y1, float x2, float y2,
        int r, int g, int b);
    void DrawRoundedRectangle (float x0, float y0, float x1, float y1,
        float rx, float ry, int r, int g, int b, float thick);
    void DrawFilledRoundedRectangle (float x0, float y0, float x1, float y1,
        float rx, float ry, int r, int g, int b);
    void DrawEllipse (float cx, float cy, float rx, float ry,
        int r, int g, int b, float thick);
    void DrawFilledEllipse (float cx, float cy, float rx, float ry,
        int r, int g, int b);

    //Primitives with Vector2f for positions
    void BigWrite (Vector2f p, std::string str, int r, int g, int b, 
        FontAlignment fa = FA_left) {
      BigWrite(p.x, p.y, str, r, g, b, fa);
    }
    void SmallWrite (Vector2f p, std::string str, int r, int g, int b, 
        FontAlignment fa = FA_left) {
      SmallWrite(p.x, p.y, str, r, g, b, fa);
    }
    void Write (Vector2f p, std::string str, int r, int g, int b, 
        FontAlignment fa = FA_left) {
      Write(p.x, p.y, str, r, g, b, fa);
    }
    void DrawLine (Vector2f p0, Vector2f p1, int r, int g, int b, int thick) {
      DrawLine(p0.x, p0.y, p1.x, p1.y, r, g, b, thick);
    }
    void DrawRectangle (Vector2f p0, Vector2f p1, int r, int g, int b, int thick) {
      DrawRectangle(p0.x, p0.y, p1.x, p1.y, r, g, b, thick);
    }
    void DrawFilledRectangle (Vector2f p0, Vector2f p1, int r, int g, int b) {
      DrawFilledRectangle(p0.x, p0.y, p1.x, p1.y, r, g, b);
    }
    void DrawCircle (Vector2f c, int radius, int r, int g, int b, int thick) {
      DrawCircle(c.x, c.y, radius, r, g, b, thick);
    }
    void DrawFilledCircle (Vector2f c, int radius, int r, int g, int b) {
      DrawFilledCircle(c.x, c.y, radius, r, g, b);
    }
    void DrawTriangle (Vector2f p0, Vector2f p1, Vector2f p2,
        int r, int g, int b, float thick) {
      DrawTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, r, g, b, thick);
    }
    void DrawFilledTriangle (Vector2f p0, Vector2f p1, Vector2f p2,
        int r, int g, int b) {
      DrawFilledTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, r, g, b);
    }
    void DrawRoundedRectangle (Vector2f p0, Vector2f p1,
        float rx, float ry, int r, int g, int b, float thick) {
      DrawRoundedRectangle(p0.x, p0.y, p1.x, p1.y, rx, ry, r, g, b, thick);
    }
    void DrawFilledRoundedRectangle (Vector2f p0, Vector2f p1,
        float rx, float ry, int r, int g, int b) {
      DrawFilledRoundedRectangle(p0.x, p0.y, p1.x, p1.y, rx, ry, r, g, b);
    }
    void DrawEllipse (Vector2f c, float rx, float ry,
        int r, int g, int b, float thick) {
      DrawEllipse(c.x, c.y, rx, ry, r, g, b, thick);
    }
    void DrawFilledEllipse (Vector2f c, float rx, float ry,
        int r, int g, int b) {
      DrawFilledEllipse(c.x, c.y, rx, ry, r, g, b);
    }

    ///Primitives with Vector3i for color
    void BigWrite (float x0, float y0, std::string str, Vector3i color,
        FontAlignment fa = FA_left) {
      BigWrite(x0, y0, str, color.x, color.y, color.z, fa);
    }
    void SmallWrite (float x0, float y0, std::string str, Vector3i color,
        FontAlignment fa = FA_left) {
      SmallWrite(x0, y0, str, color.x, color.y, color.z, fa);
    }
    void Write (float x0, float y0, std::string str, Vector3i color,
        FontAlignment fa = FA_left) {
      Write(x0, y0, str, color.x, color.y, color.z, fa);
    }
    void DrawLine (float x0, float y0, float x1, float y1, Vector3i color, int thick) {
      DrawLine(x0, y0, x1, y1, color.x, color.y, color.z, thick);
    }
    void DrawRectangle (float x0, float y0, float x1, float y1, Vector3i color, int thick) {
      DrawRectangle(x0, y0, x1, y1, color.x, color.y, color.z, thick);
    }
    void DrawFilledRectangle (float x0, float y0, float x1, float y1, Vector3i color) {
      DrawFilledRectangle(x0, y0, x1, y1, color.x, color.y, color.z);
    }
    void DrawCircle (float cx, float cy, float radius, Vector3i color, int thick) {
      DrawCircle(cx, cy, radius, color.x, color.y, color.z, thick);
    }
    void DrawFilledCircle (float cx, float cy, float radius, Vector3i color) {
      DrawFilledCircle(cx, cy, radius, color.x, color.y, color.z);
    }
    void DrawTriangle (float x0, float y0, float x1, float y1, float x2, float y2,
        Vector3i color, float thick) {
      DrawTriangle(x0, y0, x1, y1, x2, y2, color.x, color.y, color.z, thick);
    }
    void DrawFilledTriangle (float x0, float y0, float x1, float y1, float x2, float y2,
        Vector3i color) {
      DrawFilledTriangle(x0, y0, x1, y1, x2, y2, color.x, color.y, color.z);
    }
    void DrawRoundedRectangle (float x0, float y0, float x1, float y1,
        float rx, float ry, Vector3i color, float thick) {
      DrawRoundedRectangle(x0, y0, x1, y1, rx, ry, color.x, color.y, color.z, thick);
    }
    void DrawFilledRoundedRectangle (float x0, float y0, float x1, float y1,
        float rx, float ry, Vector3i color) {
      DrawFilledRoundedRectangle(x0, y0, x1, y1, rx, ry, color.x, color.y, color.z);
    }
    void DrawEllipse (float cx, float cy, float rx, float ry,
        Vector3i color, float thick) {
      DrawEllipse(cx, cy, rx, ry, color.x, color.y, color.z, thick);
    }
    void DrawFilledEllipse (float cx, float cy, float rx, float ry,
        Vector3i color) {
      DrawFilledEllipse(cx, cy, rx, ry, color.x, color.y, color.z);
    }

    //Primitives with Vector2f for positions and Vector3i for color
    void BigWrite (Vector2f p, std::string str, Vector3i color, 
        FontAlignment fa = FA_left) {
      BigWrite(p.x, p.y, str, color.x, color.y, color.z, fa);
    }
    void SmallWrite (Vector2f p, std::string str, Vector3i color, 
        FontAlignment fa = FA_left) {
      SmallWrite(p.x, p.y, str, color.x, color.y, color.z, fa);
    }
    void Write (Vector2f p, std::string str, Vector3i color, 
        FontAlignment fa = FA_left) {
      Write(p.x, p.y, str, color.x, color.y, color.z, fa);
    }
    void DrawLine (Vector2f p0, Vector2f p1, Vector3i color, int thick) {
      DrawLine(p0.x, p0.y, p1.x, p1.y, color.x, color.y, color.z, thick);
    }
    void DrawRectangle (Vector2f p0, Vector2f p1, Vector3i color, int thick) {
      DrawRectangle(p0.x, p0.y, p1.x, p1.y, color.x, color.y, color.z, thick);
    }
    void DrawFilledRectangle (Vector2f p0, Vector2f p1, Vector3i color) {
      DrawFilledRectangle(p0.x, p0.y, p1.x, p1.y, color.x, color.y, color.z);
    }
    void DrawCircle (Vector2f c, int radius, Vector3i color, int thick) {
      DrawCircle(c.x, c.y, radius, color.x, color.y, color.z, thick);
    }
    void DrawFilledCircle (Vector2f c, int radius, Vector3i color) {
      DrawFilledCircle(c.x, c.y, radius, color.x, color.y, color.z);
    }
    void DrawTriangle (Vector2f p0, Vector2f p1, Vector2f p2,
        Vector3i color, float thick) {
      DrawTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, color.x, color.y, color.z, thick);
    }
    void DrawFilledTriangle (Vector2f p0, Vector2f p1, Vector2f p2,
        Vector3i color) {
      DrawFilledTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, color.x, color.y, color.z);
    }
    void DrawRoundedRectangle (Vector2f p0, Vector2f p1,
        float rx, float ry, Vector3i color, float thick) {
      DrawRoundedRectangle(p0.x, p0.y, p1.x, p1.y, rx, ry, color.x, color.y, color.z, thick);
    }
    void DrawFilledRoundedRectangle (Vector2f p0, Vector2f p1,
        float rx, float ry, Vector3i color) {
      DrawFilledRoundedRectangle(p0.x, p0.y, p1.x, p1.y, rx, ry, color.x, color.y, color.z);
    }
    void DrawEllipse (Vector2f c, float rx, float ry,
        Vector3i color, float thick) { 
      DrawEllipse(c.x, c.y, rx, ry, color.x, color.y, color.z, thick);
    }
    void DrawFilledEllipse (Vector2f c, float rx, float ry,
        Vector3i color) {
      DrawFilledEllipse(c.x, c.y, rx, ry, color.x, color.y, color.z);
    }

    void DrawBackground ();
    void Done () { mDone = true; }
  private:
    bool mDone;
    Vector2f mMousePosition;

    ALLEGRO_DISPLAY *mDisplay;
    ALLEGRO_EVENT_QUEUE *mEventQueue;
    ALLEGRO_TIMER *mTimer;
    ALLEGRO_FONT *mBigFont;
    ALLEGRO_FONT *mFont;
    ALLEGRO_FONT *mSmallFont;

    ALLEGRO_AUDIO_STREAM *mMusic;

    ALLEGRO_BITMAP *mBackground;

    Interface *mInterface;
};

#endif
