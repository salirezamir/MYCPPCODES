#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int loc[k][2];
    for (int j = 0; j < k; j++)
    {
        cin >> loc[j][0] >> loc[j][1];
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (loc[i][0] == loc[j][0] || loc[i][1] == loc[j][1])
            {
                cout << "LOOSER!";
                return 0;
            }
        }
    }
    cout << "WINNER!";
    return 0;
}