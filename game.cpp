#include "game.h"
#include <cmath>

game::game()
{}

void game::draw(Window &window)
{
    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].draw(window);
    }    
}

void game::addCircle (GCircle &circle)
{
    circles.push_back(circle);
}

// bool game::colision(GCircle &a, GCircle &b)
// {
//     return a.c + b.c >= abs(a.c - b.c); 
// }