#ifndef LS_H
#define LS_H
#include <iostream>
#include <dirent.h>
#include "listaenlazada.h"
#include <stdio.h>
using namespace std;
class lsCommand
{
public:
    lsCommand();
    ListaEnlazada<string> getFiles(string dir);
    bool isFile(string route);
    bool isDir(string route);

};

#endif // LS_H
