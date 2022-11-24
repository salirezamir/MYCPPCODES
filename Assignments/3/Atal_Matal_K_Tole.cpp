#include <iostream>

using namespace std;

int main()
{
    /*
    n va k moteghyer haye vorodi va i tedad marhale atal matal ... hast
    i az 1 shroe shode chon yek marhale ro be dalil peyda nakardan moshkel dar shart 
    j%n != 1 neveshtam chon agar j=1 mishod for kar nemikard
    */
    int n, k, i = 1;
    cin >> n >> k;
    /*
    agar farz konim bazikonan adad gozari shode and j%n amalan nobat
    fard dar har dast bazi ra neshan midahad
    pas baray bargasht bayad bazi be dast bazikon aval beresad
    */
    for (int j = k + 1; j % n != 1; j += k)
        i++;
    cout << i;
}