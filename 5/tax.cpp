#include <iostream>
using namespace std;

int main()
{
    double x, xbar, deltaxbar[2];
    cin >> x >> xbar;
    deltaxbar[0] = xbar * 0.975;
    deltaxbar[1] = xbar * 1.025;
    if (x < deltaxbar[1] && x > deltaxbar[0])
        printf("%.2f", x * 0.9);
    else if (x > deltaxbar[1])
        printf("%.2f", x * 0.8);
    else if (x < deltaxbar[0])
        printf("%.2f", x * 0.95);
    return 0;
}