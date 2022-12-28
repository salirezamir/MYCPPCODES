#include <iostream>

using namespace std;

int main()
{
    int a, b, c, tmp = 0;
    cin >> a >> b >> c;
    int Mx1[a][b], Mx2[b][c];
    //, Mxr[a][c];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            cin >> Mx1[i][j];
    }
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> Mx2[i][j];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // Mxr[i][j]=0;
            tmp = 0;
            for (int k = 0; k < b; k++)
                tmp += Mx1[i][k] * Mx2[k][j];
            // Mxr[i][j]+=Mx1[i][k]*Mx1[k][j];
            cout << tmp << " ";
        }
        cout << endl;
    }
}