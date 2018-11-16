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
