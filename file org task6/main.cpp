
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    int grade, del;

    ofstream out("Grades.txt");
    cout << "Enter five grades: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> grade;
        out << grade << endl;
    }
    out.close();

    ifstream in("Grades.txt");
    while (in >> grade)
        cout << grade << endl;
    in.close();

    cout << "Enter grade you want to delete: ";
    cin >> del;

    in.open("Grades.txt");
    ofstream temp("temp.txt");

    while (in >> grade)
    {
        if (grade != del)
        {
            temp << grade << endl;
        }
    }

    in.close();
    temp.close();

    remove("grades.txt");
    rename("temp.txt", "grades.txt");
    cout << "Grade deleted successfully\n";

    return 0;
}
