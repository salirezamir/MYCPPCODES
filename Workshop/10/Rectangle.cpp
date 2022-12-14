#include <iostream>

using namespace std;

class Rectangle
{
    public:
    int x,y;
    int Area()
    {
        return x*y;
    }
};

int main()
{
    Rectangle rectangle;
    cin >> rectangle.x >> rectangle.y;
    cout << rectangle.Area();
}