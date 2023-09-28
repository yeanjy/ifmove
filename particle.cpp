#include "particle.h"
#include <cmath>
       
Particle::Particle(const Vector3<double> &r, const Vector3<double> &v,
        const Vector3<double> &a):
    r{r},
    v{v},
    a{a}
{

}

ostream & operator<<(ostream &out, const Particle &p)
{
    out << "{r=" << p.r << ", v=" << p.v << ", a=" << p.a << "}"; 
    return out;
}
        
void Particle::move(double dt)
{
    v += dt * a;
    r += dt * v;
}
