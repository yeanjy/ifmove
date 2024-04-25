#include "gparticle.h"
#include "arrow2.h"

GParticle::GParticle(const Vector3<double> &r,
        const Vector3<double> &v,
        const Vector3<double> &a,
        double radius):
    Particle{r, v, a},
    // creating a circle at origin, position will be 
    // used to translate the circle to position
    circle{Vector3<double>{0.0, 0.0, 1.0}, radius}
{
}

void GParticle::draw(Window &w)
{
    Graphics::draw(w);
    Matrix<double> t = Matrix<double>::identity(3);
    t.a[0][2] = r.x();
    t.a[1][2] = r.y();
    circle.draw(w, t);
    Arrow2 ra{Vector3<double>{0, 0, 1.0}, r, 
        RGBA<unsigned char>{0xff, 0xff, 0xff, 0x77}};
    ra.draw(w);
    Arrow2 va{r, r+v, 
        RGBA<unsigned char>{0xff, 0x00, 0x00, 0x77}};
    va.draw(w);
    Arrow2 aa{r, r+a,
        RGBA<unsigned char>{0x00, 0x00, 0xff, 0x77}};
    aa.draw(w);
}
        
void GParticle::move(double dt)
{
    Particle::move(dt);
}
