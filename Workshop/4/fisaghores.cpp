#include "iostream"
using namespace std;

int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

bool fisaghores(int a, int b, int c)
{
    if (a * a == b * b + c * c)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool test(int arr[3], int max)
{
    if (arr[0] == max)
    {
        return fisaghores(max, arr[1], arr[2]);
    }
    else if (arr[1] == max)
    {
        return fisaghores(max, arr[0], arr[2]);
    }
    else if (arr[2] == max)
    {
        return fisaghores(max, arr[1], arr[0]);
    }
}

int main()
{
    int number[3];
    cin >> number[0];
    cin >> number[1];
    cin >> number[2];
    if (test(number, largest(number, 3)))
    {
        cout << "YES";
        return 1;
    }
    cout << "NO";
    return 0;
}