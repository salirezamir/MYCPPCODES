#include <iostream>

using namespace std;

int main()
{
    int nC, index = 0, max;
    cin >> nC;
    int nN[nC];
    for (int i = 0; i < nC; i++)
        cin >> nN[i];
    max = nN[0];
    for (int i = 0; i < nC; i++)
    {
        if (max < nN[i])
        {
            max = nN[i];
            index = i;
        }
    }
    cout << max << " " << index;
}