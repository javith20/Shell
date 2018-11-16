#ifndef MKDIR_H
#define MKDIR_H
#include <iostream>
#include <dirent.h>
#include "listaenlazada.h"
using namespace std;

class MkdirCommand
{
public:
    MkdirCommand();
    ListaEnlazada<string> createDir(string ruta);
};

#endif // MKDIR_H
