#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, np, i = 0, r = 0, j = 0;
    string StrAnswer = "";
    cin >> n;
    cin >> StrAnswer;
    cin >> np;
    char ArrAnswer[n];
    string StrInput[n * np];
    j = n * np;
    while (i != j)
    {
        cin >> StrInput[i];
        i++;
    }
    i = 0;
    j = 0;
    // StrAnswer.length() + 1
    strcpy(ArrAnswer, StrAnswer.c_str());
    while (i != np)
    {
        while (j!=n*(i+1))
        {
            if (ArrAnswer[j % n] == 'A')
            {
                if (StrInput[j] == "#OOO")
                {
                    r = r + 3;
                }
                else if (StrInput[j] == "OOOO")
                {
                }
                else
                {
                    r = r - 1;
                }
            }
            else if (ArrAnswer[j % n] == 'B')
            {
                if (StrInput[j] == "O#OO")
                {
                    r = r + 3;
                }
                else if (StrInput[j] == "OOOO")
                {
                }
                else
                {
                    r = r - 1;
                }
            }
            else if (ArrAnswer[j % n] == 'C')
            {
                if (StrInput[j] == "OO#O")
                {
                    r = r + 3;
                }
                else if (StrInput[j] == "OOOO")
                {
                }
                else
                {
                    r = r - 1;
                }
            }
            else if (ArrAnswer[j % n] == 'D')
            {
                if (StrInput[j] == "OOO#")
                {
                    r = r + 3;
                }
                else if (StrInput[j] == "OOOO")
                {
                }
                else
                {
                    r = r - 1;
                }
            }
            j++;
        }
        cout << r << endl;
        r = 0;
        i++;
    }
}