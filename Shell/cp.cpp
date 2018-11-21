#include "cp.h"

CpCommand::CpCommand()
{

}
ListaEnlazada<string> CpCommand::copyFile(string rutaInicio, string rutaFin)
{
    ListaEnlazada<string> listOut;

    unsigned int c;
    FILE *f1 = fopen(rutaInicio.c_str(), "rb");
    FILE *f2 = fopen(rutaFin.c_str(), "wb");

    if(f1 == NULL || f2 == NULL){
        listOut.insertarCabeza("¡El archivo de origen o la ruta de destino son erroneas!");
        return listOut;
    }

    while(!feof(f1)){
        c = getc(f1);
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);


    listOut.insertarCabeza("¡Copiado exitoso!");
    return listOut;
}
