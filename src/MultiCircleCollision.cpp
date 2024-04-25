#include "MultiCircleCollision.h"

mCircles::mCircles()
{}

void mCircles::draw(Window &w)
{
    for (int i = 0; i < Circles.size(); i++)
    {
        Circles[i].draw(w);
    }
}

vector<GCircle> mCircles::createBalls(int n, const int &height, const int &width)
{
    std::uniform_real_distribution<double> distX(-width/2, width/2);
    std::uniform_real_distribution<double> distY(-height/2, height/2);
    std::uniform_real_distribution<double> randomN(10, 100);

    for (int i = 0; i < n; i++)
    {
        double x = distX(gen); 
        double y = distY(gen); 
        double r = randomN(gen);

        Circles.emplace_back(Vector3<double>{x, y, 1.f}, r);
    }
    return Circles;
}

void mCircles::checkWallColision(vector<GCircle> &circle, const int &width, const int &height)
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

void mCircles::multipleCollision(vector<GCircle> &circle)
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

                    // double tx = -ny;
                    // double ty = nx;

                    // double dpTan1 = circle[i].vx*tx + circle[i].vy*ty;
                    // double dpTan2 = circle[j].vx*tx + circle[j].vy*ty;

                    // double dpNorm1 = circle[i].vx*nx + circle[i].vy*ny;
                    // double dpNorm2 = circle[j].vx*nx + circle[j].vy*ny;

                    // double m1 = ((dpNorm1*(circle[i].mass - circle[j].mass)) + 2.f*circle[j].mass*dpNorm2) / (circle[i].mass + circle[j].mass);
                    // double m2 = ((dpNorm2*(circle[j].mass - circle[i].mass)) + 2.f*circle[i].mass*dpNorm1) / (circle[i].mass + circle[j].mass);

                    // circle[i].vx = tx*dpTan1 + nx*m1;
                    // circle[i].vy = ty*dpTan1 + ny*m1;
                    // circle[j].vx = tx*dpTan2 + nx*m2;
                    // circle[j].vy = ty*dpTan2 + nx*m2;

                    double kx = (circle[i].vx - circle[j].vx);
                    double ky = (circle[i].vy - circle[j].vy);
                    double p = 2.0*(nx*kx + ny*ky) / (circle[i].mass + circle[j].mass);
                    circle[i].vx -= p*circle[j].mass * nx;
                    circle[i].vy -= p*circle[j].mass * ny;

                    circle[j].vx += p*circle[i].mass * nx;
                    circle[j].vy += p*circle[i].mass * ny;
                }
            }
        }
    }
}

void mCircles::updatePosition(vector<GCircle> &circle, double dt)
{
   for (auto &c : circle)
    {
        c.vx += c.ax * dt;
        c.vy += c.ay * dt;
        c.move(c.vx * dt, c.vy * dt);
    }
}

void mCircles::setInfo(double vx, double vy, double ax, double ay)
{
    for (int i = 0; i < Circles.size(); i++)
    {
        Circles[i].vx = vx;
        Circles[i].vy = vy;
        Circles[i].ax = ax;
        Circles[i].ay = ay;
        Circles[i].mass = 10*Circles[i].getR();
    }
}

std::random_device mCircles::rd;
std::mt19937 mCircles::gen(mCircles::rd());