#include "iostream"
using namespace std;
int main()
{
    double F;
    double C;
    double K;
    cin >> F;
    C=(5*(F-32))/9;
    K=C+273;    
    printf("%.3f %.3f",C,K);
    // cout << " ";
    // printf("%.3f",K);
}