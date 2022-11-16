#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    int i=0;
    if(i==1)
    {
        cout << "";
    }
    else
    {
        cout << "ddd";
    }
    cout << endl;
}
