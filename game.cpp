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

    if (main.c.x() == width/2 - main.r)
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

void game::checkWallColision(const int &width, const int &height)
{
    if (main.c.x() + main.r >= width/2)
    {
        main.move(-(main.c.x() - (width/2 - main.r)), 0);
    }
    if (main.c.x() - main.r <= -width/2)
    {
        main.move((-main.c.x() + (-width/2 + main.r)), 0);
    }
    if(main.c.y() + main.r >= height/2)
    {
        main.move(0, -(main.c.y() - (height/2 - main.r)));
    }
    if(main.c.y() - main.r <= -height/2)
    {
        main.move(0, (-main.c.y() + (-height/2 + main.r)));
    }
}