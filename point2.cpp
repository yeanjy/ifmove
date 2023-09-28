#include "point2.h"

Point2::Point2():
    x{0.0}, y{0.0}
{ }

Point2::Point2(double x, double y):
    x{x}, y{y}
{ }

Point2::Point2(const Point2 &p):
    Point2{p.x, p.y}
{
}

Point2 & Point2::operator=(const Point2 &p)
{
    Point2::x = p.x;
    Point2::y = p.y;
    return *this;
}

void Point2::translate(double x, double y)
{
    Point2::x += x;
    Point2::y += y;
}

