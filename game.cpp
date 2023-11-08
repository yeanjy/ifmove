#include "game.h"
#include <cmath>

game::game()
{}

void game::draw(Window &window)
{
    Matrix<double> translate = Matrix<double>::identity(3);
    translate.a[0][2] = main.c.x();
    translate.a[1][2] = main.c.y();

    main.draw(window, translate);

    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].draw(window);
    }    
}

void game::addCircle (GCircle &circle)
{
    circles.push_back(circle);
}

bool game::collision(GCircle &a, GCircle &b)
{
    double distance = sqrt(pow((a.c.x() - b.c.x()), 2) + pow((a.c.y() - b.c.y()), 2));
    double sumRadii = a.r + b.r;

    return distance <= sumRadii;
}


void game::checkCollision()
{
    for (int i = 0; i < circles.size(); i++)
    {
        if ((game::collision(main, circles[i])))
            std::cout << "colidiu" << std::endl;
        else 
            std::cout << "nao colidiu" << std::endl;
    }
}