#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    string s;
    double a, b;
    int c, d;
    cin >> s;
    if (s == "sqrt")
    {
        cin >> a;
        printf("%.6f", sqrt(a));
    }
    else if (s == "%")
    {
        cin >> c;
        cin >> d;
        int e = c % d;
        cout << e;
    }
    else
    {
        cin >> a;
        cin >> b;
    }
    if (s == "+")
    {
        printf("%.6f", a + b);
    }
    else if (s == "-")
    {
        printf("%.6f", a - b);
    }
    else if (s == "*")
    {
        printf("%.6f", a * b);
    }
    else if (s == "/")
    {
        printf("%.6f", a / b);
    }
}