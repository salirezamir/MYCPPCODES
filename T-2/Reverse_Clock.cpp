#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int h, MM;
    cin >> h >> MM;
    h = h == 0 ? 0 : 12 - h;
    MM = MM == 0 ? 0 : 60 - MM;
    printf("%.2d",h);
    cout << ":";
    printf("%.2d", MM);
    return 0;
}