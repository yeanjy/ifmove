#include "gsquare.h"
#include "mesh2_utils.h"

GSquare::GSquare(const Vector3<double> &r, double l, 
        const RGBA<unsigned char> &rgba):
    GMesh2{buildSquareMesh(r, l), rgba},
    c{r.x()-l/2, r.y()-l/2, 1.0f},
    l{l}
{}
