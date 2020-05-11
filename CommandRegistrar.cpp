#ifndef CommandRegistrar__cpp
#define CommandRegistrar__cpp
#include "CommandUltility.cpp"
#include "CommandProcessor.cpp"
#include "commands/commands.h" //including the header file from the commands folder
#include<iostream>
namespace matm
{
class CommandRegistrar
{
CommandRegistrat(){}
public:
static void registerCommands()
{
CommandUltility::registerCommand(new EXITCommand());
CommandUltility::registerCommand(new AssignmentCommand());
}


};

}
#endif