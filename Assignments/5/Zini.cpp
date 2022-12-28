#include <iostream>

using namespace std;

int main()
{
    int m, n, zini = 0;
    cin >> m >> n;
    unsigned long table[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if ((table[i][j] > table[i][j - 1] && table[i][j] > table[i][j + 1] && table[i][j] < table[i - 1][j] && table[i][j] < table[i + 1][j]) || (table[i][j] < table[i][j - 1] && table[i][j] < table[i][j + 1] && table[i][j] > table[i - 1][j] && table[i][j] > table[i + 1][j]))
                zini++;
        }
    }
    cout << zini;
    return 0;
}