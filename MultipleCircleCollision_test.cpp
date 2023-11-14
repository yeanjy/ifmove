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
                }
            }
            w.clear();
            mcircle.draw(w);
            for (int i = 0; i < mcircle.Circles.size(); i++)
            {    
                mcircle.Circles[i].imprimir();
                // cout << mcircle.Circles[i].getR() << endl;
            }
            w.update();
        } 
    } 

    return 0;
}
