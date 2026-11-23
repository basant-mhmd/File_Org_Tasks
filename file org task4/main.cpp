#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct persons
{
    string name ;
    int age ;
};

int main()
{
    int pernum;

    fstream datafile;
    datafile.open("persons_data.txt",ios::out);

    cout <<"Enter  number of persons: \n";
    cin >>pernum;

    for(int i=0; i<pernum; i++)
    {
    persons P;

    cout << "Enter name: ";
    cin  >> P.name;

    cout <<"Enter age: ";
    cin >> P.age;

    datafile<<P.name<<"  "<<P.age<<endl;

    }
    datafile.close();

   datafile.open("persons_data.txt",ios::in);
   vector<persons> vperson;
   persons temp;
   while(datafile>>temp.name>>temp.age)
   {
        vperson.push_back(temp);
   }
   datafile.close();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


   persons younger = vperson[0];
   persons older = vperson[0];
   for(int i=1; i<vperson.size(); i++)
   {
       if(vperson[i].age < younger.age)
       {
           younger=vperson[i];
       }

       if(vperson[i].age > older.age)
       {
           older=vperson[i];
       }
   }
   fstream resfile;
   resfile.open("age_result.txt",ios::out);

   resfile<<"Younger person is: "<<younger.name<<"  "<<younger.age<<endl;
   resfile<<"Older person is: "<<older.name<<"   "<<older.age<<endl;

   resfile.close();

   cout<<"data saved successfully.";
    return 0;
}
