#ifndef LS_H
#define LS_H
#include <iostream>
#include <dirent.h>
#include "listaenlazada.h"
using namespace std;
class lsCommand
{
public:
    lsCommand();
    ListaEnlazada<string> getFiles(string dir);
};

#endif // LS_H
