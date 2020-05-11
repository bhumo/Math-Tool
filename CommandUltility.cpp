#ifndef CommandUltility__cpp
#define CommandUltility__cpp
#include "DataManager.cpp"
#include "CommandProcessor.cpp"
#include <forward_list>
using namespace std;
namespace matm
{
class CommandUltility
{
CommandUltility(){}
static forward_list<CommandProcessor*> commandProcessors;//declaring the static property
public:
static void registerCommand(CommandProcessor* command)
{
commandProcessors.push_front(command);
return;
}
static CommandProcessor* getCommandProcessor(char* commandLine)
{

CommandProcessor* commandProcessor;
for(auto commandProcessor:commandProcessors)
{
if(commandProcessor->canProcess(commandLine))
{

return commandProcessor;
}

}
return NULL;
}


};
forward_list<CommandProcessor*> CommandUltility::commandProcessors; //defining the static variable so that the memory is allocated.

}
#endif