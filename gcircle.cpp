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
    cout << "Centro: " << c << endl;
}

bool GCircle::collision(GCircle &a, GCircle &b)
{
    double distance = sqrt(pow((a.c.x() - b.c.x()), 2) + pow((a.c.y() - b.c.y()), 2));
    double sumRadii = a.r + b.r;

    return distance <= sumRadii;
}

bool GCircle::floorCollision(const int &floor, GCircle &a)
{
    if (a.c.y() + a.r >= floor/2)
        return true;        
    else if (a.c.y() - a.r <= -floor/2)
        return true;
    else    
        return false;
}
