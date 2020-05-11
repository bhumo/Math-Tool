#ifndef RealNumber__cpp
#define RealNumber__cpp
#include<string.h>
namespace matm
{
class RealNumber : public DataType
{
private :
char * val;
RealNumber(char * );
~RealNumber();
public :
char getTypeId();
char * toString();


};
RealNumber::RealNumber(char *val)
{
this->val = new char[strlen(val)+1];

}

RealNumber::~RealNumber()
{
delete[] val;
}

char RealNumber::getTypeId()
{
return (char)2;
}
char * RealNumber::toString()
{
return this->val;
}
}
#endif