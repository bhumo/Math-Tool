#ifndef String__cpp
#define String__cpp
#include "DataType.cpp"
#include<string.h>
namespace matm
{

class String : public DataType
{
private:
char * val;
public :
String(char *);
~String();
char getTypeId();
char* toString();
};
String::String(char *val)
{
this->val = new char[strlen(val)+1];
}
String::~String()
{
delete[] val;
}

char String::getTypeId()
{
return (char)1;
}

char* String::toString()
{
return val;
}
}
#endif