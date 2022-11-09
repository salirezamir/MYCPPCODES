#include <iostream>
using namespace std;

int charToNum(char b)
{
    switch(b) {
        case 'A':
            return 1;
        break;
        case 'B':
            return 2;
        break;
        case 'C':
            return 3;
        break;
        case 'D':
            return 4;
        break;
        case 'E':
            return 5;
        break;
        case 'F':
            return 6;
        break;
        case 'G':
            return 7;
        break;
        case 'H':
            return 8;
        break;
    }
}

int out(int a,int b)
{
    return (a-1)*8+b;
}

int main()
{
    int num;
    char chr;
    cin >> chr >> num;
    cout << (num - 1) * 8 + charToNum(chr);
    return 1;
}