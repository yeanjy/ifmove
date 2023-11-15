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

vector<GCircle> mCircles::createBalls(int n, const int &height, const int &width, double r)
{
    std::uniform_real_distribution<double> distX(-width/2, width/2);
    std::uniform_real_distribution<double> distY(-height/2, height/2);

    for (int i = 0; i < n; i++)
    {
        double x = distX(gen); 
        double y = distY(gen); 

        Circles.emplace_back(Vector3<double>{x, y, 1.f}, r);
    }
    return Circles;
}

void mCircles::setInfo(double vx, double vy, double ax, double ay, double mass)
{
    for (int i = 0; i < Circles.size(); i++)
    {
        Circles[i].vx = vx;
        Circles[i].vy = vy;
        Circles[i].ax = ax;
        Circles[i].ay = ay;
        Circles[i].mass = mass;
    }
}

std::random_device mCircles::rd;
std::mt19937 mCircles::gen(mCircles::rd());