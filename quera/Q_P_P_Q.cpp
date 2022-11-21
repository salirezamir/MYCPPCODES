#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << data[n - i - 1];
        if (i != n - 1)
            cout << " ";
    }
}