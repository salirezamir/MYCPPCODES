#include <iostream>

using namespace std;

int main()
{
    int n, k, min;
    cin >> k >> n;
    int rank[n];
    for (int i = 0; i < k; i++)
        cin >> rank[i];
    for (int i = k; i < n; i++)
    {
        min = 1;
        for (int j = i - k; j < i; j++)
        {
            if (rank[j] == min)
            {
                j = i - k - 1;
                min++;
            }
        }
        rank[i] = min;
    }
    cout << rank[n - 1];
}