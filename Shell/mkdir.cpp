#include "mkdir.h"

MkdirCommand::MkdirCommand()
{

}

ListaEnlazada<string> MkdirCommand::createDir(string ruta)
{
    ListaEnlazada<string> listOut;

    int a = mkdir(ruta.c_str());
    std::cout << a <<std::endl;
    if(a==-1)
        listOut.insertarFinal("Error, imposible crear directorio");
    else
        listOut.insertarFinal("Carpeta creada");
    return listOut;
}
