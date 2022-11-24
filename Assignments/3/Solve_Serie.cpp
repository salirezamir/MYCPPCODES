#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    /*
        n va in haman n va x hastand
        sum majmoee seire mon hast ke marhale marhale ezafe mishe (for{...})
        sumU factoriel sorat hast
        sumD jame serie makhraj hast
    */
    int n;
    /* double chon ham baze bozorg dare ham 
    baray in ke to taghsim ha moshkel nakhoram */
    double in, sum = 0, sumU = 1, sumD = 0;
    cin >> in >> n;
    for (int i = 1; i <= n; i++)
    {
        /* be dast avordan makhraj
        har dafee ye jomle be makhraj ezafe mikone
        sumD=x -> +2*x^2 -> sumD=x+2*x^2 ... */
        sumD += i * pow(in, i);
        /*be dast avordan sorat
        har dafee adad lazem ro dar factoriel ghabli zarb mikone 
        ta factoriel jadid be dast byad 
        sumU=7! -> *8*9 -> sumU=9! */
        if (i != 1)
        {
            for (int j = 2 * (i - 1); j <= 2 * i - 1; j++)
            {
                sumU *= j;
            }
        }
        /*pow(-1,i+1) : +/- ghable har jomle ro moshkhas mikone
        va taghsime sorat va makhraj*/
        sum += pow(-1,i+1) *(sumU / sumD);
    }
    // fix kardan 3 ragham ashar
    printf("%.3f", sum);
}