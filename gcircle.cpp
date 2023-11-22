#include "gcircle.h"

#include "mesh2_utils.h"

GCircle::GCircle(const Vector3<double> &c, double r, 
            ssize_t n, const RGBA<unsigned char> &rgba):
    GMesh2{buildCircleMesh(c,r,n), rgba}, c(c), r(r)
{
}

void GCircle::move(double x, double y)
{
    c.a[0][0] += x;
    c.a[1][0] += y;
    Matrix<double> translate = Matrix<double>::identity(3);
    translate.a[0][2] = x;
    translate.a[1][2] = y;
    Mesh2::transform(translate);
}

void GCircle::imprimir()
{
    cout << c << endl;
}

bool GCircle::collision(GCircle &a, GCircle &b)
{
    double distance = sqrt(pow((a.c.x() - b.c.x()), 2) + pow((a.c.y() - b.c.y()), 2));
    double sumRadii = a.r + b.r;

    return distance <= sumRadii;
}

bool GCircle::floorCollision(const int &height)
{
    if (c.y() + r >= height/2)
        return true;        
    else if (c.y() - r <= -height/2)
        return true;
    else    
        return false;
}

double GCircle::calculateDistance(GCircle &a, GCircle &b)
{
    return sqrt((a.c.x() - b.c.x())*(a.c.x() - b.c.x()) + (a.c.y() - b.c.y())*(a.c.y() - b.c.y()));
}

double GCircle::getcX()
{
    return c.x();
}

double GCircle::getcY()
{
    return c.y();
}

Vector3<double> GCircle::getC()
{
    return c;
}

double GCircle::getR()
{
    return r;
}