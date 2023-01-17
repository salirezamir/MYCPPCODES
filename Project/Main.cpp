#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

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
    bool easy_Single[4][4] = {{true, false, false, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool easy_Bar_1[4][4] = {{true, true, false, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool easy_Bar_2[4][4] = {{true, false, false, false}, {true, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool easy_Square[4][4] = {{true, true, false, false}, {true, true, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Norm_L_1[4][4] = {{false, true, false, false}, {true, true, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Norm_L_2[4][4] = {{true, false, false, false}, {true, true, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Norm_L_3[4][4] = {{true, true, false, false}, {false, true, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Norm_L_4[4][4] = {{true, true, false, false}, {true, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Norm_Bar_3_1[4][4] = {{true, false, false, false}, {true, false, false, false}, {true, false, false, false}, {false, false, false, false}};
    bool Norm_Bar_3_2[4][4] = {{true, true, true, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_LL_1[4][4] = {{true, true, false, false}, {false, true, true, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_LL_2[4][4] = {{false, true, true, false}, {true, true, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_LL_3[4][4] = {{true, false, false, false}, {true, true, false, false}, {false, true, false, false}, {false, false, false, false}};
    bool Hard_LL_4[4][4] = {{false, true, false, false}, {true, true, false, false}, {true, false, false, false}, {false, false, false, false}};
    bool Hard_T_1[4][4] = {{true, true, true, false}, {false, true, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_T_2[4][4] = {{false, true, false, false}, {true, true, true, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_T_3[4][4] = {{false, true, false, false}, {true, true, false, false}, {false, true, false, false}, {false, false, false, false}};
    bool Hard_T_4[4][4] = {{true, false, false, false}, {true, true, false, false}, {true, false, false, false}, {false, false, false, false}};
    bool Hard_L_1[4][4] = {{true, true, true, false}, {true, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_L_2[4][4] = {{true, true, true, false}, {false, false, true, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_L_3[4][4] = {{true, false, false, false}, {true, true, true, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_L_4[4][4] = {{false, false, true, false}, {true, true, true, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_Bar_4_1[4][4] = {{true, true, true, true}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
    bool Hard_Bar_4_2[4][4] = {{true, false, false, false}, {true, false, false, false}, {true, false, false, false}, {true, false, false, false}};
    bool Board[100][100] = {false};
    bool Tmp[100][100] = {false};
    int cord = 0;
    unsigned int Score = 0;

    void Render_Game_Board(bool board[100][100])
    {
        for (int i = 0; i < boardsize; i++)
        {
            for (int j = 0; j < boardsize; j++)
            {
                ConXY(2 * i + 2, j + 1);
                if (board[i][j])
                    cout << '#';
                else
                    cout << '-';
            }
        }
    }
    void Copy_Board_To_Tmp()
    {
        for (int i = 0; i < boardsize; i++)
        {
            for (int j = 0; j < boardsize; j++)
                Tmp[i][j] = Board[i][j];
        }
    }

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
    bool change_Game_Board(int X, int x, int y, bool obj[4][4])
    {
        int Y = -1;
        for (int i = 0; i <= boardsize - y; i++)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < x; k++)
                {
                    if (obj[k][j])
                    {
                        if (Board[X + k][i + j])
                        {
                            Y = i - 1;
                            break;
                        }
                    }
                }
                if (Y > 0)
                    break;
            }
            if (Y > 0)
                break;
            if (Y < 0 && i == boardsize - y)
                return false;
        }
        if (Y == -1)
            Y = boardsize - y;
        for (int i = 0; i < y; i++)
        {
            for (int k = 0; k < x; k++)
            {
                if (obj[k][i])
                    Board[X + k][Y + i] = true;
            }
        }
        Render_Game_Board(Board);
        return true;
    }
    void Do(int cor, int mod)
    {
        switch (mod)
        {
        case 1:
            change_Game_Board(cor, 1, 1, easy_Single);
            break;
        case 2:
            change_Game_Board(cor, 2, 1, easy_Bar_2);
            break;
        case 3:
            change_Game_Board(cor, 1, 2, easy_Bar_1);
            break;
        case 4:
            change_Game_Board(cor, 2, 2, easy_Square);
            break;
        case 5:
            change_Game_Board(cor, 2, 2, Norm_L_1);
            break;
        case 6:
            change_Game_Board(cor, 2, 2, Norm_L_2);
            break;
        case 7:
            change_Game_Board(cor, 2, 2, Norm_L_3);
            break;
        case 8:
            change_Game_Board(cor, 2, 2, Norm_L_4);
            break;
        case 9:
            change_Game_Board(cor, 3, 1, Norm_Bar_3_1);
            break;
        case 10:
            change_Game_Board(cor, 1, 3, Norm_Bar_3_2);
            break;
        case 11:
            change_Game_Board(cor, 2, 3, Hard_LL_1);
            break;
        case 12:
            change_Game_Board(cor, 2, 3, Hard_LL_2);
            break;
        case 13:
            change_Game_Board(cor, 3, 2, Hard_LL_3);
            break;
        case 14:
            change_Game_Board(cor, 3, 2, Hard_LL_4);
            break;
        case 15:
            change_Game_Board(cor, 2, 3, Hard_L_1);
            break;
        case 16:
            change_Game_Board(cor, 2, 3, Hard_L_2);
            break;
        case 17:
            change_Game_Board(cor, 2, 3, Hard_L_3);
            break;
        case 18:
            change_Game_Board(cor, 2, 3, Hard_L_4);
            break;
        case 19:
            change_Game_Board(cor, 2, 3, Hard_T_1);
            break;
        case 20:
            change_Game_Board(cor, 2, 3, Hard_T_2);
            break;
        case 21:
            change_Game_Board(cor, 3, 2, Hard_T_3);
            break;
        case 22:
            change_Game_Board(cor, 3, 2, Hard_T_4);
            break;
        case 23:
            change_Game_Board(cor, 1, 4, Hard_Bar_4_1);
            break;
        case 24:
            change_Game_Board(cor, 4, 1, Hard_Bar_4_2);
            break;
        }
        return;
    }
    void Row_Checker()
    {
        bool f = true;
        int y = 0;
        for (int i = 0; i < boardsize; i++)
        {
            f = true;
            for (int j = 0; j < boardsize; j++)
            {
                if (!Board[j][i])
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                y = i;
                break;
            }
        }
        if (f)
        {
            for (int i = y; i > 0; i--)
            {
                for (int j = 0; j < boardsize; j++)
                {
                    Board[j][i] = Board[j][i - 1];
                }
            }
            for (int j = 0; j < boardsize; j++)
            {
                Board[j][0] = false;
            }
            Score += 10;
        }
        if (f)
            return Row_Checker();
        Render_Game_Board(Board);
    }
    void Move(int cor, bool right, int x, bool obj[4][4])
    {
        if (right)
            cor++;
        else
            cor--;
        if (right && cor + x > boardsize)
            return;
        if (!right && cor < 0)
            return;
        Copy_Board_To_Tmp();
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (obj[i][j])
                {
                    if (Tmp[i + cord][j])
                    {
                        if (right)
                            cor++;
                        else
                            cor--;
                        return Move(cor, right, x, obj);
                    }
                    Tmp[i + cord][j] = true;
                }
            }
        }
        Render_Game_Board(Tmp);
        cord = cor;
    }
    void Move_mod(int mod, bool R)
    {
        switch (mod)
        {
        case 1:
            Move(cord, R, 1, easy_Single);
            break;
        case 2:
            Move(cord, R, 2, easy_Bar_2);
            break;
        case 3:
            Move(cord, R, 1, easy_Bar_1);
            break;
        case 4:
            Move(cord, R, 2, easy_Square);
            break;
        case 5:
            Move(cord, R, 2, Norm_L_1);
            break;
        case 6:
            Move(cord, R, 2, Norm_L_2);
            break;
        case 7:
            Move(cord, R, 2, Norm_L_3);
            break;
        case 8:
            Move(cord, R, 2, Norm_L_4);
            break;
        case 9:
            Move(cord, R, 3, Norm_Bar_3_1);
            break;
        case 10:
            Move(cord, R, 1, Norm_Bar_3_2);
            break;
        case 11:
            Move(cord, R, 2, Hard_LL_1);
            break;
        case 12:
            Move(cord, R, 2, Hard_LL_2);
            break;
        case 13:
            Move(cord, R, 3, Hard_LL_3);
            break;
        case 14:
            Move(cord, R, 3, Hard_LL_4);
            break;
        case 15:
            Move(cord, R, 2, Hard_L_1);
            break;
        case 16:
            Move(cord, R, 2, Hard_L_2);
            break;
        case 17:
            Move(cord, R, 2, Hard_L_3);
            break;
        case 18:
            Move(cord, R, 2, Hard_L_4);
            break;
        case 19:
            Move(cord, R, 2, Hard_T_1);
            break;
        case 20:
            Move(cord, R, 2, Hard_T_2);
            break;
        case 21:
            Move(cord, R, 3, Hard_T_3);
            break;
        case 22:
            Move(cord, R, 3, Hard_T_4);
            break;
        case 23:
            Move(cord, R, 1, Hard_Bar_4_1);
            break;
        case 24:
            Move(cord, R, 4, Hard_Bar_4_2);
            break;
        }
    
    }
};

int main()
{
    Game game;
    game.start_menu();
    system("cls");
    game.Make_Game_Borad();
    char keys = _getch();
    return 0;
}
