#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a, b, c, n = 0, j, v;
    cin >> a;
    v = a;
    b = a % 10;
    while (a != 0)
    {
        a = a / 10;
        n++;
    }
    j = pow(10, n - 1);
    c = v / j;
    v = v - b + c;
    v = v + (b - c) * j;
    cout << v;
}