#ifndef USER_H
#define USER_H
#include <iostream>
#include "listaenlazada.h"
using namespace std;
class User
{
public:
    User();
    string getName();
    void setName(string name);
    string getMainGroup();
    void setMainGroup();
    ListaEnlazada<string> getGroups();

    
private:
    string name;
    ListaEnlazada<string> groups;
    string passwd;
    int type;
};

#endif // USER_H
