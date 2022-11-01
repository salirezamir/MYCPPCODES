#include <iostream>
using namespace std;
int main()
{
    int x[5], y[5], I;
    cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
    cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
    for (int k = 0; k < 5; k++)
    {
        for (int z = 0; z < 5; z++)
        {
            I = 0;
            I = ((x[k] + y[z]) % 10) * 100;
            I += ((x[(k + 1) % 5] + y[(z + 1) % 5]) % 10) * 10;
            I += ((x[(k + 2) % 5] + y[(z + 2) % 5]) % 10);
            // cout << I << "\n";
            if (I % 6 == 0)
            {
                cout << "Boro joloo :)";
                return 1;
            }
        }
    }
    cout << "Gir oftadi :(";
    return 0;
}