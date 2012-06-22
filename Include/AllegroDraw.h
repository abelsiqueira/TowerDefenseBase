#ifndef allegro_draw_h
#define allegro_draw_h

typedef void (*pVoidFVoid) (void);

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Vectors.h"

class Interface;

class DrawingClass {
  public:
    DrawingClass (int, int, Interface *);
    ~DrawingClass ();

    void Run ();

    // Primitives
    void DrawLine (float x0, float y0, float x1, float y1, int r, int g, int b,
        int thick);
    void DrawRectangle (float x0, float y0, float x1, float y1, int r, int g,
        int b, int thick);
    void DrawFilledRectangle (float x0, float y0, float x1, float y1, int r, 
        int g, int b);
    void DrawCircle (float cx, float cy, float radius, int r, int g, int b, int thick);
    void DrawFilledCircle (float cx, float cy, float radius, int r, int g, int b);

    //Primitives with Vector2f for positions
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

    ///Primitives with Vector3i for color
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

    //Primitives with Vector2f for positions and Vector3i for color
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

  private:
    ALLEGRO_DISPLAY *mDisplay;
    ALLEGRO_EVENT_QUEUE *mEventQueue;
    ALLEGRO_TIMER *mTimer;

    Interface *mInterface;
};

#endif
