#include "matrix.h"

int main()
{
    const int rols = 3;
    const int cols = 7;
    Matrix<double> m1{rols, cols};
    for (int i = 0; i < rols; i++)
        for (int j = 0; j < cols; j++)
            m1.a[i][j] = i * cols + j + 1;

    cout << "aqui" << endl;

    Matrix<double> m2{m1};
    cout.flags(ios_base::fixed);
    cout.precision(5);

    cout << "m1" << endl;
    cout << m1 << endl;
    cout << "m2" << endl;
    cout << m2 << endl;


    cout << "m1 * m2::transpose()" << endl;
    cout << m1 * m2.transpose() << endl;

    cout << "m1 + m2" << endl;
    cout << m1 + m2 << endl;
    
}
