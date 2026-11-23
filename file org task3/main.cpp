#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
fstream file;
string text;
file.open("welcome.txt",ios::out);

if (!file.is_open())
 {
   cout<<"error,file is not opened";
 }
else
  {
    file<<"Hello Everybody";
    file.seekp(11,ios::beg);
    file<<"one ";
    file.close();

    file.clear();

    file.open("welcome.txt",ios::in);
    getline(file,text);
    cout<<text;
    file.close();
  }



    return 0;
}
