#include "iostream"
using namespace std;

bool error(double d, double m, double y)
{
    if (d != int(d))
        return true;
    if (m != int(m))
        return true;
    if (m != int(m))
        return true;
    if (m > 12)
        return true;
    if (m < 1)
        return true;
    // if (m < 7)
    //     if (d > 31)
    //         return true;
    // if (m > 6)
    if (d > 30)
        return true;
    if (d < 1)
        return true;
    if (y > 1400)
        return true;
    if (y < 1300)
        return true;
    return false;
}

string mounthConverter(int m)
{
    switch (m)
    {
    case 1:
        return "Farvardin";
        break;
    case 2:
        return "Ordibehesht";
        break;
    case 3:
        return "Khordad";
        break;
    case 4:
        return "Tir";
        break;
    case 5:
        return "Mordad";
        break;
    case 6:
        return "Shahrivar";
        break;
    case 7:
        return "Mehr";
        break;
    case 8:
        return "Aban";
        break;
    case 9:
        return "Azar";
        break;
    case 10:
        return "Dey";
        break;
    case 11:
        return "Bahman";
        break;
    case 12:
        return "Esfand";
        break;
    }
}

int main()
{
    double t[3];
    cin >> t[0] >> t[1] >> t[2];
    if (error(t[0], t[1], t[2]))
    {
        cout << "ERROR: The numbers that you entered aren't in the correct format!";
        return 0;
    }
    cout << mounthConverter(t[1]) << " " << t[0] << ", " << t[2];
    return 1;
}