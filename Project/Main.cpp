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
    void change_Game_Board(int X, int mod)
    {
        bool obj[4][3];
        int x = 0, y = 0;
        switch (mod)
        {
        case 1:
            x = 1;
            y = 1;
            obj[0][0] = true;
            break;
        case 2:
            x = 2;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[1][0] = true;
            obj[1][1] = true;
            break;
        case 3:
            x = 2;
            y = 1;
            obj[1][0] = true;
            obj[1][1] = true;
            break;
        case 4:
            x = 1;
            y = 2;
            obj[0][1] = true;
            obj[0][1] = true;
            break;
        case 5:
            x = 3;
            y = 1;
            obj[0][0] = true;
            obj[1][0] = true;
            obj[2][0] = true;
            break;
        case 6:
            y = 3;
            x = 1;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[0][2] = true;
            break;
        case 7:
            x = 4;
            y = 1;
            obj[0][0] = true;
            obj[1][0] = true;
            obj[2][0] = true;
            obj[3][0] = true;
            break;
        case 8:
            x = 1;
            y = 4;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[0][2] = true;
            obj[0][3] = true;
            break;
        case 9:
            x = 2;
            y = 2;
            obj[0][0] = false;
            obj[0][1] = true;
            obj[1][0] = true;
            obj[1][1] = true;
            break;
        case 10:
            x = 2;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[1][0] = false;
            obj[1][1] = true;
            break;
        case 11:
            x = 2;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = false;
            obj[1][0] = true;
            obj[1][1] = true;
            break;
        case 12:
            x = 2;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[1][0] = true;
            obj[1][1] = false;
            break;
        case 13:
            x = 3;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = false;
            obj[1][0] = true;
            obj[1][1] = true;
            obj[2][0] = false;
            obj[2][1] = true;
            break;
        case 14:
            x = 3;
            y = 2;
            obj[0][0] = false;
            obj[0][1] = true;
            obj[1][0] = true;
            obj[1][1] = true;
            obj[2][0] = true;
            obj[2][1] = false;
            break;
        case 15:
            x = 2;
            y = 3;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[0][2] = false;
            obj[1][0] = false;
            obj[1][1] = true;
            obj[1][2] = true;
            break;
        case 16:
            x = 2;
            y = 3;
            obj[0][0] = false;
            obj[0][1] = true;
            obj[0][2] = true;
            obj[1][0] = true;
            obj[1][1] = true;
            obj[1][2] = false;
            break;
        case 17:
            x = 3;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = false;
            obj[1][0] = true;
            obj[1][1] = true;
            obj[2][0] = true;
            obj[2][1] = false;
            break;
        case 18:
            x = 3;
            y = 2;
            obj[0][0] = false;
            obj[0][1] = true;
            obj[1][0] = true;
            obj[1][1] = true;
            obj[2][0] = false;
            obj[2][1] = true;
            break;
        case 19:
            x = 2;
            y = 3;
            obj[0][0] = false;
            obj[0][1] = true;
            obj[0][2] = false;
            obj[1][0] = true;
            obj[1][1] = true;
            obj[1][2] = true;
            break;
        case 20:
            x = 2;
            y = 3;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[0][2] = true;
            obj[1][0] = false;
            obj[1][1] = true;
            obj[1][2] = false;
            break;
        case 21:
            x = 3;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = false;
            obj[1][0] = true;
            obj[1][1] = false;
            obj[2][0] = true;
            obj[2][1] = true;
            break;
        case 22:
            x = 3;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[1][0] = true;
            obj[1][1] = false;
            obj[2][0] = true;
            obj[2][1] = false;
            break;
        case 23:
            x = 3;
            y = 2;
            obj[0][0] = false;
            obj[0][1] = true;
            obj[1][0] = false;
            obj[1][1] = true;
            obj[2][0] = true;
            obj[2][1] = true;
            break;
        case 24:
            x = 3;
            y = 2;
            obj[0][0] = true;
            obj[0][1] = true;
            obj[1][0] = false;
            obj[1][1] = true;
            obj[2][0] = false;
            obj[2][1] = true;
            break;
        }
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
                if (j == 2)
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
                Board[X][Y + i] = obj[0][i];
            }
        }
        Render_Game_Board();
    }
    void play()
    {
        char cnt = _getch();
    }
};

int main()
{
    Game game;
    game.start_menu();
    game.Make_Game_Borad();
    char keyz = _getch();
    game.play();
    keyz = _getch();
    return 0;
}
