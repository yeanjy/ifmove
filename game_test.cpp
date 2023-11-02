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

int main()
{
    // create a SDL object
    SDL sdl;
    // quit will control the main loop (game loop)
    bool quit = false;

    // Event handler, it'll handle keyboard and mouse events
    SDL_Event e;

    GCircle mainCircle{Vector3<double>{-500, 0, 1.0f}, 30, 100}; 
    GCircle circle1{Vector3<double>{-100, 0, 1.0f}, 30, 100};
    GCircle circle2{Vector3<double>{100, 0, 1.0f}, 30, 100};
    GCircle circle3{Vector3<double>{300, 0, 1.0f}, 30, 100};
    GCircle circle4{Vector3<double>{400, 0, 1.0f}, 30, 100};
    GCircle circle5{Vector3<double>{500, 0, 1.0f}, 30, 100};

    game game1{};

    game1.addCircle(circle1);
    game1.addCircle(circle2);
    game1.addCircle(circle3);
    game1.addCircle(circle4);
    game1.addCircle(circle5);


    // new scope to control when the window w will be destroyed
    {
        Window w(WIDTH, HEIGHT);
        Matrix<double> transform = w.transform();
        transform.a[1][1] = -1 * transform.a[1][1];
        transform.a[0][2] = WIDTH/2;
        transform.a[1][2] = HEIGHT/2;
        
        w.transform(transform);
        // main loop
        while (!quit) 
        {
            // Handle events on event queue
            while(SDL_PollEvent(&e) != 0)
            {
                // User requests quit
                if(e.type == SDL_QUIT)
                    quit = true;
                // Keydown Event
                if(e.type == SDL_KEYDOWN)
                {       
                    // pressing q will exit the main loop
                    if (e.key.keysym.sym == SDLK_q)
                        quit = true;
                }
            }
            w.clear();

            game1.draw(w);

            w.update();
        } 
    } 

    return 0;
}
