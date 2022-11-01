#include <iostream>
using namespace std;
int main()
{
    int x[5], y[5], z = 0, k = 0, I;
    bool b = false;
    cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
    cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
    while (k != 5)
    {
        while (z != 5)
        {
            I = 0;
            I = I + (x[(k) % 5] + y[(z) % 5]) % 10;
            I = I + ((x[(k + 1) % 5] + y[(z + 1) % 5]) % 10) * 10;
            I = I + ((x[(k + 2) % 5] + y[(z + 2) % 5]) % 10) * 100;
            if (I % 6 == 0)
            {
                b = true;
            }
            z++;
        }
        z = 0;
        k++;
    }
    if (b)
    {
        cout << "Boro joloo :)";
    }
    else
    {
        cout << "Gir oftadi :(";
    }
}