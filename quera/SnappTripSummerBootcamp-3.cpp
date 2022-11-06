#include <iostream>
using namespace std;

string status(int game[2][2])
{

    if (game[1][1] + game[2][1] - game[1][2] - game[2][2] < 0)
    {
        return "esteghlal";
    }
    else if (game[1][1] + game[2][1] - game[1][2] - game[2][2] > 0)
    {
        return "perspolis";
    }
    else
    {
        if (game[2][1] > game[1][2])
        {
            return "perspolis";
        }
        else if (game[2][1] < game[1][2])
        {
            return "esteghlal";
        }
        else
        {
            return "penalty";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int Game[n][2][2];
    for (int i = 0; i < n; i++)
    {
        cin >> Game[i][1][1] >> Game[i][1][2] >> Game[i][2][1] >> Game[i][2][2];
    }
    for (int i = 0; i < n; i++)
    {
        cout << status(Game[i]) << endl;
    }
    return 1;
}