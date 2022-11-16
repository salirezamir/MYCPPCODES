#include <iostream>

using namespace std;

long fact(long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    long n;
    cin >> n;
    cout << fact(n);
    return 1;
}