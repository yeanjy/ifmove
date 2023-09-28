#include <cmath>
#include <iostream>
using namespace std;

#include "window.h"
#include "sdl.h"
#include "gcircle.h"
#include "gsquare.h"
#include "grid.h"
#include "gparticle.h"
#include "gtriangle.h"

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

    Grid grid{Vector3<double>{}, WIDTH-200, HEIGHT-200, 100, 100,
        RGBA<unsigned char>{0xff, 0xff, 0xff, 0x30}
    };

    GSquare square{Vector3<double>{50, 50, 1.0f}, 75, 
        RGBA<unsigned char>{0xff, 0xff, 0x0, 0x99}};

    GTriangle triangle{
        Vector3<double>{0, 0, 1.0f}, 
        Vector3<double>{-150, -50, 1.0f}, 
        Vector3<double>{+150, -50, 1.0f} };

    GParticle particle{
        Vector3<double>{-350, -250, 1.0f},
        Vector3<double>{50.0, 70.0, 0.0f},
        Vector3<double>{0.0, -9.8, 0.0f}, 
        50.0
    };

    vector<Graphics *> graphics;
    graphics.push_back(&grid);
    graphics.push_back(&particle);
    graphics.push_back(&square);
    graphics.push_back(&triangle);

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
            // clear surface before draw
            w.clear();

            // control rotation speed of line
            angle += 0.003;


            /*
            gcircle.draw(w);
            gcircle.transform(translate);*/

            particle.move(dt);

            for (size_t i = 0; i < graphics.size(); i++)
                graphics[i]->draw(w);


            // update renderer
            w.update();
            if ( abs(particle.v.y() - 0) < 1.0/10000 )
                cout << "t = " << t << endl; 
            t += dt;
        } // end of main loop
    } // end of a scope of window

    // return no error to the operating system
    return 0;
}
