#include <iostream>

using namespace std;

bool check(int i, int fig[100], int n)
{
    for (int j = 2; fig[j] <= i && j < n; j++)
    {
        if (fig[j] == i)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int fig[n];
    // fig clac
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            fig[0] = 1;
            cout << "+";
        }
        else if (i == 1)
        {
            fig[1] = 2;
            cout << "+";
        }
        else
        {
            fig[i] = fig[i - 1] + fig[i - 2];
        }
    }
    for (int i = 3; i <= n; i++)
    {
        if (check(i,fig,n))
            cout << "+";
        else
            cout << "-";
    }
    
}