
#ifndef CommandProcessor__cpp
#define CommandProcessor__cpp
#include "DataManager.cpp"
#include<iostream>
using namespace std;
namespace matm
{
class CommandProcessor
{

public:
virtual void process(DataManager *dataManager)=0;
virtual bool canProcess(char *commandLine)=0;

};
}
#endif