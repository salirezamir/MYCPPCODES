#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

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

class Game
{
private:
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
    int boardsize[2] = {11, 11};
    unsigned int HighScore = 0;
    int diff[3] = {1, 1, 1};

    int Round_up(double in)
    {
        if (in == int(in))
            return in;
        return (1 + in);
    }

    int RndSel()
    {
        srand(time(0));
        int asd = 4 * diff[0] + 8 * diff[1] + 12 * diff[2];
        int opt = 1 + (rand() % asd);
        if (opt <= 4 * diff[0])
            return Round_up(opt / diff[0]);
        opt -= 4 * diff[0];
        if (opt <= 8 * diff[1])
            return Round_up(4 + (opt / diff[1]));
        opt -= 8 * diff[1];
        return Round_up(12 + (opt / diff[2]));
    }

    void Render_Game_Board(bool board[100][100])
    {
        for (int i = 0; i < boardsize[0]; i++)
        {
            for (int j = 0; j < boardsize[1]; j++)
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
        for (int i = 0; i < boardsize[0]; i++)
        {
            for (int j = 0; j < boardsize[1]; j++)
                Tmp[i][j] = Board[i][j];
        }
    }

    void Clear_a_Row()
    {
        for (int i = 0; i < boardsize[1]; i++)
        {
            for (int j = 0; j < boardsize[0]; j++)
            {
                if (Board[j][i])
                {
                    for (int k = 0; k < boardsize[0]; k++)
                    {
                        Board[k][i] = false;
                    }
                    return;
                }
            }
        }
    }
    void Game_Over()
    {
        system("cls");
        ConClr(4);
        cout << "   ********      **     ****     **** ********     *******   **      ** ******** *******  \n  **//////**    ****   /**/**   **/**/**/////     **/////** /**     /**/**///// /**////** \n **      //    **//**  /**//** ** /**/**         **     //**/**     /**/**      /**   /** \n/**           **  //** /** //***  /**/*******   /**      /**//**    ** /******* /*******  \n/**    ***** **********/**  //*   /**/**////    /**      /** //**  **  /**////  /**///**  \n//**  ////**/**//////**/**   /    /**/**        //**     **   //****   /**      /**  //** \n //******** /**     /**/**        /**/********   //*******     //**    /********/**   //**\n  ////////  //      // //         // ////////     ///////       //     //////// //     // \n";
        int set[2] = {116, 7};
        int X = 40;
        int Y = 10;
        ConXY(X - 5, Y + 6);
        ConClr(4);
        cout << "High Score : " << HighScore;
        ConXY(X - 5, Y + 5);
        cout << "Last Score : " << Score;
        int counter = 1;
        char key;
        char keyz;
        while (true)
        {
            ConXY(X, Y);
            ConClr(set[0]);
            cout << "Retry";
            ConXY(X, Y + 2);
            ConClr(set[1]);
            cout << "Exit";
            ConClr(7);
            key = _getch();
            if (key == 13)
            {
                if (counter == 1)
                {
                    for (int i = 0; i < boardsize[0]; i++)
                    {
                        for (int j = 0; j < boardsize[1]; j++)
                            Board[i][j] = false;
                    }
                    return;
                }
                if (counter == 2)
                {
                    system("cls");
                    exit(0);
                }
            }

            if (key == -32)
            {
                keyz = _getch();
                if (keyz == 72 && counter == 2)
                    counter = 1;
                if (keyz == 80 && counter == 1)
                    counter = 2;
            }
            set[0] = 7;
            set[1] = 7;
            set[counter - 1] = 116;
        }
    }

    void Hint(int x, int y)
    {
        ConClr(226);
        ConXY(x, y);
        cout << "UP & DOWN ARROW : SELECTING ITEMS IN MENU";
        ConXY(x, y + 1);
        cout << "         A : MOVE BLOCK TO LEFT          ";
        ConXY(x, y + 2);
        cout << "         D : MOVE BLOCK TO RIGHT         ";
        ConXY(x, y + 3);
        cout << "         S : FALL DOWN THE BLOCK         ";
        ConXY(x, y + 4);
        cout << "                                         ";
        ConXY(x, y + 5);
        cout << "        PRESS ANY KEY TO CONTINUE        ";
        ConClr(7);
        _getch();
        for (int i = 0; i < 6; i++)
        {
            ConXY(x, y + i);
            cout << "                                         ";
        }
    }
    void High_Score(int x, int y)
    {
        ConClr(186);
        ConXY(x, y);
        cout << "  _____  ______ _____ ____  _____  _____  _  ";
        ConXY(x, y + 1);
        cout << " |  __ \\|  ____/ ____/ __ \\|  __ \\|  __ \\| | ";
        ConXY(x, y + 2);
        cout << " | |__) | |__ | |   | |  | | |__) | |  | | | ";
        ConXY(x, y + 3);
        cout << " |  _  /|  __|| |   | |  | |  _  /| |  | | | ";
        ConXY(x, y + 4);
        cout << " | | \\ \\| |___| |___| |__| | | \\ \\| |__| |_| ";
        ConXY(x, y + 5);
        cout << " |_|  \\_\\______\\_____\\____/|_|  \\_\\_____/(_) ";
        ConXY(x, y + 6);
        cout << "                                             ";
        ConXY(x, y + 7);
        cout << "          PRESS ANY KEY TO CONTINUE          ";
        ConClr(7);
        _getch();
        for (int i = 0; i < 8; i++)
        {
            ConXY(x, y + i);
            cout << "                                             ";
        }
    }
    void Exit()
    {
        system("cls");
        ConClr(10);
        cout << "oooooooooo o888                        oooo         oooooooooo                                      o888             \n 888    888 888   ooooooo     ooooooo   888  ooooo   888    888 oooo  oooo  ooooooooooo ooooooooooo  888  ooooooooo8 \n 888oooo88  888 888     888 888     888 888o888      888oooo88   888   888       8888        8888    888 888oooooo8  \n 888    888 888 888     888 888         8888 88o     888         888   888    8888        8888       888 888         \no888ooo888 o888o  88ooo88     88ooo888 o888o o888o  o888o         888o88 8o o888ooooooo o888ooooooo o888o  88oooo888 \n ";
        ConClr(7);
        ConXY(50, 16);
        ConClr(4);
        cout << "High Score : " << HighScore;
        ConXY(50, 15);
        cout << "Last Score : " << Score;
        ConClr(109);
        ConXY(47, 18);
        cout << "PRESS ANY KEY TO EXIT";
        _getch();
        ConClr(7);
        system("cls");
        exit(0);
    }

    void Make_Game_Borad()
    {
        ConClr(238);
        ConXY(0, 0);
        for (int i = 1; i <= 1 + 2 * (1 + boardsize[0]); i++)
        {
            cout << " ";
        }
        ConXY(0, (boardsize[1] + 1));
        for (int i = 1; i <= 1 + 2 * (1 + boardsize[0]); i++)
        {
            cout << " ";
        }
        for (int i = 1; i <= boardsize[1]; i++)
        {
            ConXY(0, i);
            cout << " ";
            ConXY((1 + boardsize[0]) * 2, i);
            cout << " ";
        }
    }

    void change_Game_Board(int X, int x, int y, bool obj[4][4])
    {
        int Y = -1;
        for (int i = 0; i <= boardsize[1] - y; i++)
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
                            for (int i = 0; i < y; i++)
                            {
                                for (int k = 0; k < x; k++)
                                {
                                    if (obj[k][i])
                                        Board[X + k][Y + i] = true;
                                }
                            }
                            return;
                        }
                    }
                }
                if (Y > 0)
                    break;
            }
            if (Y > 0)
                break;
        }
        if (Y == -1)
        {
            Y = boardsize[1] - y;
            for (int i = 0; i < y; i++)
            {
                for (int k = 0; k < x; k++)
                {
                    if (obj[k][i])
                        Board[X + k][Y + i] = true;
                }
            }
            Render_Game_Board(Board);
        }
        return;
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
        cord = 0;
        return;
    }

    void Row_Checker()
    {
        bool f[2];
        int y = 0;
        int x = 0;
        for (int i = 0; i < boardsize[1]; i++)
        {
            f[0] = true;
            for (int j = 0; j < boardsize[0]; j++)
            {
                if (!Board[j][i])
                {
                    f[0] = false;
                    break;
                }
            }
            if (f[0])
            {
                y = i;
                break;
            }
        }
        if (f[0])
        {
            for (int i = y; i > 0; i--)
            {
                for (int j = 0; j < boardsize[0]; j++)
                {
                    Board[j][i] = Board[j][i - 1];
                }
            }
            for (int j = 0; j < boardsize[0]; j++)
            {
                Board[j][0] = false;
            }
            Score += 10;
            return Row_Checker();
        }
        for (int i = 0; i < boardsize[0]; i++)
        {
            f[1] = true;
            for (int j = 0; j < boardsize[1]; j++)
            {
                if (!Board[i][j])
                {
                    f[1] = false;
                    break;
                }
            }
            if (f[1])
            {
                x = i;
                break;
            }
        }
        if (f[1])
        {
            for (int j = 0; j < boardsize[1]; j++)
            {
                Board[x][j] = false;
            }
            Score += 10;
            return Row_Checker();
        }
    }

    bool Move(int cor, bool right, int x, bool obj[4][4])
    {
        if (right)
            cor++;
        else
            cor--;
        if (right && cor + x > boardsize[0])
            return false;
        if (!right && cor <= -1)
            return true;
        Copy_Board_To_Tmp();
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (obj[i][j])
                {
                    if (Tmp[i + cor][j])
                        return Move(cor, right, x, obj);
                    Tmp[i + cor][j] = true;
                }
            }
        }
        cord = cor;
        Render_Game_Board(Tmp);
        return true;
    }
    bool Move_mod(int mod, bool R)
    {
        switch (mod)
        {
        case 1:
            return Move(cord, R, 1, easy_Single);
            break;
        case 2:
            return Move(cord, R, 2, easy_Bar_2);
            break;
        case 3:
            return Move(cord, R, 1, easy_Bar_1);
            break;
        case 4:
            return Move(cord, R, 2, easy_Square);
            break;
        case 5:
            return Move(cord, R, 2, Norm_L_1);
            break;
        case 6:
            return Move(cord, R, 2, Norm_L_2);
            break;
        case 7:
            return Move(cord, R, 2, Norm_L_3);
            break;
        case 8:
            return Move(cord, R, 2, Norm_L_4);
            break;
        case 9:
            return Move(cord, R, 3, Norm_Bar_3_1);
            break;
        case 10:
            return Move(cord, R, 1, Norm_Bar_3_2);
            break;
        case 11:
            return Move(cord, R, 2, Hard_LL_1);
            break;
        case 12:
            return Move(cord, R, 2, Hard_LL_2);
            break;
        case 13:
            return Move(cord, R, 3, Hard_LL_3);
            break;
        case 14:
            return Move(cord, R, 3, Hard_LL_4);
            break;
        case 15:
            return Move(cord, R, 2, Hard_L_1);
            break;
        case 16:
            return Move(cord, R, 2, Hard_L_2);
            break;
        case 17:
            return Move(cord, R, 2, Hard_L_3);
            break;
        case 18:
            return Move(cord, R, 2, Hard_L_4);
            break;
        case 19:
            return Move(cord, R, 2, Hard_T_1);
            break;
        case 20:
            return Move(cord, R, 2, Hard_T_2);
            break;
        case 21:
            return Move(cord, R, 3, Hard_T_3);
            break;
        case 22:
            return Move(cord, R, 3, Hard_T_4);
            break;
        case 23:
            return Move(cord, R, 1, Hard_Bar_4_1);
            break;
        case 24:
            return Move(cord, R, 4, Hard_Bar_4_2);
            break;
        }
        return false;
    }
    void Next_Block(int x, int y, bool obj[4][4])
    {
        for (int i = 0; i < 4; i++)
        {
            ConXY(x, y + i);
            for (int j = 0; j < 4; j++)
            {
                if (obj[j][i])
                    cout << '#';
                else
                    cout << ' ';
            }
        }
    }
    void Next_mod(int x, int y, int mod)
    {
        switch (mod)
        {
        case 1:
            return Next_Block(x, y, easy_Single);
            break;
        case 2:
            return Next_Block(x, y, easy_Bar_2);
            break;
        case 3:
            return Next_Block(x, y, easy_Bar_1);
            break;
        case 4:
            return Next_Block(x, y, easy_Square);
            break;
        case 5:
            return Next_Block(x, y, Norm_L_1);
            break;
        case 6:
            return Next_Block(x, y, Norm_L_2);
            break;
        case 7:
            return Next_Block(x, y, Norm_L_3);
            break;
        case 8:
            return Next_Block(x, y, Norm_L_4);
            break;
        case 9:
            return Next_Block(x, y, Norm_Bar_3_1);
            break;
        case 10:
            return Next_Block(x, y, Norm_Bar_3_2);
            break;
        case 11:
            return Next_Block(x, y, Hard_LL_1);
            break;
        case 12:
            return Next_Block(x, y, Hard_LL_2);
            break;
        case 13:
            return Next_Block(x, y, Hard_LL_3);
            break;
        case 14:
            return Next_Block(x, y, Hard_LL_4);
            break;
        case 15:
            return Next_Block(x, y, Hard_L_1);
            break;
        case 16:
            return Next_Block(x, y, Hard_L_2);
            break;
        case 17:
            return Next_Block(x, y, Hard_L_3);
            break;
        case 18:
            return Next_Block(x, y, Hard_L_4);
            break;
        case 19:
            return Next_Block(x, y, Hard_T_1);
            break;
        case 20:
            return Next_Block(x, y, Hard_T_2);
            break;
        case 21:
            return Next_Block(x, y, Hard_T_3);
            break;
        case 22:
            return Next_Block(x, y, Hard_T_4);
            break;
        case 23:
            return Next_Block(x, y, Hard_Bar_4_1);
            break;
        case 24:
            return Next_Block(x, y, Hard_Bar_4_2);
            break;
        }
    }

public:
    void start_menu()
    {
        system("cls");
        cout << "oooooooooo o888                        oooo         oooooooooo                                      o888             \n 888    888 888   ooooooo     ooooooo   888  ooooo   888    888 oooo  oooo  ooooooooooo ooooooooooo  888  ooooooooo8 \n 888oooo88  888 888     888 888     888 888o888      888oooo88   888   888       8888        8888    888 888oooooo8  \n 888    888 888 888     888 888         8888 88o     888         888   888    8888        8888       888 888         \no888ooo888 o888o  88ooo88     88ooo888 o888o o888o  o888o         888o88 8o o888ooooooo o888ooooooo o888o  88oooo888 \n ";
        int set[3] = {116, 7, 7};
        int X = 50;
        int Y = 10;
        int tmp = 0;
        ConClr(7);
        ConXY(X - 16, Y + 15);
        cout << "  Use up & down Arrow keys for menu navigating ";
        ConXY(X - 16, Y + 16);
        cout << "Telegram : @JVUXE | @TheRealStan_313 | @mmrezaw";
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
                    set[0] = 116;
                    set[1] = 7;
                    set[2] = 7;
                    X = 20;
                    Y = 15;
                    counter = 1;
                    ConXY(X, Y - 1);
                    ConClr(7);
                    cout << "Select Difficulty";
                    while (true)
                    {
                        ConXY(X + 5, Y);
                        ConClr(set[0]);
                        cout << "Defualt";
                        ConXY(X + 5, Y + 1);
                        ConClr(set[1]);
                        cout << "Custom";
                        ConXY(X + 6, Y + 2);
                        ConClr(set[2]);
                        cout << "Back";
                        ConClr(7);
                        key = _getch();
                        if (key == 13)
                        {
                            if (counter == 1)
                            {
                                diff[0] = 1;
                                diff[1] = 1;
                                diff[2] = 1;
                                boardsize[0] = 11;
                                boardsize[1] = 11;
                                system("cls");
                                return start_menu();
                            }
                            if (counter == 2)
                            {
                                ConXY(X + 20, Y - 1);
                                ConClr(207);
                                cout << "INPUT VALUES OF LENGTHS MUST BIGGER THEN 11";
                                ConClr(228);
                                ConXY(X + 20, Y);
                                cout << "Input vertical length";
                                ConClr(0);
                                cin >> tmp;
                                if (tmp >= 11)
                                {
                                    ConClr(7);
                                    ConXY(X + 20, Y);
                                    cout << "                                                 ";
                                    boardsize[1] = tmp;
                                    ConClr(228);
                                    ConXY(X + 20, Y);
                                    cout << "Input Horizental length";
                                    ConClr(0);
                                    cin >> tmp;
                                    if (tmp >= 11)
                                    {
                                        boardsize[0] = tmp;
                                        ConClr(7);
                                        ConXY(X + 20, Y);
                                        cout << "                                                 ";
                                        ConXY(X + 20, Y - 1);
                                        cout << "                                                ";
                                        set[0] = 116;
                                        set[1] = 7;
                                        set[2] = 7;
                                        X = 50;
                                        Y = 15;
                                        counter = 1;
                                        ConXY(X, Y - 1);
                                        ConClr(7);
                                        cout << "Select Difficulty";
                                        while (true)
                                        {
                                            ConXY(X + 6, Y);
                                            ConClr(set[0]);
                                            cout << "HARD";
                                            ConXY(X + 5, Y + 1);
                                            ConClr(set[1]);
                                            cout << "NORMALL";
                                            ConXY(X + 6, Y + 2);
                                            ConClr(set[2]);
                                            cout << "EASY";
                                            ConClr(7);
                                            key = _getch();
                                            if (key == 13)
                                            {
                                                if (counter == 1)
                                                {
                                                    diff[0] = 3;
                                                    diff[1] = 2;
                                                    diff[2] = 1;
                                                    return start_menu();
                                                }
                                                if (counter == 2)
                                                {
                                                    diff[0] = 1;
                                                    diff[1] = 1;
                                                    diff[2] = 1;
                                                    return start_menu();
                                                }
                                                if (counter == 3)
                                                {
                                                    diff[0] = 1;
                                                    diff[1] = 2;
                                                    diff[2] = 3;
                                                    return start_menu();
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
                                    ConClr(79);
                                    ConXY(X + 20, Y);
                                    cout << "INPUT VALUE IS INVALID  PRESS ANY KEY TO BACK";
                                    _getch();
                                    ConClr(7);
                                    ConXY(X + 20, Y);
                                    cout << "                                                 ";
                                    ConXY(X + 20, Y - 1);
                                    cout << "                                                ";
                                }
                            }
                            if (counter == 3)
                            {

                                system("cls");
                                return start_menu();
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

    void Play()
    {
        system("cls");
        Make_Game_Borad();
        Score = 0;
        srand(time(0));
        int set[4] = {116, 7, 7, 0};
        int mod = RndSel();
        int nmod = RndSel();
        int X = 6 + 5 * boardsize[0] / 2;
        int Y = -1 + boardsize[1] / 2;
        ConClr(95);
        ConXY(X - 6, Y - 1);
        cout << "Next";
        Next_mod(X - 6, Y, nmod);
        ConClr(7);
        cord = -1;
        Move_mod(mod, true);
        int counter = 1;
        char key;
        char keyz;
        bool high = false;
        while (true)
        {
            if (Score > HighScore)
            {
                if (!high)
                {
                    High_Score(X, Y);
                    high = false;
                }
                HighScore = Score;
            }
            ConXY(X, Y);
            ConClr(set[0]);
            cout << "Retry";
            ConXY(X, Y + 1);
            ConClr(set[1]);
            cout << "Hint";
            ConXY(X, Y + 2);
            ConClr(set[2]);
            cout << "Exit";
            ConXY(X, Y + 3);
            ConClr(set[3]);
            cout << "Clear a row";
            ConClr(7);
            ConXY(X, Y + 4);
            cout << "High SCORE : " << HighScore;
            ConXY(X, Y + 5);
            cout << "SCORE : " << Score;
            key = _getch();
            if (key == 13)
            {
                if (counter == 1)
                {
                    if (HighScore < Score)
                        HighScore = Score;
                    for (int i = 0; i < boardsize[0]; i++)
                    {
                        for (int j = 0; j < boardsize[1]; j++)
                            Board[i][j] = false;
                    }
                    return Play();
                }
                if (counter == 2)
                {
                    Hint(X, Y);
                }
                if (counter == 3)
                {
                    Exit();
                }
                if (counter == 4)
                {
                    Score -= 50;
                    Clear_a_Row();
                    if (Score < 50)
                        counter--;
                }
            }
            if (key == -32)
            {
                keyz = _getch();
                if (keyz == 72 && counter > 1)
                    counter--;
                if (keyz == 80 && ((Score >= 50 && counter < 4) || (counter < 3)))
                {
                    counter++;
                }
            }
            if (key == 'a' || key == 'A')
                Move_mod(mod, false);
            if (key == 'd' || key == 'd')
                Move_mod(mod, true);
            if (key == 's' || key == 'S')
            {
                Do(cord, mod);
                Row_Checker();
                cord = -1;
                mod = nmod;
                nmod = RndSel();
                ConClr(95);
                Next_mod(X - 6, Y, nmod);
                ConClr(7);
                if (!Move_mod(mod, true))
                {
                    if (HighScore < Score)
                        HighScore = Score;
                    Game_Over();
                    break;
                }
            }
            set[0] = 7;
            set[1] = 7;
            set[2] = 7;
            if (Score >= 50)
                set[3] = 43;
            else
                set[3] = 0;
            set[counter - 1] = 116;
        }
        return Play();
    }
};

int main()
{
    Game game;
    game.start_menu();
    game.Play();
    return 0;
}
