#include <iostream>

using namespace std;

long calculateExponent(int a, int b)
{
    if (b == 0)
        return 1;
    return a * calculateExponent(a, b - 1);
}

long calculateFibonacci(int n)
{
    if (n == 1 || n == 0)
        return (n);
    return (calculateFibonacci(n - 1) + calculateFibonacci(n - 2));
}

long calculateFactorial(int n)
{
    if (n == 0)
        return 1;
    return (n * calculateFactorial(n - 1));
}

int calculateGCD(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return calculateGCD(b, a % b);
}

int main()
{
    //Seyed Alireza Mirabedini
}