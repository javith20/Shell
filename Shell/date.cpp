#include "date.h"

dateCommand::dateCommand()
{


}
ListaEnlazada<string> dateCommand::getTime()
{
    ListaEnlazada<string> time;
    time.insertarFinal( to_string(ltm->tm_hour)+" : "+ to_string(ltm->tm_min ));
    return time;
}
ListaEnlazada<string> dateCommand::getDate()
{
    ListaEnlazada<string> time;
    time.insertarFinal( to_string(ltm->tm_mday)+"/"+to_string(ltm->tm_mon+1)+"/"+ to_string(ltm->tm_year ));
    return time;
}
ListaEnlazada<string> dateCommand::getDateAndTime()
{
    ListaEnlazada<string> time;
    time.insertarFinal(getTime().getCabeza()->getElemento());
    time.insertarFinal(getDate().getCabeza()->getElemento());

    return time;
}
