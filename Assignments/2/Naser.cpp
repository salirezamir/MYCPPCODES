#include <iostream>

using namespace std;

int fruit(string a)
{

    if (a=="apple")
        return 100;
    else if (a=="banana")
        return 250;
    else if (a=="peach")
        return 70;
    else if (a=="lemon")
        return 45;
    else if (a=="kiwi")
        return 85;

    return 0;
}

int main()
{
    string fName;
    double count;
    cin >> fName >> count;
    if (fruit(fName)*count > 200)
    {
        cout << int(fruit(fName)*count) << "\n" << "more";
    }
    else if(fruit(fName)*count < 100)
    {
        cout << int(fruit(fName)*count) << "\n" << "less";
    }
    else
    {
        cout << int(fruit(fName)*count) << "\n" << "ok";
    }
    return 1;
}