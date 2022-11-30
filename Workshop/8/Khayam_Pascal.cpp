#include <iostream>

using namespace std;

int fact(int n)
{
    if (n < 0)
        return -1; 
    if (n == 0)
        return 1; 
    else
    {
        return (n * fact(n - 1));
    }
}

int comb(int n, int k)
{
    return (fact(n) / (fact(k) * fact(n - k)));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << comb(i, j);
            if (j != i)
                cout << " ";
        }
        if (i != n)
            cout << endl;
    }
}