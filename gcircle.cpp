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


                    double fdistance = GCircle::calculateDistance(circle[i], circle[j]);

                    double nx = (circle[j].c.x() - circle[i].c.x())/fdistance;
                    double ny = (circle[j].c.y() - circle[i].c.y())/fdistance;

                    double tx = -ny;
                    double ty = nx;

                    double dpTan1 = circle[i].c.x()*tx + circle[i].c.y()*ty;
                    double dpTan2 = circle[j].c.x()*tx + circle[j].c.y()*ty;

                    double dpNorm1 = circle[i].c.x()*nx + circle[i].c.y()*ny;
                    double dpNorm2 = circle[j].c.x()*nx + circle[j].c.y()*ny;

                    double m1 = (dpNorm1*(circle[i].mass - circle[j].mass)) + 2.f*circle[j].mass*dpNorm2 / (circle[i].mass + circle[j].mass);
                    double m2 = (dpNorm2*(circle[j].mass - circle[i].mass)) + 2.f*circle[i].mass*dpNorm1 / (circle[i].mass + circle[j].mass);

                    circle[i].vx = tx*dpTan1 + nx*m1;
                    circle[i].vy = ty*dpTan1 + ny*m1;
                    circle[j].vx = tx*dpTan2 + nx*m2;
                    circle[j].vy = ty*dpTan2 + nx*m2;
                }
            }
        }
    }
}

void GCircle::checkWallColision(vector<GCircle> &circle, const int &width, const int &height)
{
    for (int i = 0; i<circle.size(); i++)
    {
        if (circle[i].c.x() + circle[i].r >= width/2)
        {
            circle[i].move(-(circle[i].c.x() - (width/2 - circle[i].r)), 0);
            circle[i].vx *= -1;
        }

        if (circle[i].c.x() - circle[i].r <= -width/2)
        {
            circle[i].move((-circle[i].c.x() + (-width/2 + circle[i].r)), 0);
            circle[i].vx *= -1;
        }
        if(circle[i].c.y() + circle[i].r >= height/2)
        {
            circle[i].move(0, -(circle[i].c.y() - (height/2 - circle[i].r)));
            circle[i].vy *= -1;
        }
        if(circle[i].c.y() - circle[i].r <= -height/2)
        {
            circle[i].move(0, (-circle[i].c.y() + (-height/2 + circle[i].r)));
            circle[i].vy *= -1;
        }
    }
}

void GCircle::updatePosition(vector<GCircle> &circle, double dt)
{
   for (auto &c : circle)
    {
        c.move(c.vx*dt, c.vy*dt);
    }
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