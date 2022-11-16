#include <iostream>
using namespace std;
int main()
{
    int t, d, h, m;
    cin >> t;
    d = t / 86400;
    t = t - d * 86400;
    h = t / 3600;
    t = t - h * 3600;
    m = t / 60;
    t = t - m * 60;
    cout << d << " days " << h << " hours " << m << " minutes " << t << " seconds";
}