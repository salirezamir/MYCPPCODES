#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int k, l, fit, delta[3], NTI[2], n;
    bool dbn[2];
    cin >> k >> NTI[0] >> NTI[1];
    // fix neg
    if (NTI[0] < 0 && NTI[1] < 0)
    {
        NTI[0] *= -1;
        NTI[1] *= -1;
    }
    else if (NTI[0] < 0)
    {
        n = int(abs(NTI[0] / k)) + 5;
        NTI[0] += n * k;
        NTI[1] += n * k;
    }
    else if (NTI[1] < 0)
    {
        n = int(abs(NTI[1] / k)) + 5;        
        NTI[1] += n * k;
        NTI[0] += n * k;
    }
    //max
    if (NTI[0] > NTI[1])
    {
        l = NTI[0];
        fit = NTI[1];
    }
    else
    {
        l = NTI[1];
        fit = NTI[0];
    }
    // algo
    if (l % k > k - (l % k))
    {
        dbn[0] = true;
        delta[0] = k - (l % k);
    }
    else
    {
        dbn[0] = false;
        delta[0] = l % k;
    }
    if (fit % k > k - fit % k)
    {
        dbn[1] = true;
        delta[1] = k - fit % k;
    }
    else
    {
        dbn[1] = false;
        delta[1] = fit % k;
    }
    if (dbn[0])
    {
        NTI[0] = l + delta[0];
    }
    else
    {
        NTI[0] = l - delta[0];
    }
    if (dbn[1])
    {
        NTI[1] = fit + delta[1];
    }
    else
    {
        NTI[1] = fit - delta[1];
    }
    delta[2] = (abs(NTI[0] - NTI[1])) / k;
    if (l - fit > delta[0] + delta[1] + delta[2])
        cout << delta[0] + delta[1] + delta[2];
    else
        cout << l - fit;
}