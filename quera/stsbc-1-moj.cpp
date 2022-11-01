#include <iostream>
#include <cstring>
using namespace std;
int CheckAnswer(char Answer, string strAnswer)
{
    if (strAnswer == "OOOO")
        return 0;
    if (Answer == 'A')
    {
        if (strAnswer == "#OOO")
            return 3;
        else
            return -1;
    }
    if (Answer == 'B')
    {
        if (strAnswer == "O#OO")
            return 3;
        else
            return -1;
    }
    if (Answer == 'C')
    {
        if (strAnswer == "OO#O")
            return 3;
        else
            return -1;
    }
    if (Answer == 'D')
    {
        if (strAnswer == "OOO#")
            return 3;
        else
            return -1;
    }
}
int CheckAnswerSheet(string Answer, string strAnswerSheet[])
{
    int res = 0;
    int n = Answer.length();
    for (int i = 0; i < n; i++)
    {
        res += CheckAnswer(Answer[i], strAnswerSheet[i]);
    }
    return res;
}
int main()
{
    int n, np;
    string strAnswer = "";
    cin >> n;
    cin >> strAnswer;
    cin >> np;
    string strInput[np][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < np; j++)
        {
            cin >> strInput[i][j];
        }
    }
    for (int i = 0; i < np; i++)
    {
        cout << CheckAnswerSheet(strAnswer, strInput[i]) << endl;
    }
}
