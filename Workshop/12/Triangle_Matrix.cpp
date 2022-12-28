#include <iostream>

using namespace std;

int main()
{
    int n;
    bool Status[2] = {true, true};
    cin >> n;
    int Mx[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> Mx[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (Mx[i][j] != 0)
            {
                Status[0] = false;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Mx[i][j] != 0)
            {
                Status[1] = false;
                break;
            }
        }
    }
    if (Status[0])
        cout << "Payein Mosalasi";
    else if (Status[1])
        cout << "Bala Mosalasi";
    else
        cout << -1;
    return 0;
}