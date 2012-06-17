#ifndef allegro_draw_h
#define allegro_draw_h

typedef void (*pVoidFVoid) (void);

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Interface;

class DrawingClass {
  public:
    DrawingClass (int, int, Interface *);
    ~DrawingClass ();

    void Run ();

    // Primitives
    void DrawSquare (float x0, float y0, float x1, float y1, int r, int g,
        int b, int thick);
    void DrawFilledSquare (float x0, float y0, float x1, float y1, int r, 
        int g, int b);
    void DrawCircle (float cx, float cy, float radius, int r, int g, int b, int thick);
    void DrawFilledCircle (float cx, float cy, float radius, int r, int g, int b);

  private:
    ALLEGRO_DISPLAY *mDisplay;
    ALLEGRO_EVENT_QUEUE *mEventQueue;
    ALLEGRO_TIMER *mTimer;

    Interface *mInterface;
};

#endif
