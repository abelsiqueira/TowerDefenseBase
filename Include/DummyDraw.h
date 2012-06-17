#ifndef dummy_draw_h
#define dummy_draw_h

/* This file exists to define drawing functions that will do nothing.
 * This way, we can test the compilation and execution independent of graphic
 * library. Hopefully all will work well.
 */

class DrawingClass {
  public:
    DrawingClass ();
    ~DrawingClass ();

    void DrawSquare (float x0, float y0, float x1, float y1) {}
    void DrawCircle (float cx, float cy, float r) {}
  private:
};

#endif
