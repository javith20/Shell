#include "ls.h"

lsCommand::lsCommand()
{

}
ListaEnlazada<string> lsCommand::getFiles(string directory)
{   // Extraido de https://www.elotrolado.net/hilo_no-archivos-en-un-directorio-lenguaje-c_1639761
    cout << directory << endl;
    ListaEnlazada<string> listFiles;
    DIR *dir;
    struct dirent *file;
    dir = opendir(directory.c_str());
    if(dir == NULL)
        listFiles.insertarFinal("Error de direccion");

    while(file = readdir(dir))
    {
        cout<< file->d_name<<endl;
        string filename =file->d_name;
        if(filename !=".")
            listFiles.insertarFinal(filename);
         //aqui haces lo que quieras con el fichero encontrado
         //en fichero->d_name tienes el nombre del fichero
         //cada iteracion de este bloque es por cada entrada en el directorio, sean directorios o ficheros
    }
    closedir(dir);
    return listFiles;
}
