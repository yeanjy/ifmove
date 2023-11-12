#include "game.h"
#include <cmath>

game::game()
{}

void game::draw(Window &window)
{
    main.draw(window);

    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].draw(window);
    }
}

void game::addCircle (GCircle &circle)
{
    circles.push_back(circle);
}

void game::checkCollision(bool &a)
{
    for (int i = 0; i < circles.size(); i++)
    {
        if (GCircle::collision(main, circles[i]))
            a = !a; 
    }
}

void game::updatee(double dt, bool a)
{
    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].move(0, -dt*circles[i].vy);
        if (a)
            circles[i].vy *= -1;
    }
}

void game::setVelocity(int v)
{
    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].vy = (i+1)*v;
    }
}