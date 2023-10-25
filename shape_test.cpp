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

    /*
    GCircle gcircle{Vector3<double>{-250, -250}, 50, 30, 
        RGBA<unsigned char>{0x0, 0x0, 0xff, 0xff}};
    gcircle.eColor(0, RGBA<unsigned char>{255, 0, 255, 255});
    gcircle.eColor(1, RGBA<unsigned char>{255, 0, 255, 255});
    gcircle.eColor(2, RGBA<unsigned char>{255, 0, 255, 255});
    Matrix<double> translate = Matrix<double>::identity(3);
    translate.a[0][2] = 0.05;
    translate.a[1][2] = 0.05;
    */

    double car_height = 250;

    GSquare square0{Vector3<double>{-car_height, car_height/2, 1.0f}, car_height, 
        RGBA<unsigned char>{0xff, 0xff, 0x0, 0x99}};
    GSquare square1{Vector3<double>{0, car_height/2, 1.0f}, car_height, 
        RGBA<unsigned char>{0xff, 0xff, 0x0, 0x99}};
    GCircle wheel0{Vector3<double>{-car_height/2, -car_height/2, 1.0f}, car_height/4, 30, 
        RGBA<unsigned char>{0xff, 0xff, 0x0, 0x99}};
    GCircle wheel1{Vector3<double>{car_height/2, -car_height/2, 1.0f}, car_height/4 , 30,
        RGBA<unsigned char>{0xff, 0xff, 0x0, 0x99}};
    GCircle circle{Vector3<double>{0,0,1}, 15};

    CompoundShape shape{};
    shape.center = Vector3<double>{+150, -50, 1.0f};
    shape.rotate = 0;
    shape.addShape(square0);
    shape.addShape(square1);
    shape.addShape(wheel0);
    shape.addShape(wheel1);
    shape.addShape(circle);
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
                    if (e.key.keysym.sym == SDLK_LEFT)
                        shape.center += Vector3<double>{-10, 0, 0};
                    if (e.key.keysym.sym == SDLK_RIGHT)
                        shape.center += Vector3<double>{10, 0, 0};
                    if (e.key.keysym.sym == SDLK_UP)
                        shape.center += Vector3<double>{0, 10, 0};
                    if (e.key.keysym.sym == SDLK_DOWN)
                        shape.center += Vector3<double>{0, -10, 0};

                    if (e.key.keysym.sym == SDLK_r)
                        shape.rotate += 0.03;
                    if (e.key.keysym.sym == SDLK_t)
                        shape.rotate -= 0.03;

                    if (e.key.keysym.sym == SDLK_s)
                        shape.shear_x -= .1;
                    if (e.key.keysym.sym == SDLK_x)
                        shape.shear_y -= .1;
                    if (e.key.keysym.sym == SDLK_d)
                        shape.shear_x += .1;
                    if (e.key.keysym.sym == SDLK_c)
                        shape.shear_y += .1;
                }
            }
            // clear surface before draw
            w.clear();

            shape.draw(w);


            // update renderer
            w.update();
        } 
    } 

    return 0;
}
