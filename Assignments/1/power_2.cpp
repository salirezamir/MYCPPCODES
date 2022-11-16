#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a, b, c;
    c = 1;
    cin >> a;
    while (a > b)
    {
        b = pow(2, c);
        c++;
    }
    if (a == b)
    {
        b = b * 2;
    }
    cout << b;
}