#include <iostream>

using namespace std;

int main()
{
    int n, m;
    long opt = 0;
    cin >> n >> m;
    for (int i = -10; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            opt += ((i + j) * (i + j) * (i + j)) / (j * j);
    }
    cout << opt;
}