#include <iostream>

using namespace std;

int n;

int pow(int j)
{
    if (j == 0)
        return 1;
    return n * pow(j - 1);
}

int main()
{
    int i;
    cin >> n >> i;
    cout << pow(i);
    return 0;
}