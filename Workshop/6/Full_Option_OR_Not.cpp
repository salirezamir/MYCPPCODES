#include <iostream>

using namespace std;

long mSum(long num)
{
    long j = 1;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            j += i;
    }
    return j;
}

int main()
{
    long in;
    cin >> in;
    if (in == mSum(in))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}