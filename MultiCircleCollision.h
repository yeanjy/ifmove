#ifndef JI_MULTIPLECIRCLESCOLLISION_JH
#define JI_MULTIPLECIRCLESCOLLISION_JH

#include <iostream>
#include <vector>
#include <random>
#include "gcircle.h"
#include "window.h"
using namespace std;

class mCircles{
    public:
        mCircles();
        void draw(Window &w);
        void setInfo(double vx, double vy, double ax, double ay);
        vector<GCircle> createBalls(int n, const int &height, const int &width);
        static void checkWallColision(vector<GCircle> &circle, const int &width, const int &height);
        static void multipleCollision(vector<GCircle> &circle);
        static void updatePosition(vector<GCircle> &circle, double dt);

        vector<GCircle> Circles;
    private:
        static std::random_device rd;
        static std::mt19937 gen;
};

#endif