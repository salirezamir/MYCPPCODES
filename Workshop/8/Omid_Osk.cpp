#include <iostream>

using namespace std;

int conv(int b, int num)
{
    if (1 + num % 10 == b)
    {
        num = num - (num % 10) + 10;
        for (int tmp = 100; num % tmp == tmp * b / 10; tmp *= 10)
            num = num - (num % tmp) + tmp;
    }
    else
        num = num + 1;
    return num;
}

int main()
{
    int base, num;
    cin >> base >> num;
    cout << conv(base, num);
}