#include <iostream>
#include <windows.h>

using namespace std;

void ConXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}

void ConClr(int clr)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
    return;
}

void PrintXYClr(string str, int x, int y, int clr)
{
    ConXY(x, y);
    ConClr(clr);
    cout << str;
}

void Make_Game_Borad(int j)
{
    j = 2 * (j + 1);
    ConClr(238);
    for (int i = 1; i <= j; i++)
    {
        ConXY(1, i);
        cout << " ";
        ConXY(i, 1);
        cout << " ";
        ConXY(j + 1, j - i + 1);
        cout << " ";
        ConXY(j - i + 1, j);
        cout << " ";
    }
    ConClr(7);
    j = -1 + j / 2;
    for (int i = 1; i <= j; i++)
    {
        for (int k = 1; k <= j; k++)
        {
            ConXY(2 * i + 1, 2 * k + 1);
            cout << "-";
        }
    }
    ConXY(30, 30);
}

int main()
{
    system("cls");
    Make_Game_Borad(11);
    return 0;
}