#include <iostream>

using namespace std;

class Student
{
public:
    string Name, Tel, Zip;
    void print()
    {
        cout << "Student Name : " << Name << endl;
        cout << "Student Phone Number : " << Tel << endl;
        cout << "Student Zip code : " << Zip;
    }
};

int main()
{
    Student student;
    getline(cin, student.Name);
    getline(cin, student.Tel);
    getline(cin, student.Zip);
    student.print();
}