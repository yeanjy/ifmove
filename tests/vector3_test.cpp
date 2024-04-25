#include "vector3.h"
#include <iostream>
using namespace std;

int main()
{
    Vector3<double> v{1.0, 2.0, 3.0};
    // multiplicação por escalar
    cout << 3.0 * v << endl;
    return 0;
}
