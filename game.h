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
    void checkCollision(bool &a);
    void draw(Window &window);
    void addCircle (GCircle &circle);
    void updatee(double dt, bool a);
    void setVelocity(int v);

    GCircle main{Vector3<double>{0, 0, 1.0f}, 30, 100};
    vector<GCircle> circles;
};


#endif