#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    double a, b, sum = 0, i = 0, fig0, fig1, fig2;
    cin >> a >> b;
    fig0 = 1;
    fig1 = 1;
    fig2 = 2;
    if (a <= 1)
    {
        i++;
        sum++;
    }
    while (fig2 <= b)
    {
        fig2 = fig1 + fig0;
        fig0 = fig1;
        fig1 = fig2;
        if (fig2 >= a && fig2 <= b)
        {
            sum += fig2;
            i++;
        }
    }
    if (i != 0)
        cout << (round((sum / i) * 1000) * 1.0) / 1000;
    else
        cout << "Not Found!";
}