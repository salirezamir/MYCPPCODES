#include <iostream>

using namespace std;

class WM
{
public:
    int i, w;
};

class List
{
private:
    WM wm[5000];
    int ci = -1;

public:
    void Add(int i, int w)
    {
        ci++;
        wm[ci].i = i;
        wm[ci].w = w;
        return;
    }
    void Remove(int index)
    {
        for (int i = index; i <= ci; i++)
        {
            wm[i] = wm[i + 1];
        }
        ci -= 1;
        return;
    }
    int Current_index()
    {
        return ci;
    }
    WM Read(int index)
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
        list.Add(i + 1, w);
    }
    while (true)
    {
        if (list.Current_index() == 0)
            break;
        if (list.Read(0).w > list.Read(1).w)
            list.Remove(1);
        else
            list.Remove(0);
    }
    cout << list.Read(0).i;
}