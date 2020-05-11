#ifndef Integer__cpp
#define Integer__cpp
#include<string.h>
#include "DataType.cpp"
namespace matm
{
class Integer:public DataType
{
private:
char* value;

Integer(char*);
~Integer();
public :
char getTypeId();
char* toString();

};  //Integer class ends

Integer :: Integer(char* val)
{
this->value=new char[strlen(val)+1];
}
Integer::~Integer()
{
delete [] value;
}
char Integer :: getTypeId()
{
return (char) 0 ;
}
char* Integer:: toString()
{

return this->value;
}

}//namespace matm ends
#endif