#include <iostream>
#include <vector>

using namespace std;

class Stuff
{
public:
    int BC;
    int SC;
    int Rep;
    string Name;
    Stuff(int bc, int sc, int rep, string name)
    {
        BC = bc;
        SC = sc;
        Rep = rep;
        Name = name;
    }
};

class HSD
{
private:
    vector<Stuff> stuff;
    long Buy = 0, Sell = 0;
    int Find(string nam)
    {
        for (int i = 0; i < stuff.size(); i++)
        {
            if (stuff.at(i).Name == nam)
                return i;
        }
        return -1;
    }

public:
    void Define(string nam, int buy, int sel)
    {
        if (Find(nam) != -1)
        {
            cout << "!\n";
            return;
        }
        Stuff tmp(buy, sel, 0, nam);
        stuff.push_back(tmp);
        return;
    }
    void Delete(string nam)
    {
        int loc = Find(nam);
        if (loc == -1)
        {
            cout << "!\n";
            return;
        }
        if (stuff.at(loc).Rep != 0)
        {
            cout << "!\n";
            return;
        }
        stuff.erase(stuff.begin() + loc);
    }
    void SellF(string nam, int count)
    {
        int loc = Find(nam);
        if (stuff.at(loc).Rep <= count)
        {
            cout << "!\n";
            return;
        }
        stuff.at(loc).Rep -= count;
        Sell += stuff.at(loc).SC * count;
        return;
    }
    void BuyF(string nam, int count)
    {
        int loc = Find(nam);
        if (loc == -1)
        {
            cout << "!\n";
            return;
        }
        stuff.at(loc).Rep += count;
        Buy += stuff.at(loc).BC * count;
    }
    void Status()
    {
        for (int i = 0; i < stuff.size(); i++)
        {
            cout << stuff.at(i).Name << " " << stuff.at(i).BC << " " << stuff.at(i).SC << " " << stuff.at(i).Rep << endl;
        }
        return;
    }
    void Financial()
    {
        cout << Sell << " " << Buy << " " << Sell - Buy << endl;
    }
};

class UI
{
public:
    void terminal(HSD &hsd)
    {
        string cmd = "", arg0 = "";
        int arg1[2] = {0, 0};
        while (true)
        {
            cmd = "";
            arg0 = "";
            arg1[0] = 0;
            arg1[1] = 0;
            cout << "$ ";
            cin >> cmd;
            if (cmd == "Define")
            {
                cin >> arg0 >> arg1[0] >> arg1[1];
                hsd.Define(arg0, arg1[0], arg1[1]);
            }
            else if (cmd == "Delete")
            {
                cin >> arg0;
                hsd.Delete(arg0);
            }
            else if (cmd == "Sell")
            {
                cin >> arg0 >> arg1[0];
                hsd.SellF(arg0, arg1[0]);
            }
            else if (cmd == "Buy")
            {
                cin >> arg0 >> arg1[0];
                hsd.BuyF(arg0, arg1[0]);
            }
            else if (cmd == "Status")
            {
                hsd.Status();
            }
            else if (cmd == "Financial")
            {
                hsd.Financial();
            }
            else if (cmd == "Exit")
            {
                return;
            }
            else
            {
                cout << "Command Not Found !\n";
            }
        }
    }
};

int main()
{
    HSD hsd;
    UI ui;
    ui.terminal(hsd);
    return 0;
}