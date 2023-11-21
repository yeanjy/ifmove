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

void game::checkCollision(bool &a, const int& width)
{
    for (int i = 0; i < circles.size(); i++)
    {
        if (GCircle::collision(main, circles[i]))
        {
            a = !a;
            cout << "You lost" << endl;
        }

    }

    if (main.getcX() == width/2)
    {
        a = !a;
        cout << "You win" << endl;
    } 
}

void game::setVelocity(int v)
{
    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].vy = (i+1)*v;
    }
}