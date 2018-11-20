#ifndef FILEEDITOR_H
#define FILEEDITOR_H

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;


class fileEditor
{
public:
    fileEditor();
    void presentaMenuGeneral();
    int createFile(string name,string text);
    int readFile(string name);
    int modifyFile();
private :
    string contenido;
    string contenido2;
};

#endif // FILEEDITOR_H
