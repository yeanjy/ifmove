#include "window.h"
#include <iostream>
#include <cassert>
using namespace std;

Window::Window(int width, int height):
    width{width},
    height{height},
    _transform{Matrix<double>::identity(3)},
    bgColor{0x15, 0x15, 0x15, 0xff},
    drawColor{0xff, 0xff, 0xff, 0xff}
{
    // creating a sdl window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

    if (window == NULL)
    {
        // the window was not created
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        // return error level 1 to operating system
        exit(1);
    }
    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

Window::~Window()
{
    // cout << "~Window() called" << endl;
    //Destroy window
    SDL_DestroyWindow(window);
}

void Window::drawLine(int ix, int iy, int fx, int fy)
{
    _drawLine(Vector3<double>{static_cast<double>(ix), static_cast<double>(iy), 1.0f}, Vector3<double>{static_cast<double>(fx), static_cast<double>(fy), 1.0f});
}

void Window::drawLine(int ix, int iy, int fx, int fy, 
    const RGBA<unsigned char> &rgba)
{
    drawLine(Vector3<double>{static_cast<double>(ix), static_cast<double>(iy), 1.0f}, 
        Vector3<double>{static_cast<double>(fx), static_cast<double>(fy), 1.0f}, rgba);
}

void Window::drawLine(const Vector3<double> &i, const Vector3<double> &f)
{
    _drawLine(i, f);
}


void Window::drawLine(const Vector3<double> &i, 
    const Vector3<double> &f, const RGBA<unsigned char> &rgba)
{
    SDL_SetRenderDrawColor(renderer, rgba.r, rgba.g, 
        rgba.b, rgba.a);
    _drawLine(i, f);
    SDL_SetRenderDrawColor(renderer, drawColor.r,
        drawColor.g, drawColor.b, drawColor.a);
}

void Window::_drawLine(const Vector3<double> &i, const Vector3<double> &f)
{
    Vector3<double> it = _transform * i;
    Vector3<double> ft = _transform * f;
    int ix = static_cast<int>(it.a[0][0]);
    int iy = static_cast<int>(it.a[1][0]);
    int fx = static_cast<int>(ft.a[0][0]);
    int fy = static_cast<int>(ft.a[1][0]);
    SDL_RenderDrawLine(renderer, ix, iy, fx, fy);
}

void Window::clear()
{
    //Clear screen
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, 
        bgColor.b, bgColor.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, drawColor.r,
        drawColor.g, drawColor.b, drawColor.a);
}

void Window::update()
{
    //Update screen
    SDL_RenderPresent(renderer);
}

Matrix<double> Window::transform()
{
    return _transform;
}

void Window::transform(const Matrix<double> &t)
{
    assert(t.r == 3 && t.c ==3);
    _transform = t;
}

void Window::setDrawColor(const RGBA<unsigned char> &rgba)
{
    SDL_SetRenderDrawColor(renderer, rgba.r, rgba.g, 
        rgba.b, rgba.a);
}
