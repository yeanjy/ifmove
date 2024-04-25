#include "particle.h"
#include "vector3.h"

int main()
{
    Vector3<double> r{0.0, 0.0, 1.0f};
    Vector3<double> v{1.0, 1.0, 0.0f};
    Vector3<double> a{0.1, 0.1, 0.0f};
    Particle p{r, v, a};
    cout << p << endl;
    p.move(0.1);
    cout << p << endl;
}
