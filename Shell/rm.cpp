#include "rm.h"

rmCommand::rmCommand()
{

}

ListaEnlazada<string> rmCommand::removeDir(string ruta)
{
    ListaEnlazada<string> listOut;
    int a =rmdir(ruta.c_str());
    if(a==-1)
        listOut.insertarFinal("Error, imposible eliminar directorio");
    else
        listOut.insertarFinal("Directorio eliminado");
    return listOut;
}
ListaEnlazada<string> rmCommand::removeFile(string ruta)
{
    ListaEnlazada<string> listOut;

    int a =remove(ruta.c_str());
    if(a==-1)
        listOut.insertarFinal("Error, imposible eliminar el archivo");
    else
        listOut.insertarFinal("archivo eliminado");
    return listOut;
}
