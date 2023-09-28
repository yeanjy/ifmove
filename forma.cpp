#include "forma.h"
#include <iostream>
using namespace std;

FormaComposta::FormaComposta()
{}

void FormaComposta::draw(Window &window)
{
    for (int i =0 ; i < formas.size(); i++)
    {
        formas[i].draw(window); 
    }
}

void FormaComposta::addForma(GMesh2 &forma)
{
    formas.push_back(forma);
    cout << "adicionando forma\n";
}


