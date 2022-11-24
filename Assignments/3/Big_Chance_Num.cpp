#include <iostream>

using namespace std;

int main()
{
    long n;
    cin >> n;
    //az e'enja be bad n mahale noghte ba hazf kardan noghat sookhte da har dor ast
    for (int i = 2; i < n; i++)
    {
        /*
        agar har dast bekhahim n dar mian hazf konim pas a'dad j*(n+1) j az n ta inf 
            hazf mishvad (n+1 dar e'en code i ast)
        alabte ke ma to inf ro lazem nadarim va faghat to ghable adad vorodi moon kafee ast
        agar mokhtrasate adad da har dore hazf mazrab iu bashd hazf migardad pas if zir ra neveshtam
        */
        if (n % i == 0)
        {
            cout << "NO";
            return 1;
        }
        // long(n / i) tedad adad hazf shode ast ke ba kam kardan A'n makan jadid adad ra baray dor jadid peyad mikonim
        // lazem be zekr nist ke vaghti be e'en khat residim yani adad ma be dor bad rah yafte
        n -= long(n / i);
    }
    //agar i (tarif shode dar for) az n bistar shavad yani digar dar khatar hazf nist va az for biron miaiim 
    cout << "YES";
    return 1;
}