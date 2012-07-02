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
#ifndef dummy_draw_h
#define dummy_draw_h

/* This file exists to define drawing functions that will do nothing.
 * This way, we can test the compilation and execution independent of graphic
 * library. Hopefully all will work well.
 */

class DrawingClass {
  public:
    DrawingClass (int, int) {}
    ~DrawingClass () {}

    void DrawSquare (float x0, float y0, float x1, float y1) {}
    void DrawCircle (float cx, float cy, float r) {}
  private:
};

#endif
