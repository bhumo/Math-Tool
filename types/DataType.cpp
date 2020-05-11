#ifndef DataType__cpp
#define DataType__cpp

namespace matm
{
class DataType
{
/*
0-Integer
1-String
2-RealNumber
3-Boolean

*/
public:
virtual char getTypeId()=0;
virtual char* toString()=0;;

};

}

#endif