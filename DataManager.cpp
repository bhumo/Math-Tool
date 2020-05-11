#ifndef DataManager__cpp
#define DataManager__cpp
#include<map>
#include<stdio.h>
# include "types/DataType.cpp"
#include "types/Integer.cpp"
#include "types/String.cpp"
#include  "types/Boolean.cpp"
#include "types/RealNumber.cpp"
namespace matm
{
class DataManager
{
private:
std::map<char *,DataType *> IntegerDataStructure;
std::map<char *,DataType *> StringDataStructure;
public:

void assignInteger(char *variablePart , char *valuePart)
{
//the valuePart is definetly a integer
//we have used string because we want to be able to assign large values alse
//here we'll maintain a map 
//we want to make a pool so that we don't allocate unnecessary memory for same value.
//for now let's create a map 
//if the value already exsits in the map then we will assign that value to that variable
//if we find the key with the specified value then we will assisgn the address of that object to the variable.


printf("variable part:(%s), value part: (%s)\n",variablePart,valuePart);

return;
}

void assignString(char *variablePart,char *valuePart)
{

//some processing

printf("Variable: (%s), Value:%s",variablePart,valuePart);
printf("String assigned\n");
return;
}


void assignBoolean(char* variablePart , bool valuePart)
{
printf("Variable: (%s), Value:%d\n",variablePart,valuePart);
printf("boolean value assigned\n");
return;
}

void assignNull(char* variablePart)
{
printf("variable part (%s), is assigned null\n",variablePart);
return;
}

void assignRealNumber(char *variablePart, char *valuePart)
{
printf("Variable: (%s), Value(%f)\n",variablePart,valuePart);
return;
}


void assignValue(char* variablePart,char *valuePart)
{
//here we will check if the variable in valuePart is defined or not.
//if defined then, we will assign it's value to the variblePart.
printf("Variable: (%s), Value(%s)",variablePart,valuePart);

return;
}
};
}
#endif