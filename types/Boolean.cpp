#ifndef Boolean__cpp
#define Boolean__cpp
#include "DataType.cpp"
#include <string.h>
namespace matm
{
class Boolean:public DataType
{
private:
char *val;
Boolean(char*);
~Boolean();
public:
char getTypeId();
char * toString();

};
Boolean::Boolean(char *val)
{
this->val = new char[strlen(val)+1];
}

Boolean::~Boolean()
{
delete [] val;
}

char Boolean::getTypeId()
{
return (char)3;
}

char * Boolean::toString()
{
return this->val;
}
}
#endif