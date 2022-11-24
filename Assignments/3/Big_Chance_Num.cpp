#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // n:adad vorodi "be dalil ehtemal bozorg bodan vorodi long darnazar gereftam"
    long n;
    cin >> n;
    /*
    tozih shart dakhele if
        agar deghat konim mibinim ke
        dar serie aval hazf adAdi ke i%2=1 bod baghi mandand
        dar serie dovom hazf adAdi ke i%4=1 ya i%4=3 bod baghi mandand
        dar serie sevom hazf adAdi ke i%8=1 ya i%8=7 bod baghi mandand
        ...
        dar serie n om hazf adadi ke i%2^n=1 ya i%2^n=-1+2^n bod baghi mandand
        => shart zir ra neveshtam
    */
    /*
    tozih shart dakhele for
        agar deghat konim mibinim ke
        dar serie aval hazf adad 1 ke ghabl 2 hast baray hamishe baghi mimand
            chon az een be bad 2 ta da mian hazf darim va 2 ghabl az baze hazf hast
        dar serie dovom hazf adad 1,3 ke ghabl 4 hast baray hamishe baghi mimand
            chon az een be bad 3 ta da mian hazf darim va adade zekr shode ghabl az baze hazf hast
        dar serie sevom hazf adad 1,3,7 ke ghabl 8 hast baray hamishe baghi mimand
            chon az een be bad 3 ta da mian hazf darim va adade zekr shode ghabl az baze hazf hast
        ...
        pas agar ada ta 2^round(Log2(n)) zende bemanad , baraye hamishe zende mimanad
    */
    for (int i = 1; pow(2, i) <= n; i++)
    {
        if (n % long(pow(2, i)) == 1 || n % long(pow(2, i)) == long(pow(2, i)) - 1)
        {
            // continue: agar dar een serie hazf zende mand serie bad ra check konad
            continue;
        }
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 1;
}