#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    string A[k], B[k - 1];
    for (int i = 0; i < k; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < k - 1; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < k; i++)
    {
        // if (A[i] != find(B[0], B[k - 2], A[i]))
        // {
        //     cout << A[i];
        // }
    }
}