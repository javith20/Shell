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
    if(programStr =="ls")
    {
        if(this->listRouteStr.getCabeza())
            listOut=this->ls.getFiles(this->listRouteStr.getPos(0)->getElemento());
        else
            listOut=this->ls.getFiles(this->mainRouteStr);
    }
    if(programStr =="mkdir")
    {
        if(this->listRouteStr.getCabeza())
            listOut=this->mkdir.createDir(this->listRouteStr.getPos(0)->getElemento());
        else
            listOut=this->mkdir.createDir(this->mainRouteStr);
    }
    if(programStr =="rm")
    {
        if(this->listRouteStr.getCabeza())
            listOut=this->rm.removeDir(this->listRouteStr.getPos(0)->getElemento());
        else
            listOut=this->rm.removeDir(this->mainRouteStr);
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
        string routeStr = this->getListParameters().getPos(1)->getElemento();
            if(routeStr[1]==':')
            {
                if(routeStr[2]=='/')
                {
                    this->mainRouteStr = routeStr;
                }else{
                    this->mainRouteStr +=routeStr;
                }
                }else{
                    this->mainRouteStr +=routeStr;

            }
    }
    if(programStr == "cp"){
        cp.copyFile("C:/");
    }
    if(programStr == "date")
    {
        listOut=date.getDateAndTime();
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