#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("students.txt", ios::out  | ios::app );

    char name[20], stop_char= 'y';
    int id;
    float grade;
    char delim = '$';

    if (!file.is_open())
    {
        cout << "Error, file not opened!";
        return 1;
    }

    while (stop_char == 'y')
    {
        cout << "Enter student name: ";
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        file << name << ", " << id << ", "<< grade << " " << delim << endl;

        cout << "Add another student? (y/n): ";
        cin >> stop_char;
        cin.ignore();
    }

    file.close();

    cout << "Records saved successfully";

    return 0;
}