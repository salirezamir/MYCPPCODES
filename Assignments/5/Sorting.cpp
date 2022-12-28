#include <iostream>

using namespace std;

class List
{
private:
    int wm[5000];
    int ci = -1;

public:
    void Add(int i)
    {
        ci++;
        wm[ci] = i;
        return;
    }
    void Move(int i1, int i2)
    {
        int tmp[2] = {wm[i1], wm[i2]};
        wm[i2] = tmp[0];
        wm[i1] = tmp[1];
        return;
    }
    int Read(int index)
    {
        return wm[index];
    }
};

int main()
{
    List list;
    int n, w;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        list.Add(w);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (list.Read(i) < list.Read(j))
                list.Move(i, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << list.Read(i) << " ";
    }
}