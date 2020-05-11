#include "DataManager.cpp"
#include "types/DataType.cpp"
#include "CommandProcessor.cpp"
#include "CommandRegistrar.cpp"
#include "CommandUltility.cpp"
#include<iostream>
#include<string.h>
#include "mat.h"
#include "TMUltility.cpp"
using namespace matm;
int main()
{
DataManager* dataManager= new DataManager();
CommandRegistrar::registerCommands();
char commandLine [1002];
char promt [5] = {"matm"};
while(True)
{

printf("%s>",promt);
fgets(commandLine,1001,stdin);
fflush(stdin);
commandLine[strlen(commandLine)-1]='\0';
CommandProcessor* commandProcessor=CommandUltility::getCommandProcessor(commandLine);
if(commandProcessor == NULL)
{
printf("Invalid command\\operation. Press ? for help\n");
continue;
}
commandProcessor->process(dataManager);
}
printf("Good bye");
return 0;
}


