#include "mesh2.h"

Mesh2::Mesh2(ssize_t n):
    vs{3,n}
{
}


void Mesh2::transform(const Matrix<double> &t)
{
    vs = t * vs;
}

    
Vector3<double> Mesh2::getVertex(ssize_t n) const
{
    assert(n < vs.c);
    return Vector3<double>{vs.a[0][n],vs.a[1][n],vs.a[2][n]};
}

ostream & operator<<(ostream &out, const Mesh2 &m)
{
    out << "Vertexes: " << endl;
    out << m.vs.transpose() << endl;
    out << "Edges: " << endl;
    for (auto it = m.es.begin(); it != m.es.end(); it++)
        cout << "(" << (*it).first << "," << (*it).second << ")" << endl;
    return out;
}



