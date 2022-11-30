#include <iostream>

using namespace std;

int f1 = 1, f2 = 1, fx = 1;

void nextFib()
{
    fx = f1 + f2;
    f2 = f1;
    f1 = fx;
}
void check(int i)
{
    if (i == fx)
    {
        cout << "+";
        nextFib();
        return;
    }
    cout << "-";
    return;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        check(i);
    }
}