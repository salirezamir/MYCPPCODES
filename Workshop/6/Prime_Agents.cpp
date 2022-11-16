#include <iostream>
#include <math.h>

using namespace std;

bool primeChecker(long num)
{
    if (num == 1)
        return false;
    if (num <= 3)
        return true;
    for (int i = 2; (i * i) < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    long input;
    bool star = false;
    cin >> input;
    int power = 1;
    for (long i = 2; i <= input; i += 2)
    {
        if (primeChecker(i) && input % i == 0)
        {
            power = 1;
            if (star)
                cout << "*";
            while (double(input / (pow(i, power))) == int((input / (pow(i, power)))))
            {
                power++;
            }
            if (power - 1 == 1)
                cout << i;
            else
                cout << i << "^" << power - 1;
            star = true;
            input /= pow(i, power-1);
        }
        if (i == 2)
            i = 1;
    }
}