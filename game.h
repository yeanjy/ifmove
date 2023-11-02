#ifndef JI_GAME_JH
#define JI_GAME_JH

#include <iostream>
#include <vector>
#include "gcircle.h"
#include "window.h"
using namespace std;

class game{
public:
    game();
    bool colision(GCircle &a, GCircle &b);
    void draw(Window &window);
    void addCircle (GCircle &circle);

    vector<GCircle> circles;
};


#endif