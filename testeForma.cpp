#include <cmath>
#include <iostream>
using namespace std;
#include "forma.h"
#include "window.h"
#include "sdl.h"
#include "gcircle.h"
#include "gsquare.h"
#include "grid.h"
#include "gparticle.h"
#include "gtriangle.h"
#include "vector3.h"

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

    double angle = 0.0;
    double t = 0;
    double dt = 4.0/10000.0;

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

    FormaComposta forma{};
    forma.center = Vector3<double>{+150, -50, 1.0f};
    forma.rotate = 0;
    forma.addForma(square0);
    forma.addForma(square1);
    forma.addForma(wheel0);
    forma.addForma(wheel1);
    forma.addForma(circle);
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
                        forma.center += Vector3<double>{-10, 0, 0};
                    if (e.key.keysym.sym == SDLK_RIGHT)
                        forma.center += Vector3<double>{10, 0, 0};
                    if (e.key.keysym.sym == SDLK_UP)
                        forma.center += Vector3<double>{0, 10, 0};
                    if (e.key.keysym.sym == SDLK_DOWN)
                        forma.center += Vector3<double>{0, -10, 0};

                    if (e.key.keysym.sym == SDLK_r)
                        forma.rotate += 0.03;
                    if (e.key.keysym.sym == SDLK_t)
                        forma.rotate -= 0.03;

                    if (e.key.keysym.sym == SDLK_s)
                        forma.shear_x -= .1;
                    if (e.key.keysym.sym == SDLK_x)
                        forma.shear_y -= .1;
                    if (e.key.keysym.sym == SDLK_d)
                        forma.shear_x += .1;
                    if (e.key.keysym.sym == SDLK_c)
                        forma.shear_y += .1;
                }
            }
            // clear surface before draw
            w.clear();

            // control rotation speed of line
            angle += 0.003;
            
            forma.draw(w);


            // update renderer
            w.update();
             t += dt;
        } // end of main loop
    } // end of a scope of window

    // return no error to the operating system
    return 0;
}
