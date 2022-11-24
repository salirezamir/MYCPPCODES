#include <iostream>

using namespace std;

long mul(long a, long b)
{
    // saktane tabe zarb a*b ba jam'e
    long t = 0;
    for (; a > 0; a--)
        t += b;
    return t;
}

int main()
{
    long num, i = 1;
    cin >> num;
    /*
        az anja ke tazmin shode ast ke jazr adad vorodi adadi tabiee ast
        pas check mikoni adad tabiee ro ta anja ke mul(a,a)=num ke 'a' mishavad
        jazr num
    */
    while (mul(i, i) != num)
    {
        i++;
    }
    cout << i;
}