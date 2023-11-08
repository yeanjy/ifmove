#include "gcircle.h"

#include "mesh2_utils.h"

GCircle::GCircle(const Vector3<double> &c, double r, 
            ssize_t n, const RGBA<unsigned char> &rgba):
    GMesh2{buildCircleMesh(c,r,n), rgba}, c(c), r(r)
{
}
