#ifndef allegro_draw_h
#define allegro_draw_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class DrawingClass {
  public:
    DrawingClass (int, int);
    ~DrawingClass ();

    void Run ();
    void DrawSquare (float x0, float y0, float x1, float y1);
    void DrawCircle (float cx, float cy, float r);

    void SetTimerFunction (void (*f)()) {
      mTimerFunction = f;
    }
    void SetMouseFunction (void (*f)()) {
      mMouseFunction = f;
    }
    void SetKeyboardFunction (void (*f)()) {
      mKeyboardFunction = f;
    }
    void SetDrawFunction (void (*f)()) {
      mDrawFunction = f;
    }
  private:
    ALLEGRO_DISPLAY *mDisplay;
    ALLEGRO_EVENT_QUEUE *mEventQueue;
    ALLEGRO_TIMER *mTimer;

    void (*mTimerFunction)();
    void (*mMouseFunction)();
    void (*mKeyboardFunction)();
    void (*mDrawFunction)();

    bool CallTimerFunction () {
      if (mTimerFunction) {
        (*mTimerFunction)();
        return true;
      }
      return false;
    }

    void CallDrawFunction () {
      if (mDrawFunction)
        (*mDrawFunction)();
    }
};

#endif
