#include <iostream>
#include <cmath>

using namespace std;

double t;

double fact(int n)
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

double Cos(int m)
{
    if (m % 2 != 0)
        m -= 1;
    if (m == 0)
        return 1;
    return ((pow(t, m) * pow(-1, (m / 2) % 2)) / fact(m) + Cos(m - 2));
}

int main()
{
    double f, d;
    cin >> f >> d >> t;
    t = t * 3.14 / 180;
    printf("%.2f", d * f * Cos(20));
}