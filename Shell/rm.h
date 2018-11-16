#ifndef RM_H
#define RM_H
#include <iostream>
#include <dirent.h>
#include "listaenlazada.h"
using namespace std;

class rmCommand
{
public:
    rmCommand();
    ListaEnlazada<string> removeDir(string ruta);
};

#endif // MKDIR_H
