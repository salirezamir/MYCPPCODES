#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long n, f1 = 1, f2 = 1, i = 1, fx = 1, j = 3;
    cin >> n;
    if (n == 0)
    {
        fx = 0;
        j = n + 1;
    }
    while (j <= n)
    {
        if (n == 1 || n == 2)
        {
            fx = 1;
            break;
        }
        fx = (f1 + f2) % 10;
        f2 = f1 % 10;
        f1 = fx % 10;
        j++;
    }
    cout << fx % 10;
}