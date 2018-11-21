#ifndef CP_H
#define CP_H
#include <iostream>
#include <dirent.h>
#include "listaenlazada.h"
using namespace std;


class CpCommand
{
public:
    CpCommand();
    ListaEnlazada<string> copyFile(string rutaInicio, string rutaFin);

};

#endif // CPCOMMAND_H
