#include <SDL.h>
#include "sdl.h"

#include <iostream>
using namespace std;

SDL::SDL()
{
    init();
}

SDL::~SDL()
{
    cout << "~SDL() called" << endl;
    quit();
}

bool SDL::init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        // exit program returning error level 1 to operating system
        exit(1);
        return false;
    }
    return true;
}

bool SDL::quit()
{
    //Quit SDL subsystems
    SDL_Quit();
    return true;
}
