#include "cp.h"

CpCommand::CpCommand()
{

}
ListaEnlazada<string> CpCommand::copyFile(string ruta)
{
    ListaEnlazada<string> listOut;
    cout << "Entro copiar" << endl;

        unsigned int c;
        FILE *f1 = fopen("C:/1.exe", "rb");
        FILE *f2 = fopen("D:/", "wb");

        if(f1 == NULL || f2 == NULL){
              printf("El archivo de origen o la ruta de destino son erroneas");
              exit(EXIT_FAILURE);
        }

        while(!feof(f1)){
            c = getc(f1);
            fputc(c, f2);
        }
        fclose(f1);
        fclose(f2);



    return listOut;
}
