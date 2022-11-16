#include <iostream>
using namespace std;

string status(int a)
{
    if (a<0)
    {
        return "Ice";
    }
    else if (a>100)
    {
        return "Steam";
    }
    else
    {
        return "Water";
    }
}

int main()
{
    int input;
    cin >> input;
    cout << status(input);
}