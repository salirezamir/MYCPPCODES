#include <iostream>
#include <string>
using namespace std;

int findMismatch(string s1, string s2)
{
    int missed = 0;
    if (s1.length() == s2.length())
    {
        for (int i = 0; i < s1.length(); i++)
            s1[i] = tolower(s1[i]);
        for (int i = 0; i < s2.length(); i++)
            s2[i] = tolower(s2[i]);
        if (s1 == s2)
            return 0;
        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] != s1[i])
                missed++;
        }
        if (missed == 1)
            return 1;
    }
    return 2;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << findMismatch(s1, s2);

    return 0;
}