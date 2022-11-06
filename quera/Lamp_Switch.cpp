#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, oh = 0;
    cin >> n;
    int Status[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Status[i];
        if (i != 0 && abs(Status[i] - Status[i - 1]) == 1)
        {
            oh++;
        }
    }
    cout << oh;
    return 1;
}