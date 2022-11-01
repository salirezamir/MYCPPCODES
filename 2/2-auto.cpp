#include "iostream"
using namespace std;
int main()
{
    int INNER;
    int CAP;
    cin >> INNER;
    cin >> CAP;
    int N=INNER/CAP;
    int FARBOD=CAP-INNER+(CAP*N);    
    cout << FARBOD;
    //printf("%.3f",K);
}