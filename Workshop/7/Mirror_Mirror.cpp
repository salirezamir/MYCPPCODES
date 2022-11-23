#include <iostream>

using namespace std;

int nn(int n)
{
    return 2 * n - 1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; 2 * j <= nn(n) - nn(i); j++)
            cout << " ";
        for (int j = i; j <= nn(i); j++)
            cout << j;
        for (int j = nn(i) - 1; j >= i; j--)
            cout << j;
        for (int j = 1; 2 * j <= nn(n) - nn(i); j++)
            cout << " ";
        cout << "\n";
    }
}