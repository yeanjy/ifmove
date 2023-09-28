#include "vector3.h"
#include "circle.h"

int main()
{
    Vector3<double> vc(100.0, 100.0, 1.0);
    Circle c{vc}; 
    cout.precision(3);
    cout.flags(ios_base::fixed);
    cout << c << endl;

    // translation matrix
    Matrix<double> t = Matrix<double>::identity(3);
    // translate 3 units in x direction
    t.a[0][2] = 3.0;

    // scale matrix
    Matrix<double> s = Matrix<double>::identity(3);
    // scale 2 units in x and y direction
    s.a[0][0] = 2.0;
    s.a[1][1] = 2.0;

    Matrix<double> tr = t * s; 

    c.transform(tr);
    cout << c << endl;


}
