#ifndef EXITCommand__cpp
#define EXITCommand__cpp
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "..\CommandProcessor.cpp"
#include "..\DataManager.cpp"
using namespace std;
namespace matm
{
class EXITCommand : public CommandProcessor
{

public:
bool canProcess(char* commandLine)
{

while(*commandLine == ' ') *commandLine++;//here we are removing the right spaces. the point will point first non space character.
//strnicmp return 0 when the strings are equal
if(*commandLine=='\0')return false;
if(!(strnicmp(commandLine,"bye",3)))
{
commandLine = commandLine+3;
while(*commandLine==' ')commandLine++;
if(*commandLine=='\0') 
{

return true;
}
}
if((strnicmp(commandLine,"quit",4)==0)||(strnicmp(commandLine,"exit",4)==0))
{
commandLine=commandLine+4;
while(*commandLine==' ') commandLine++;
if(*commandLine == '\0')return true;
}

return false;
}//canProcess() ends

void process(DataManager* dataManager)
{
exit(0);
}
};
}
#endif