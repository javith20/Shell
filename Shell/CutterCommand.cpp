#include "CutterCommand.h"

CutterCommand::CutterCommand()
{
    this->userStr = "javith";
    this->groupStr = "javi";
    this->mainRouteStr = "C:/";

}
CutterCommand::~CutterCommand(){}
void CutterCommand::cutCommandStr(string commandStr)
{
    this->userStr="";
    this->programStr="";
    this->groupStr ="";
    this->listRouteStr.vaciar();
    this->listParametersStr.vaciar();
    commandStr = cutLastCommand(commandStr);
    int i=0;
    commandStr+=';';
    while(commandStr[i]!='@')
    {
        this->userStr+=commandStr[i];
        i++;
    }
    i++;
    while(commandStr[i]!=' ')
    {
        this->groupStr+=commandStr[i];
        i++;
    }
    i++;
    while(commandStr[i]!=';')
    {
        i++;
        string subStr="";
        while(commandStr[i] !=' ' && commandStr[i]!=';')
        {
            subStr+=commandStr[i];
            i++;
        }
        this->listParametersStr.insertarFinal(subStr);
    }

}
void CutterCommand::OrganizeCommandData()
{
    listParametersStr.EliminarPos(0);
    listParametersStr.EliminarPos(0);
    this->programStr = listParametersStr.getCabeza()->getElemento();
    for(int index = listParametersStr.getTam()-1 ; index > 0;index--)
    {
        if(listParametersStr.getPos(index)->getElemento()[0]=='/')
        {
            this->listRouteStr.insertarFinal(this->mainRouteStr+listParametersStr.getPos(index)->getElemento());
            this->listParametersStr.EliminarPos(index);
        }
    }
}
string CutterCommand::routeGenerate(string routeStr)
{
    if(ls.isDir(routeStr) || ls.isFile(routeStr))
    {
       return routeStr;
    }
    else{
        routeStr = this->mainRouteStr +routeStr;
        if(ls.isDir(routeStr) || ls.isFile(routeStr))
            return  routeStr;
        else{
         return("0");
        }
    }
}
string CutterCommand::cutLastCommand(string completeStr)
{   string invlastCommand;
    string lastCommand;
    int i = completeStr.length()-1;
    while(completeStr[i]!='\n' && i!=-1)
    {
        invlastCommand+=completeStr[i];
        i--;
    }
    for(i=invlastCommand.length()-1; i!=-1;i--)
        lastCommand+=invlastCommand[i];
    this->listHistoryStr.insertarFinal(lastCommand);
    return lastCommand;
}
string CutterCommand::selectCommand()
{
    this->OrganizeCommandData();
    string str;
    ListaEnlazada<string> listOut;
    listOut.insertarCabeza("Comando no encontrado");
    if(programStr == "ls")
    {

        if(this->listRouteStr.getCabeza())
        {
            listOut=this->ls.getFiles(this->listRouteStr.getPos(0)->getElemento());
        }
        else
        {
            listOut=this->ls.getFiles(this->mainRouteStr);
        }
    }
    if(programStr == "mkdir")
    {
        if(this->listRouteStr.getCabeza())
            listOut=this->mkdir.createDir(this->listRouteStr.getPos(0)->getElemento());
        else
            listOut=this->mkdir.createDir(this->mainRouteStr);
    }
    if(programStr == "rm")
    {
        string routeStr = routeGenerate ( this->getListParameters().getPos(1)->getElemento());
        if(routeStr !="0" )
        {
            cout<< routeStr << endl;
                if(ls.isFile(routeStr)==0)
                listOut=this->rm.removeDir(routeStr);
                else
                listOut= this->rm.removeFile(routeStr);
        }


    }
    if(programStr == "clear")
    {
        listOut.insertarFinal("clear");
    }
    if(programStr == "exit")
    {
        listOut.insertarFinal("exit");
    }
    if(programStr == "cd")
    {
        listOut.EliminarPos(0);
        if(getListParameters().getPos(1))
        {
            string routeStr = routeGenerate ( this->getListParameters().getPos(1)->getElemento());
            if(routeStr !="0")
                this->mainRouteStr = routeStr;
            else
                listOut.insertarFinal("Error de ruta");
        }else{
            this->mainRouteStr = "C:/";

        }
    }
    if(programStr == "cp"){
        listOut.EliminarPos(0);
        string routeCopyStr = ( this->getListParameters().getPos(1)->getElemento());
        string routeFateStr =  ( this->getListParameters().getPos(2)->getElemento());
        cout << routeCopyStr << endl;
        cout << routeFateStr << endl;

        cp.copyFile(routeCopyStr,routeFateStr);


    }
    if(programStr == "date")
    {
        listOut=date.getDateAndTime();
    }
    if(programStr == "Editor")
    {
        file.presentaMenuGeneral();
    }
    for(int i=0;listOut.getTam()>i;i++)
        str+=listOut.getPos(i)->getElemento()+"\n";
    return str;
}

string CutterCommand::getProgramStr()
{
    return this->programStr;
}
string CutterCommand::getRouteStr()
{
    return this->mainRouteStr;
}
string CutterCommand::getUserStr()
{
    return this->userStr;
}
string CutterCommand::getGroupStr()
{
    return this->groupStr;
}
ListaEnlazada<string> CutterCommand::getListParameters()
{
    return this->listParametersStr;
}
ListaEnlazada <string> CutterCommand::getHistoryStr()
{
    return this->listHistoryStr;
}
string CutterCommand::getCompleteDataShell()
{
    return userStr+"@"+groupStr+" "+mainRouteStr+" $ ";
}
