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
    for (int i = 1; i <= n / 2; i++)
    {
        if (i != 1)
            cout << "\n";
        for (int j = 1; 2 * j <= n - nn(i); j++)
            cout << " ";
        for (int j = 1; j <= nn(i); j++)
            cout << "*";
        for (int j = 1; j <= n - nn(i); j++)
            cout << " ";
        for (int j = 1; j <= nn(i); j++)
            cout << "*";
    }
    cout << "\n";
    for (int j = 1; j <= 2 * n; j++)
        cout << "*";
    for (int i = n / 2; i >= 1; i--)
    {
        cout << "\n";
        for (int j = 1; 2 * j <= n - nn(i); j++)
            cout << " ";
        for (int j = 1; j <= nn(i); j++)
            cout << "*";
        for (int j = 1; j <= n - nn(i); j++)
            cout << " ";
        for (int j = 1; j <= nn(i); j++)
            cout << "*";
    }
}