#include "manager.h"
#include <fstream>
#include <iostream>

using namespace std;

Manager::Manager()
{

}

void Manager::init()
{
    ifstream read;
    read.open("data.txt");
    vector<Scientist> vec;
    if (read.is_open())
    {
        Scientist s;
        while(read >> s){
            add(s);
        }
    }
    else
    {
        cout << "There is no scientist on file." << endl;
    }
    read.close();
}

void Manager::add(Scientist s)
{    
    vec.push_back(s);
    writeAllToFile();
}

void Manager::writeAllToFile()
{
    ofstream write;
    write.open("data.txt");
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        write << vec[i].toFileFormat() << endl;
    }
    write.close();
}

void Manager::print()
{
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        cout << i << "." << endl;
        cout << vec[i];
        cout << endl;
    }
}

string Scientist::getName()
{
    return name;
}
string Scientist::getSex()
{
    return sex;
}

void Manager::remove()
{
    int v;
    cout << "would you like to remove by name or by number? " << endl;
    cout << "press 1 for name." << endl;
    cout << "press 2 for number." << endl;
    cout << "any other number returns to menu." << endl;
    cin >> v;


    if(v == 1){
       string name;
       bool flag = false;

       print();

       cout << "insert the name of the scientist you would like to remove: ";
       cin >> name;
        for(unsigned int i = 0; i < vec.size(); i++){
            if(vec[i].getName() == name){
                vec.erase(vec.begin() + i);
                flag = true;
                writeAllToFile();
                cout << name << " has been removed." << endl;
            }
        }
            if(flag == false){
            cout << "there is no scientist named " << name
                 << " in this file." << endl;
            }
     }

    else if(v == 2){
        unsigned int i;
         cout << "insert the number of the scientist you would like to remove: ";
         cin >> i;
         if(i < vec.size())
         {
             vec.erase(vec.begin() + i);
             writeAllToFile();
         }

         else if(v != 1 || v != 2){
             cout << "Returning to menu";
         }
     }
}

void Manager::search()
{
    string name;
    bool flag = false;

    cout << "Enter the name of the scientist you want to find: ";
    cin >> name;
    cout << endl;

    for(unsigned int i = 0; i < vec.size(); i++){
        if(vec[i].getName() == name){
            flag = true;
            cout << i << ". " << endl;
            cout << vec[i] << endl;

        }
    }

    if(flag == false){
        cout << "there is no scientist named " << name
             << " in this file." << endl;
    }
}
