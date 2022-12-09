#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    cout << gcd(max(a, b), min(a, b));
    return 0;
}
