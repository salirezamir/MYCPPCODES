#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    long long R;
    while ((a % b) > 0)
    {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}

int main()
{
    long long a, b, mcd, gccd;
    cin >> a >> b;
    gccd = gcd(max(a, b), min(a, b));
    cout << gccd;
    mcd = gccd;
    while (gccd > 1)
    {
        a /= gccd;
        b /= gccd;
        gccd = gcd(max(a, b), min(a, b));
        mcd *= gccd;
    }
    mcd *= a * b;
    cout << " " << mcd;
}