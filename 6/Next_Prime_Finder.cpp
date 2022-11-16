#include <iostream>

using namespace std;

bool primeChecker(long num)
{
    if (num == 1)
        return false;
    if (num <= 3)
        return true;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int digitsSum(long num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

long nextPrime(long num)
{
    for (long k = num + 1; k < 100001; k++)
    {
        if (primeChecker(k))
            return k;
    }
}

int main()
{
    long input;
    cin >> input;
    int ds = digitsSum(input);
    for (int i = 0; i < ds; i++)
    {
        input = nextPrime(input);
    }
    cout << input;
}