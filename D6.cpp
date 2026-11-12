#include <iostream>
#include <iomanip>
// This is written based on the orientation of D6 explained in the work of Faber and Nazemian, *The Number of Ones in Mesh Friezes of Type E7, 2026
using namespace std;

void all(double a[], int n, int &m)
{
    // Count the number of ones in the current column
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            m++;
        }
    }

    // Calculate the next column
    double a1, a2, a3, a4, a5, a6;

    a1 = (1 + a[2]) / a[0];
    a2 = (1 + a[2]) / a[1];
    a3 = (1 + (a1 * a2 * a[3])) / a[2];
    a4 = (1 + a3 * a[4]) / a[3];
    a5 = (1 + a4 * a[5]) / a[4];
    a6 = (1 + a5) / a[5];

    a[0] = a1;
    a[1] = a2;
    a[2] = a3;
    a[3] = a4;
    a[4] = a5;
    a[5] = a6;
}

int main()
{
    cout << "Enter the 6 integers:" << endl;

    double a[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }

    int m = 0;

    // Define a 6 x 6 matrix
    double A[6][6];

    for (int j = 0; j < 6; j++)
    {
        // Store the current column
        for (int i = 0; i < 6; i++)
        {
            A[i][j] = a[i];
        }

        // Calculate the next column
        all(a, 6, m);
    }

    // Print the 6 x 6 matrix
    cout << "\nThe 6 x 6 matrix is:\n\n";

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << setw(3) << setprecision(6) << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nThe number of ones is: " << m << endl;

    return 0;
}


