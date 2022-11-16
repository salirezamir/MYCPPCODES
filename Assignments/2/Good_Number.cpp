#include <iostream>
using namespace std;

int status(int a)
{
    int i=1;
    if(int(a%10)+int(a/100) == int(0.2*(int(a%100)-int(a%10))))
    {
        i++;
    }
    if ((int(a%10)+int(a/100)+(int(0.1*(int(a%100)-int(a%10)))))%3 == 0)
    {
        i++;
    }
    if (int(a/100)>int(0.1*(int(a%100)-int(a%10))) && int(a/100)>int(a%10))
    {
        i++;
    }
    return i;
}

int main()
{
    int OMG;
    cin >> OMG;
    switch(status(OMG)) {
        case 1:
            cout << "Bad";
        break;
        case 2:
            cout << "Normal";
        break;
        case 3:
            cout << "Good";
        break;
        case 4:
            cout << "Very Good";
        break;
    }
    return 1;

}