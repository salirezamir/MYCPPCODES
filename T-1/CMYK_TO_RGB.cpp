#include <iostream>
using namespace std;
int main()
{
    double c, m, y, k;
    int r, b, g;
    cin >> c >> m >> y >> k;
    r = 255 * (1 - c) * (1 - k);
    g = 255 * (1 - m) * (1 - k);
    b = 255 * (1 - y) * (1 - k);
    cout << "(" << r << ", " << g << ", " << b << ")";
}