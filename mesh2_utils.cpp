#include "mesh2_utils.h"

Mesh2 buildCircleMesh(const Vector3<double> &c, double r, 
    ssize_t n)
{
    Mesh2 tmp{n};
    double frac2Pi = 2*M_PI / n;
    for (int i = 0; i < n; i++)
    {
        tmp.vs.a[0][i] = c.a[0][0] + r * cos(i*frac2Pi);
        tmp.vs.a[1][i] = c.a[1][0] + r * sin(i*frac2Pi);
        tmp.vs.a[2][i] = 1.0;
    }
    for (int i = 0; i < n; i++)
        tmp.es.push_back(pair<size_t, size_t>{i%n, (i+1)%n}); 
    return tmp;
}

Mesh2 buildSquareMesh(const Vector3<double> &r, double l)
{
    Mesh2 tmp{4};
    // top left corner
    tmp.vs.a[0][0] = r.x();
    tmp.vs.a[1][0] = r.y();
    tmp.vs.a[2][0] = 1.0;
    // bottom left corner
    tmp.vs.a[0][1] = r.x();
    tmp.vs.a[1][1] = r.y()-l;
    tmp.vs.a[2][1] = 1.0;
     // bottom right corner
    tmp.vs.a[0][2] = r.x()+l;
    tmp.vs.a[1][2] = r.y()-l;
    tmp.vs.a[2][2] = 1.0;
    // top right corner
    tmp.vs.a[0][3] = r.x()+l;
    tmp.vs.a[1][3] = r.y();
    tmp.vs.a[2][3] = 1.0;
    tmp.es.push_back(pair<size_t, size_t>{0,1});
    tmp.es.push_back(pair<size_t, size_t>{1,2});
    tmp.es.push_back(pair<size_t, size_t>{2,3});
    tmp.es.push_back(pair<size_t, size_t>{3,0});
    return tmp;
}

Mesh2 buildTriangleMesh(const Vector3<double> &p1,
            const Vector3<double> &p2,
            const Vector3<double> &p3)
{
    Mesh2 tmp{3};
    tmp.vs.a[0][0] = p1.x();
    tmp.vs.a[1][0] = p1.y();
    tmp.vs.a[2][0] = 1.0;

    tmp.vs.a[0][1] = p2.x();
    tmp.vs.a[1][1] = p2.y();
    tmp.vs.a[2][1] = 1.0;

    tmp.vs.a[0][2] = p3.x();
    tmp.vs.a[1][2] = p3.y();
    tmp.vs.a[2][2] = 1.0;

    tmp.es.push_back(pair<size_t, size_t>{0,1});
    tmp.es.push_back(pair<size_t, size_t>{1,2});
    tmp.es.push_back(pair<size_t, size_t>{2,0});
    return tmp;
}


