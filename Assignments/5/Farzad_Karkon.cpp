#include <iostream>

using namespace std;

int main()
{
    int n, ci = 0, tmp = 0;
    cin >> n;
    int nums[n], sums[n * (n + 1) / 2];
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++)
    {
        sums[ci] = nums[i];
        ci++;
        for (int j = i + 1; j < n; j++)
        {
            sums[ci] = sums[ci - 1] + nums[j];
            ci++;
        }
    }
    tmp = sums[0];
    for (int i = 0; i < n * (n + 1) / 2; i++)
    {
        if (sums[i] > tmp)
            tmp = sums[i];
    }
    if (tmp > 0)
        cout << tmp;
    else
        cout << 0;
    return 0;
}
