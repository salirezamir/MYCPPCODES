#include <iostream>

using namespace std;

int main()
{
    int nC, mC;
    cin >> nC >> mC;
    int nN[nC], mN[mC], Out[nC + mC];
    for (int i = 0; i < nC; i++)
        cin >> nN[i];
    for (int i = 0; i < mC; i++)
        cin >> mN[i];
    for (int i = 0; i < nC; i++)
        Out[i] = nN[i];
    for (int i = nC; i < nC + mC; i++)
        Out[i] = mN[i - nC];
    for (int i = 0; i < mC + nC; i++)
        cout << Out[i] << " ";
}