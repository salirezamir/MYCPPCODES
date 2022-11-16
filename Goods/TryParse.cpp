#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    // try parse start
    string string;
    long n;
    bool b = true;
    cin >> string;
    if (string == "0" || string == "+0" || string == "-0")
    {
        n = 0;
        // 00 and ... not work
    }
    else
    {
        std::istringstream s(string);
        s >> n;
        if (n == 0)
        {
            b = false;
        }
    }
    // try parse end
    // code start
    if (b)
    {
        std::cout << n << '\n';
    }
    else
    {
        std::cout << "U R COW" << '\n';
    }
    // code end
}