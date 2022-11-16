#include <iostream>
using namespace std;
int main()
{
    double m1, m2, r, g, f;
    cin >> m1 >> m2 >> r;
    g = 9.78;
    m1 = m1 / 1000;
    m2 = m2 / 1000;
    r = r / 100;
    f = m1 * m2 * g / (r * r);
    cout << f;
}