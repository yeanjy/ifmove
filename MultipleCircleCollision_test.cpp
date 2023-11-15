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
#include "MultiCircleCollision.h"
using namespace std;

#define WIDTH 1200
#define HEIGHT 800


int main()
{
    SDL sdl;

    bool quit = false;

    SDL_Event e;

    mCircles mcircle{};

    mcircle.createBalls(10, HEIGHT, WIDTH, 50);

    mcircle.setInfo(80, 80, 10, 10, 800);
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
                        mcircle.Circles[1].move(0, 10);
                    }
                    if (e.key.keysym.sym == SDLK_DOWN)
                    { 
                        mcircle.Circles[1].move(0, -10);
                    }
                    if (e.key.keysym.sym == SDLK_LEFT)
                    { 
                        mcircle.Circles[1].move(-10, 0);
                    }
                    if (e.key.keysym.sym == SDLK_RIGHT)
                    { 
                        mcircle.Circles[1].move(+10, 0);
                    }
                }
            }
            w.clear();
            mcircle.draw(w);
            GCircle::checkWallColision(mcircle.Circles, WIDTH, HEIGHT);
            GCircle::multipleCollision(mcircle.Circles);
            GCircle::updatePosition(mcircle.Circles, 0.01);
            w.update();
        } 
    } 

    return 0;
}
