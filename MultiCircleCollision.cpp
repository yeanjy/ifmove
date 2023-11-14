#include "MultiCircleCollision.h"

mCircles::mCircles()
{}

void mCircles::draw(Window w)
{
    for (int i = 0; i < Circles.size(); i++)
    {
        Circles[i].draw(w);
    }
}

vector<GCircle> mCircles::createBalls(int n, const int &height, const int &width, double r)
{
    for (int i = 0; i < n; i++)
    {
        Circles.emplace_back(Vector3<double>{static_cast<double>(rand() % width), static_cast<double>(rand() % height), 1.f}, r);
    }
    return Circles;
}