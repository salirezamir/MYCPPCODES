#include <iostream>
#include <math.h>

using namespace std;

double tilt(double a[2], double b[2])
{
    return ((a[1] - b[1]) / (a[0] - b[0]));
}

double WFO(double a[2], double b[2])
{
    return ((b[1] * a[0]) - (a[1] * b[0])) / (a[0] - b[0]);
}

double intersectionX(double f[2], double g[2])
{
    return ((g[1] - f[1]) / (f[0] - g[0]));
}

double intersectionY(double f[2], double g[2])
{
    return (((g[1] * f[0]) - (f[1] * g[0])) / (f[0] - g[0]));
}

// bool Check(double p[5][2])
// {
//     int i = 0;
//     if (p[0][0] >= p[4][0] && p[1][0] <= p[4][0])
//         i++;
//     if (p[0][0] <= p[4][0] && p[1][0] >= p[4][0])
//         i++;
//     if (p[0][1] >= p[4][1] && p[1][1] <= p[4][1])
//         i++;
//     if (p[0][1] <= p[4][1] && p[1][1] >= p[4][1])
//         i++;
//     if (i >= 2)
//         return true;
//     return false;
// }

int main()
{
    bool j = false;
    double points[5][2];
    double funcs[2][2];
    for (int i = 0; i < 4; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
    for (int i = 0; i < 2; i++)
    {
        funcs[i][0] = tilt(points[2 * i], points[2 * i + 1]);
        funcs[i][1] = WFO(points[2 * i], points[2 * i + 1]);
    }
    points[4][0] = intersectionX(funcs[0], funcs[1]);
    points[4][1] = intersectionY(funcs[0], funcs[1]);
    int i = 0;
    if (funcs[1][0] == funcs[0][0])
    {
        cout << "0";
        return 0;
    }
    if (points[2][0] >= points[4][0] && points[3][0] <= points[4][0] || points[2][0] <= points[4][0] && points[3][0] >= points[4][0])
    {
        if (points[2][1] >= points[4][1] && points[3][1] <= points[4][1] || points[2][1] <= points[4][1] && points[3][1] >= points[4][1])
        {
            if (points[0][0] >= points[4][0] && points[1][0] <= points[4][0] || points[0][0] <= points[4][0] && points[1][0] >= points[4][0])
            {
                if (points[0][1] >= points[4][1] && points[1][1] <= points[4][1] || points[0][1] <= points[4][1] && points[1][1] >= points[4][1])
                    return true;
            }
        }
    }
    if (j)
    {
        cout << "1";
        return 1;
    }
    cout << "0";
    return 0;
}