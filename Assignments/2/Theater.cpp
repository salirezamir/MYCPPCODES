#include <iostream>
using namespace std;

int main()
{
    int y,x;
    cin >> y >> x;
    if(x<=10)
    {
        cout << "Right " << 11-y << " " << x;
    }
    else
    {
        cout << "Left " << 11-y << " " << 21-x;
    }
    return 1;
}