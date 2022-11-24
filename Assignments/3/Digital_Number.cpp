#include <iostream>
#include <math.h>

using namespace std;

void digit0(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int j = 2; j < size; j++)
    {
        cout << ch;
        for (int i = 1; i < size - 1; i++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    return;
}

void digit1(char ch, int size)
{
    for (int j = 1; j <= size; j++)
    {
        for (int i = 1; i < size; i++)
            cout << " ";
        cout << ch << endl;
    }
    return;
}

void digit2(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        for (int j = 1; j <= size - 1; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        cout << ch;
        for (int j = 1; j <= size - 1; j++)
            cout << " ";
        cout << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    return;
}

void digit3(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        for (int j = 1; j <= size - 1; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        for (int j = 1; j <= size - 1; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    return;
}

void digit4(char ch, int size)
{

    for (int i = 1; i <= ((size - 1) / 2); i++)
    {
        cout << ch;
        for (int j = 1; j <= size - 2; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 1) / 2); i++)
    {
        for (int j = 1; j <= size - 1; j++)
            cout << " ";
        cout << ch << endl;
    }
    return;
}

void digit5(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        for (int j = 1; j <= size - 1; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    return;
}

void digit6(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        cout << ch;
        for (int j = 1; j <= size - 2; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    return;
}

void digit7(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int j = 2; j <= size - 1; j++)
    {
        for (int i = 1; i < size; i++)
            cout << " ";
        cout << ch << endl;
    }
    return;
}

void digit8(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        cout << ch;
        for (int j = 1; j <= size - 2; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        cout << ch;
        for (int j = 1; j <= size - 2; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    return;
}

void digit9(char ch, int size)
{
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        cout << ch;
        for (int j = 1; j <= size - 2; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    for (int i = 1; i <= ((size - 3) / 2); i++)
    {
        for (int j = 1; j <= size - 1; j++)
            cout << " ";
        cout << ch << endl;
    }
    for (int i = 1; i <= size; i++)
        cout << ch;
    cout << endl;
    return;
}

long long reverse(long long in)
{
    long long out = 0;
    while (in >= 1)
    {
        out *= 10;
        out += in % 10;
        in /= 10;
    }
    return out;
}

void digitPrinter(char ch, int n, int size)
{
    switch (n)
    {
    case 0:
        digit0(ch, size);
        break;
    case 1:
        digit1(ch, size);
        break;
    case 2:
        digit2(ch, size);
        break;
    case 3:
        digit3(ch, size);
        break;
    case 4:
        digit4(ch, size);
        break;
    case 5:
        digit5(ch, size);
        break;
    case 6:
        digit6(ch, size);
        break;
    case 7:
        digit7(ch, size);
        break;
    case 8:
        digit8(ch, size);
        break;
    case 9:
        digit9(ch, size);
        break;
    }
    return;
}

int main()
{
    long long num, nump;
    int temp;
    int s;
    char k;
    cin >> num >> s >> k;
    nump = reverse(num);
    while (nump >= 1)
    {
        temp = nump % 10;
        digitPrinter(k, temp, s);
        nump /= 10;
        if (nump >= 1 || num % 10 == 0)
            cout << endl;
    }
    if (num % 10 == 0)
        digit0(k, s);
    return 0;
}