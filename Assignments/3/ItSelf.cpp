#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long num, nump = 0, pw;
    cin >> num;
    long numc=num;
    while (num >= 1)
    {
        pw = log10(num);
        nump += (num % 10 * long(pow(10, pw)));
        num = (num - num % 10) / 10;
    }
    if (numc == nump)
        cout << "YES";
    else
        cout << "NO";
}