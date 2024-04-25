#include "gtriangle.h"

#include "mesh2_utils.h"

GTriangle::GTriangle(const Vector3<double> &p1,
            const Vector3<double> &p2,
            const Vector3<double> &p3,
            const RGBA<unsigned char> &rgba):
    GMesh2{buildTriangleMesh(p1, p2, p3), rgba}
{
}
