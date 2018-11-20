#ifndef ADMINSTRING_H
#define ADMINSTRING_H

#include <iostream>
#include <string.h>
#include <cstring>
#include <listaenlazada.cpp>
#include "ls.h"
#include "mkdir.h"
#include "rm.h"
#include "cp.h"
#include "date.h"
#include "fileeditor.h"

using namespace std;
class CutterCommand
{
public:
    CutterCommand();
    ~CutterCommand();
    string selectCommand();
    void OrganizeCommandData();
    void cutCommandStr(string commandStr);
    string cutLastCommand(string completeStr);
    string getProgramStr();
    string getRouteStr();
    string getUserStr();
    string getGroupStr();
    string getCompleteDataShell();
    ListaEnlazada<string> getHistoryStr();
    ListaEnlazada<string> getListParameters();

private:

    string programStr;
    string mainRouteStr;
    string userStr;
    string groupStr;
    ListaEnlazada<string> listParametersStr;
    ListaEnlazada<string> listRouteStr;
    ListaEnlazada<string> listHistoryStr;
    lsCommand ls;
    MkdirCommand mkdir;
    rmCommand rm;
    CpCommand cp;
    dateCommand date;
    fileEditor file;
};

#endif // ADMINSTRING_H
