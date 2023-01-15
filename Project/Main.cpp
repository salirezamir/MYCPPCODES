#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int boardsize = 11;

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

void Make_Game_Borad()
{
    int &j = boardsize;
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

void start_menu()
{
    cout << "oooooooooo o888                        oooo         oooooooooo                                      o888             \n 888    888 888   ooooooo     ooooooo   888  ooooo   888    888 oooo  oooo  ooooooooooo ooooooooooo  888  ooooooooo8 \n 888oooo88  888 888     888 888     888 888o888      888oooo88   888   888       8888        8888    888 888oooooo8  \n 888    888 888 888     888 888         8888 88o     888         888   888    8888        8888       888 888         \no888ooo888 o888o  88ooo88     88ooo888 o888o o888o  o888o         888o88 8o o888ooooooo o888ooooooo o888o  88oooo888 \n ";
    int set[3] = {116, 7, 7};
    int X = 50;
    int Y = 10;
    int counter = 1;
    char key;
    char keyz;
    while (true)
    {
        ConXY(X + 6, Y);
        ConClr(set[0]);
        cout << "START";
        ConXY(X, Y + 1);
        ConClr(set[1]);
        cout << "Select Difficulty";
        ConXY(X + 6, Y + 2);
        ConClr(set[2]);
        cout << "Exit";
        ConClr(7);
        key = _getch();
        if (key == '\r')
        {
            if (counter == 1)
            {
                return;
            }
            if (counter == 2)
            {
                ConXY(X - 6, Y + 5);
                ConClr(12);
                cout << "Note That the minimal input is 11";
                ConXY(X - 3, Y + 6);
                ConClr(6);
                cout << "Please insert grids number : ";
                ConClr(7);
                cin >> boardsize;
                ConXY(X - 6, Y + 6);
                cout << "                                               ";
                ConXY(X - 6, Y + 5);
                cout << "                                               ";
                if (boardsize < 11)
                {
                    boardsize = 11;
                    ConXY(X - 3, Y + 5);
                    ConClr(70);
                    cout << "THE INPUT IS NOT VALID";
                    ConXY(X - 4, Y + 7);
                    ConClr(100);
                    cout << "PRESS ANY KEY TO CONTINUE";
                    ConClr(7);
                    keyz = _getch();
                    ConXY(X - 3, Y + 5);
                    cout << "                                               ";
                    ConXY(X - 4, Y + 7);
                    cout << "                                               ";
                }
            }
            if (counter == 3)
            {
                exit(0);
            }
        }
        if (key == -32)
        {
            keyz = _getch();
            if (keyz == 72 && counter != 1)
                counter--;
            if (keyz == 80 && counter != 3)
                counter++;
        }
        set[0] = 7;
        set[1] = 7;
        set[2] = 7;
        set[counter - 1] = 116;
    }
}

int main()
{
    system("cls");
    start_menu();
    system("cls");
    Make_Game_Borad();
    char keyz = _getch();
    return 0;
}
