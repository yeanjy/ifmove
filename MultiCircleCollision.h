#ifndef JI_MULTIPLECIRCLESCOLLISION_JH
#define JI_MULTIPLECIRCLESCOLLISION_JH

#include <iostream>
#include <vector>
#include "gcircle.h"
#include "window.h"
using namespace std;

class mCircles{
    public:
        mCircles();
        void draw(Window w);
        vector<GCircle> createBalls(int n, const int &height, const int &width, double r);

        vector<GCircle> Circles;
};

#endif