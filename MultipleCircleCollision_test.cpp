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

    mcircle.createBalls(20, HEIGHT, WIDTH, 50);
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
            GCircle::multipleCollision(mcircle.Circles);
            w.update();
        } 
    } 

    return 0;
}
