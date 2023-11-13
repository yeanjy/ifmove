#ifndef JI_MCIRCLES_JH
#define JI_MCIRCLES_JH

#include <iostream>
#include <vector>
#include "gcircle.h"
#include "window.h"
using namespace std;

class mCircles{
    public:
        mCircles();
        bool wallDetection(int height, int width);
        vector<GCircle> myCircles;


};







#endif