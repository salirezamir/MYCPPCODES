#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d;
    e = a + c - b - d;
    f = a + d - b - c;
    g = a + c + d - b;
    h = a - b - c - d;
    if (e == 0)
    {
        cout << "Mishe";
    }
    else if (f == 0)
    {
        cout << "Mishe";
    }
    else if (g == 0)
    {
        cout << "Mishe";
    }
    else if (h == 0)
    {
        cout << "Mishe";
    }
    else
    {
        cout << "Nemishe";
    }
}