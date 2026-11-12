#include <iostream>
#include <iomanip>
// This is written based on the orientation of E6 explained in the work of Faber and Nazemian, *The Number of Ones in Mesh Friezes of Type E7, 2026
using namespace std;

void mesh(double &f1, double &f2, double &f3,
          double &f4, double &f5, double &f6,
          double &f7, int &m)
{
    double F1 = (1 + f4) / f1;
    double F2 = (1 + f3) / f2;
    double F3 = (1 + F2 * f4) / f3;
    double F4 = (1 + F1 * F3 * f5) / f4;
    double F5 = (1 + F4 * f6) / f5;
    double F6 = (1 + F5 * f7) / f6;
    double F7 = (1 + F6) / f7;

    f1 = F1;
    f2 = F2;
    f3 = F3;
    f4 = F4;
    f5 = F5;
    f6 = F6;
    f7 = F7;

    if (f1 == 1) m++;
    if (f2 == 1) m++;
    if (f3 == 1) m++;
    if (f4 == 1) m++;
    if (f5 == 1) m++;
    if (f6 == 1) m++;
    if (f7 == 1) m++;
}

int main()
{
    int m = 0;

    cout << "Enter 7 entries (as the first column):" << endl;

    double f1, f2, f3, f4, f5, f6, f7;
    cin >> f1 >> f2 >> f3 >> f4 >> f5 >> f6 >> f7;

    double A[7][10];

    for (int j = 0; j < 10; j++)
    {
        A[0][j] = f1;
        A[1][j] = f2;
        A[2][j] = f3;
        A[3][j] = f4;
        A[4][j] = f5;
        A[5][j] = f6;
        A[6][j] = f7;

        mesh(f1, f2, f3, f4, f5, f6, f7, m);
    }

    cout << "\nThe 7 x 10 matrix is:\n\n";

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << setw(3) << setprecision(6)
                 << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nNumber of ones is equal to " << m << endl;

    return 0;
}


