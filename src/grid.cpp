#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid(const Vector3<double> &o, int w, int h, int dx, int dy,
    const RGBA<unsigned char> &gridColor):
        o{o}, w{w}, h{h},
        dx{dx}, dy{dy},
        gridColor{gridColor}
{ 
    cout << (unsigned int)gridColor.a << endl;
}

void Grid::draw(Window &w)
{
    // drawing a horizontal line through origin
    w.drawLine(o.x() - Grid::w/2, o.y(), 
        o.x() + Grid::w/2, o.y(), gridColor);
    // drawing a vertical line through origin
    w.drawLine(o.x(), o.y()-Grid::h/2,
        o.x(), o.y()+Grid::h/2, gridColor);
    // drawing vertical lines
    for (int i = dx; i <= Grid::w/2; i += dx)
    {
        w.drawLine(o.x()+i, o.y()-h/2, o.x()+i,
            o.y()+h/2, gridColor);
        w.drawLine(o.x()-i, o.y()-h/2, o.x()-i,
            o.y()+h/2, gridColor);
    }
    // drawing horizontal lines
    for (int i = dy; i <= Grid::h/2; i += dy)
    {
        w.drawLine(o.x()-Grid::w/2, o.y()+i, 
            o.x()+Grid::w/2, o.y()+i, gridColor);
        w.drawLine(o.x()-Grid::w/2, o.y()-i, 
            o.x()+Grid::w/2, o.y()-i, gridColor);
    }
}
