#include "arrow2.h"
#include "point2.h"

#include <iostream>
using namespace std;

// constructor
Arrow2::Arrow2(double tx, double ty, 
    double hx, double hy, 
    const RGBA<unsigned char> &rgba):
        t{tx, ty, 1.0},
        h{hx, hy, 1.0},
        color{rgba}
{
}

// constructor 
Arrow2::Arrow2(const Point2 &t, const Point2 &h, 
    const RGBA<unsigned char> &rgba):
    t{t.x, t.y, 1.0},
    h{h.x, h.y, 1.0},
    color{rgba}

{
}

Arrow2::Arrow2(const Vector3<double> &t, const Vector3<double> &h, 
    const RGBA<unsigned char> &rgba):
    t{t},
    h{h},
    color{rgba}

{
}

void Arrow2::draw(Window &w)
{
    // calculating the size of the arrow head, 10%
    double l =  0.1 * length(); 
    // calculating the angle
    double a = atan2(h.y() - t.y(), h.x() - t.x());
    w.drawLine(t, h, color);
    // drawing head 
    w.drawLine(h.x(), h.y(), 
        h.x() + l*cos(a+3*M_PI/4), 
        h.y() + l*sin(a+3*M_PI/4), color );
    w.drawLine(h.x(), h.y(), 
        h.x() + l*cos(a+5*M_PI/4), 
        h.y() + l*sin(a+5*M_PI/4), color );
}

double Arrow2::length()
{
    return sqrt((h.x()-t.x())*(h.x()-t.x())+
            (h.y()-t.y())*(h.y()-t.y()));
}
