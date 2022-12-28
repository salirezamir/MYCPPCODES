#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int in, n = -1, x = 0, count = 0;
    long sum = 0;
    cin >> in;
    int Mx[in][in];
    for (int i = 0; i < in; i++)
    {
        for (int j = 0; j < in; j++)
            cin >> Mx[i][j];
    }
    while (true)
    {
        for (int i = x; i < in - x; i++)
        {
            n++;
            sum += Mx[x][i];
            if (sqrt(sum) == int(sqrt(sum)))
                count++;
            if (n == in * in)
            {
                cout << count;
                return 0;
            }
        }
        for (int i = x + 1; i < in - x; i++)
        {
            n++;
            sum += Mx[i][in - x - 1];
            if (sqrt(sum) == int(sqrt(sum)))
                count++;
            if (n == in * in)
            {
                cout << count;
                return 0;
            }
        }
        for (int i = in - x - 2; i >= x; i--)
        {
            n++;
            sum += Mx[in - x - 1][i];
            if (sqrt(sum) == int(sqrt(sum)))
                count++;
            if (n == in * in)
            {
                cout << count;
                return 0;
            }
        }
        for (int i = in - x - 2; i > x; i--)
        {
            n++;
            sum += Mx[i][x];
            if (sqrt(sum) == int(sqrt(sum)))
                count++;
            if (n == in * in)
            {
                cout << count;
                return 0;
            }
        }
        x++;
        if (x == in)
        {
            cout << count;
            return 0;
        }
    }
}