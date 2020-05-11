#include "../AssignmentCommand.cpp"
#include<iostream>
using namespace matm;
int main()
{
bool canpro=false;
char commandLine[1000];
fgets(commandLine,1000,stdin);
fflush(stdin);
commandLine[strlen(commandLine)-1]='\0';
AssignmentCommand* as = new AssignmentCommand();
DataManager* ds;
fflush(stdin);
canpro=as->canProcess(commandLine);
if(canpro==true)
{
as->process(ds);
}
cout<<canpro;
return 0;
}
