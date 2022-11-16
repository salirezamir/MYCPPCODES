#include "iostream"
using namespace std;

int main()
{
    int i;
    cin >> i;
    if (i % 2 == 0)
    {
        if (i < 0)
        {
            cout << i;
            return 1;
        }
    }
    i = -1 * i;
    cout << i;
}