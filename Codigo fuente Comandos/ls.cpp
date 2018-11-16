#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <dirent.h>
using namespace std;
    int main(int argv, char **args) {
     
     // Extraido de https://www.elotrolado.net/hilo_no-archivos-en-un-directorio-lenguaje-c_1639761
     
   	string msg="";
    DIR *directorio;
    struct dirent *fichero;
    directorio = opendir(args[1]);
    if(directorio == NULL)
    {	
    	if(args[1]==NULL)
            directorio = opendir("c:/");
        else
        	cout<< "Error de direccion" <<endl;

    }
    while(fichero = readdir(directorio))
    {
        cout<< fichero->d_name <<'\n';
         //aqui haces lo que quieras con el fichero encontrado
         //en fichero->d_name tienes el nombre del fichero
         //cada iteracion de este bloque es por cada entrada en el directorio, sean directorios o ficheros
    }
    closedir(directorio);
      return 0;
     
    }
