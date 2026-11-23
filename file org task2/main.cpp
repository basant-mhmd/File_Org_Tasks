#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream infruit;
   infruit.open("fruit.txt" , ios::in);
   string fruit;
   while (getline(infruit,fruit)){
    cout <<fruit<<endl;
   }
   infruit.close();

   ofstream outfruit ;
   outfruit.open("fruit.txt" , ios::app);
   outfruit<<"fresh fruit";
   outfruit.close();
   return 0;
}
