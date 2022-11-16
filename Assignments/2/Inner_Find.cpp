#include <iostream>
#include <math.h>

using namespace std;

double SS(double a[2],double b[2],double c[2])
{
    return abs((a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1])));
}

int Check(double a[4][2])
{
    double s[4];
    s[0]=SS(a[0],a[1],a[2]);
    s[1]=SS(a[1],a[3],a[2]);
    s[2]=SS(a[2],a[3],a[0]);
    s[3]=SS(a[0],a[1],a[3]);
    if(s[1]==0 || s[2]==0 || s[3]==0)
    {
        return 1;
    }
    if(s[0]==s[1]+s[2]+s[3])
    {
        return 0;
    }
    return 2;
}

int main()
{
    double input[4][2];
    for(int i=0;i<5;i++)
    {
        cin >> input[i][0] >> input[i][1];
    }
    switch(Check(input)) {
    case 0:
        cout << "in";
    break;
    case 1:
        cout << "on";
    break;
    case 2:
        cout << "out";
    break;

    }
}