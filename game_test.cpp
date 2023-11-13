#include <iostream>
#include <cmath>

#include "shape.h"
#include "window.h"
#include "sdl.h"
#include "gcircle.h"
#include "gsquare.h"
#include "grid.h"
#include "gparticle.h"
#include "gtriangle.h"
#include "vector3.h"
#include "game.h"
using namespace std;

#define WIDTH 1200
#define HEIGHT 800

void circlesMovimation(game& g, double dt)
{
    for(int i = 0; i < g.circles.size(); i++)
    {
        g.circles[i].move(0, -dt*g.circles[i].vy);

        if (g.circles[i].floorCollision(HEIGHT))
            g.circles[i].vy *= -1;
    }
}

int main()
{
    SDL sdl;

    bool quit = false;

    SDL_Event e;

    GCircle circle1{Vector3<double>{-400, 350, 1.0f}, 30, 100};
    GCircle circle2{Vector3<double>{-200, 350, 1.0f}, 30, 100};
    GCircle circle3{Vector3<double>{0, 350, 1.0f}, 30, 100};
    GCircle circle4{Vector3<double>{200, 350, 1.0f}, 30, 100};
    GCircle circle5{Vector3<double>{400, 350, 1.0f}, 30, 100};

    game game1{};

    game1.main = GCircle{Vector3<double>{-550, 0, 1.0f}, 30, 100};
    
    game1.addCircle(circle1);
    game1.addCircle(circle2);   
    game1.addCircle(circle3);
    game1.addCircle(circle4);
    game1.addCircle(circle5);

    game1.setVelocity(100);

    {
        Window w(WIDTH, HEIGHT);
        Matrix<double> transform = w.transform();
        transform.a[1][1] = -1 * transform.a[1][1];
        transform.a[0][2] = WIDTH/2;
        transform.a[1][2] = HEIGHT/2;
        

        w.transform(transform);
        while (!quit) 
        {
            while(SDL_PollEvent(&e) != 0)
            {
                if(e.type == SDL_QUIT)
                    quit = true;

                if(e.type == SDL_KEYDOWN)
                {       
                    if (e.key.keysym.sym == SDLK_q)
                        quit = true;
                    if (e.key.keysym.sym == SDLK_UP)
                    { 
                        game1.main.move(0, 10);
                    }
                    if (e.key.keysym.sym == SDLK_DOWN)
                    { 
                        game1.main.move(0, -10);
                    }
                    if (e.key.keysym.sym == SDLK_LEFT)
                    { 
                        game1.main.move(-10, 0);
                    }
                    if (e.key.keysym.sym == SDLK_RIGHT)
                    { 
                        game1.main.move(+10, 0);
                    }
                }
            }
            w.clear();
            game1.draw(w);
            circlesMovimation(game1, 0.01);
            game1.checkCollision(quit);
            w.update();
        } 
    } 

    return 0;
}
