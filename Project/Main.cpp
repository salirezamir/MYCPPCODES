#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int boardsize = 11;
int HighScore = 0;

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

class Game
{
private:
    const bool easy_Single[1] = {true};
    const bool easy_Bar[2] = {true}; // d
    const bool easy_Square[2][2] = {true};
    const bool Norm_L[4][2][2] = {{{{false}, {true}}, {{true}, {true}}}, {{{true}, {false}}, {{true}, {true}}}, {{{true}, {true}}, {{false}, {true}}}, {{{true}, {true}}, {{true}, {false}}}};
    const bool Norm_Bar_3[3] = {true}; // d
    const bool Norm_Bar_4[4] = {true}; // d
    // d
    const bool Hard_LL[2][3][2] = {{{{true}, {false}}, {{true}, {true}}, {{false}, {true}}}, {{{false}, {true}}, {{true}, {true}}, {{true}, {false}}}};
    // d
    const bool Hard_T[2][2][3] = {{{{true}, {true}, {true}}, {{false}, {true}, {false}}}, {{{false}, {true}, {false}}, {{true}, {true}, {true}}}};
    const bool Hard_L[4][2][3] = {{{{true}, {true}, {true}}, {{true}, {false}, {false}}}, {{{true}, {true}, {true}}, {{false}, {false}, {true}}}, {{{true}, {false}, {false}}, {{true}, {true}, {true}}}, {{{false}, {false}, {true}}, {{true}, {true}, {true}}}};

public:
    void Make_Game_Borad()
    {
        ConClr(238);
        for (int i = 0; i <= boardsize; i++)
        {
            ConXY(2 * i, 0);
            cout << "  ";
            ConXY(0, i);
            cout << " ";
            ConXY(2 * i, boardsize + 1);
            cout << "  ";
            ConXY(2 * boardsize + 1, i + 1);
            cout << " ";
        }
        ConXY(2 * boardsize + 1, 0);
        cout << " ";
        ConClr(7);
        for (int i = 0; i < boardsize; i++)
        {
            for (int j = 0; j < boardsize; j++)
            {
                ConXY(2 * i + 2, j + 1);
                cout << "-";
            }
        }
    }

    void start_menu()
    {
        system("cls");
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
            if (key == 13)
            {
                if (counter == 1)
                {
                    system("cls");
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
                    
                    system("cls");
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
};

int main()
{
    Game game;
    game.start_menu();
    game.Make_Game_Borad();
    char keyz = _getch();
    return 0;
}
