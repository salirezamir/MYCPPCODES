#include <iostream>

using namespace std;

int sqrt(int n)
{
    int tmp=1,k=1;
    /*
        A(x)=x^2
        => A(i)=i^2 , A(i+1)=i^2+2*i+1
        => A(i+1)-A(i) = 2*i+1
        ke dar eenja k:=2*i+1 va har serie 2 ta behesh ezafeh mishe
        tmp=A(i)+k=A(i+1)
    */
    for (int i=1;i<=n;i++)
    {
        if(tmp==n)
            return i;
        k+=2;
        tmp+=k;
    }
    return -1;
}

int main()
{
    //in:=input number
    int in;
    cin >> in;
    cout << sqrt(in);
}

