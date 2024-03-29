#include <iostream>

using namespace std;

class Wallet
{
private:
    int total;
    float saving;

public:
    Wallet(int x, float y)
    {
        total = x;
        saving = y;
    }
    void alert()
    {
        if (total == 50000)
            cout << "Alert!\n";
        return;
    }
    void add(int in)
    {
        total += in;
        cout << in << " added!\n";
        alert();
        return;
    }
    void withdraw(int in)
    {
        if (total < in)
        {
            cout << "low account balance\n";
            alert();
            return;
        }
        total -= in;
        cout << in << " withdrawed successfully\n";
        alert();
        return;
    }
    void save(int in, float per)
    {
        saving += in * per;
        total += in * (1 - per);
        cout << in * per << " saved!\n";
        alert();
        return;
    }
    int account_balance()
    {
        return total;
    }
};

int main()
{
    // Seyed Alireza Mirabedini
}