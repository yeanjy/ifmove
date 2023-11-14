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

bool GCircle::floorCollision(const int &floor)
{
    if (c.y() + r >= floor/2)
        return true;        
    else if (c.y() - r <= -floor/2)
        return true;
    else    
        return false;
}

bool GCircle::wallCollision(const int &height, const int &width)
{
    if (c.x() + r >= width/2 || c.x() - r <= -width/2)
        return true;
    if(c.y() + r >= height/2 || c.y() - r <= -height/2)
        return true;

    return false;
}

void GCircle::multipleCollision(vector<GCircle> &circle)
{
    for (int i = 0; i < circle.size(); i++)
    {
        for(int j = 0; j < circle.size(); j++)
        {
            if (i != j)
            {
                if(GCircle::collision(circle[i], circle[j]))
                {
                    double distance = sqrt((circle[i].c.x() - circle[j].c.x())*(circle[i].c.x() - circle[j].c.x()) + (circle[i].c.y() - circle[j].c.y())*(circle[i].c.y() - circle[j].c.y()));
                    double overlap = 0.5f*(distance - circle[i].r - circle[j].r);

                    circle[i].move(-overlap * (circle[i].c.x() - circle[j].c.x()) / distance, -overlap * (circle[i].c.y() - circle[j].c.y()) / distance);
                    circle[j].move(overlap * (circle[i].c.x() - circle[j].c.x()) / distance, overlap * (circle[i].c.y() - circle[j].c.y()) / distance);
                }
            }
        }
    }
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