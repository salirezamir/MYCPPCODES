#include <iostream>

using namespace std;

class Student
{
    public:
    string Name, Tel, Zip;
};

int main()
{
    Student student;
    getline(cin, student.Name);
    getline(cin, student.Tel);
    getline(cin, student.Zip);
    cout << "Student Name : " << student.Name << endl;
    cout << "Student Phone Number : " << student.Tel << endl;
    cout << "Student Zip code : " << student.Zip;
}