#include "forma.h"
#include <iostream>
using namespace std;
#include "matrix.h"

FormaComposta::FormaComposta()
{}

void FormaComposta::draw(Window &window)
{
    Matrix<double> translate = Matrix<double>::identity(3);
    translate.a[0][2] = center.x();
    translate.a[1][2] = center.y();

    for (int i =0 ; i < formas.size(); i++)
    {
        formas[i].draw(window, translate); 
    }
}

void FormaComposta::addForma(GMesh2 &forma)
{
    formas.push_back(forma);
    cout << "adicionando forma\n";
}


