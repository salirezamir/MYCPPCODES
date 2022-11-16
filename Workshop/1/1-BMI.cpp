#include "iostream"
#include <stdio.h>
using namespace std;
int main()
{
    float h,w;
    //cout << "***welcome to BMI Calculator*** " ;
    //cout << "Plase insert height :";
    cin >> h;
    //cout << "Plase insert weight :";
    cin >> w;
    float BMI=w/(h*h);
    //cout << "Your BMI is : " << BMI;
    //return;
    printf("%.2f",BMI);
    // setprecision(n)
}