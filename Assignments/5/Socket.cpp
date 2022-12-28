#include <iostream>

using namespace std;

int main()
{
    int socket[2][4];
    cin >> socket[0][0] >> socket[0][1] >> socket[0][2] >> socket[0][3];
    cin >> socket[1][0] >> socket[1][1] >> socket[1][2] >> socket[1][3];
    for (int i = 0; i < 4; i++)
    {
        if (socket[0][i] != socket[1][3 - i])
        {
            cout << 0;
            return 1;
        }
    }
    cout << 1;
    return 0;
}