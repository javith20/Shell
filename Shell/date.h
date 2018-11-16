#ifndef DATECOMMAND_H
#define DATECOMMAND_H

#include <ctime>
#include <iostream>
#include "listaenlazada.h"
using namespace std;
class dateCommand
{
public:
    dateCommand();
    ListaEnlazada<string> getTime();
    ListaEnlazada<string> getDate();
    ListaEnlazada<string> getDateAndTime();
private:
    ListaEnlazada <string> listDate;
    time_t now = time(0);
    tm *ltm = localtime(&now);
};

#endif // DATE_H
