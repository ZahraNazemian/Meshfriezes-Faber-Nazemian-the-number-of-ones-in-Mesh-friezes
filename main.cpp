#include <iostream>
using namespace std;
// This is written based on the orientation of E6 explained in the work of Faber and Nazemian, *The Number of Ones in Mesh Friezes of Type E7, 2026
void mesh(int &f1, int &f2, int &f3,
          int &f4, int &f5, int &f6, int &m)
{
    int F1 = ((f4 + 1) / f1);
    int F2 = ((f3 + 1) / f2);
    int F3 = (((F2 * f4) + 1) / f3);
    int F4 = (((F1 * F3 * f5) + 1) / f4);
    int F5 = (((F4 * f6) + 1) / f5);
    int F6 = ((F5 + 1) / f6);

    f1 = F1;
    if (f1 == 1) m++;

    f2 = F2;
    if (f2 == 1) m++;

    f3 = F3;
    if (f3 == 1) m++;

    f4 = F4;
    if (f4 == 1) m++;

    f5 = F5;
    if (f5 == 1) m++;

    f6 = F6;
    if (f6 == 1) m++;
}

int main()
{
    int m = 0;

    cout << "Enter 6 entries (as the first column):" << endl;

    int f1, f2, f3, f4, f5, f6;
    cin >> f1 >> f2 >> f3 >> f4 >> f5 >> f6;

    // 6 rows x 14 columns
    int a[6][14];

    for (int i = 0; i < 14; i++)
    {
        // Store the current six values in column i
        a[0][i] = f1;
        a[1][i] = f2;
        a[2][i] = f3;
        a[3][i] = f4;
        a[4][i] = f5;
        a[5][i] = f6;

        // Calculate the next six values
        mesh(f1, f2, f3, f4, f5, f6, m);
    }

    // Print the 6 x 14 array
    cout << "\nArray:\n\n";

    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 14; col++)
        {
            cout << a[row][col] << "\t";
        }
        cout << endl;
    }

    cout << "\nThe number of ones is: " << m << endl;

    return 0;
}

