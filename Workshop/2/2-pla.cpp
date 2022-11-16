#include "iostream"
#include <math.h>
using namespace std;
int main()
{
    double keyvan,amir,yazdanloti,alisagzan;
    cin >> keyvan >> amir >> yazdanloti;
    alisagzan=(keyvan*amir)/(M_PI*yazdanloti*yazdanloti);
    printf("%.2f",alisagzan);
}