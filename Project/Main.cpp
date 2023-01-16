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
    // {{{},{},{}},{{},{},{}},{{},{},{}}},
    bool easy_Single[3][3] = {{true, false, false}, {false, false, false}, {false, false, false}};
    bool easy_Bar_1[3][3] = {{{true}, {true}, {false}}, {{false}, {false}, {false}}, {{false}, {false}, {false}}};
    bool easy_Bar_2[3][3] = {{{true}, {false}, {false}}, {{true}, {false}, {false}}, {{false}, {false}, {false}}};
    bool easy_Square[3][3] = {{{true}, {true}, {false}}, {{true}, {true}, {false}}, {{false}, {false}, {false}}};
    bool Norm_L_1[3][3] = {{{false}, {true}, {false}}, {{true}, {true}, {false}}, {{false}, {false}, {false}}};
    bool Norm_L_2[3][3] = {{{true}, {false}, {false}}, {{true}, {true}, {false}}, {{false}, {false}, {false}}};
    bool Norm_L_3[3][3] = {{{true}, {true}, {false}}, {{false}, {true}, {false}}, {{false}, {false}, {false}}};
    bool Norm_L_4[3][3] = {{{true}, {true}, {false}}, {{true}, {false}, {false}}, {{false}, {false}, {false}}};
    bool Norm_Bar_3_1[3][3] = {{{true}, {false}, {false}}, {{true}, {false}, {false}}, {{true}, {false}, {false}}};
    bool Norm_Bar_3_2[3][3] = {{{true}, {true}, {true}}, {{false}, {false}, {false}}, {{false}, {false}, {false}}};
    bool Hard_LL_1[3][3] = {{{true}, {true}, {false}}, {{false}, {true}, {true}}, {{false}, {false}, {false}}};
    bool Hard_LL_2[3][3] = {{{false}, {true}, {true}}, {{true}, {true}, {false}}, {{false}, {false}, {false}}};
    bool Hard_LL_3[3][3] = {{{true}, {false}, {false}}, {{true}, {true}, {false}}, {{false}, {true}, {false}}};
    bool Hard_LL_4[3][3] = {{{false}, {true}, {false}}, {{true}, {true}, {false}}, {{true}, {false}, {false}}};
    bool Hard_T_1[3][3] = {{{true}, {true}, {true}}, {{false}, {true}, {false}}, {{false}, {false}, {false}}};
    bool Hard_T_2[3][3] = {{{false}, {true}, {false}}, {{true}, {true}, {true}}, {{false}, {false}, {false}}};
    bool Hard_T_3[3][3] = {{{false}, {true}, {false}}, {{true}, {true}, {false}}, {{false}, {true}, {false}}};
    bool Hard_T_4[3][3] = {{{true}, {false}, {false}}, {{true}, {true}, {false}}, {{true}, {false}, {false}}};
    bool Hard_L_1[3][3] = {{{true}, {true}, {true}}, {{true}, {false}, {false}}, {{false}, {false}, {false}}};
    bool Hard_L_2[3][3] = {{{true}, {true}, {true}}, {{false}, {false}, {true}}, {{false}, {false}, {false}}};
    bool Hard_L_3[3][3] = {{{true}, {false}, {false}}, {{true}, {true}, {true}}, {{false}, {false}, {false}}};
    bool Hard_L_4[3][3] = {{{false}, {false}, {true}}, {{true}, {true}, {true}}, {{false}, {false}, {false}}};
    bool Norm_Bar_4[4] = {true};
    bool Board[100][100] = {false};

public:
    void Render_Game_Board()
    {
        for (int i = 0; i < boardsize; i++)
        {
            for (int j = 0; j < boardsize; j++)
            {
                ConXY(2 * i + 2, j + 1);
                if (Board[i][j])
                    cout << '#';
                else
                    cout << '-';
            }
        }
    }
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
                    ConClr(0);
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
                        ConClr(0);
                        keyz = _getch();
                        ConXY(X - 3, Y + 5);
                        cout << "                                               ";
                        ConXY(X - 4, Y + 7);
                        cout << "                                               ";
                        ConClr(7);
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
    void change_Game_Board(int X, int x, int y, bool obj[3][3])
    {
        int Y = 0;
        bool ok = false;
        for (int i = boardsize - y; i >= 0; i--)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < x; k++)
                {
                    if (obj[k][j])
                    {
                        if (Board[X + k][i + j])
                        {
                            break;
                        }
                    }
                }
                if (j == y - 1)
                {
                    ok = true;
                }
            }
            if (ok)
            {
                for (int j = i; j >= 0; j--)
                {
                    if (Board[X][j] || Board[X][j])
                    {
                        i = j;
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    Y = i;
                    break;
                }
            }
        }
        for (int i = 0; i < y; i++)
        {
            for (int k = 0; k < x; k++)
            {
                Board[X + k][Y + i] = obj[k][i];
            }
        }
        Render_Game_Board();
    }
    void play()
    {
        change_Game_Board(3, 2, 2, Norm_L_2);

        char cnt = _getch();
        change_Game_Board(3, 2, 1, easy_Bar_2);
    }
};

int main()
{
    Game game;
    game.start_menu();
    system("cls");
    game.Make_Game_Borad();
    char keyz = _getch();
    game.play();
    keyz = _getch();
    return 0;
}
