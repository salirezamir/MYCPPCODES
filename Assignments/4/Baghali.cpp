#include <iostream>
#include <vector>

using namespace std;

class HSD
{
private:
    vector<int> BC;
    vector<int> SC;
    vector<int> rep;
    vector<string> Name;
    long Buy = 0, Sell = 0;
    int Find(string nam)
    {
        for (int i = 0; i < Name.size(); i++)
        {
            if (Name.at(i) == nam)
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
        BC.push_back(buy);
        SC.push_back(sel);
        Name.push_back(nam);
        rep.push_back(0);
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
        if (rep.at(loc) != 0)
        {
            cout << "!\n";
            return;
        }
        Name.erase(Name.begin() + loc);
        BC.erase(BC.begin() + loc);
        SC.erase(SC.begin() + loc);
        rep.erase(rep.begin() + loc);
    }
    void SellF(string nam, int count)
    {
        int loc = Find(nam);
        if (rep.at(loc) <= count)
        {
            cout << "!\n";
            return;
        }
        rep.at(loc) -= count;
        Sell += SC.at(loc) * count;
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
        rep.at(loc) += count;
        Buy += BC.at(loc) * count;
    }
    void Status()
    {
        for (int i = 0; i < Name.size(); i++)
        {
            cout << Name.at(i) << " " << BC.at(i) << " " << SC.at(i) << " " << rep.at(i) << endl;
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