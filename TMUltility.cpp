#ifndef  TMUltility__cpp
#define TMUltility__cpp
#include<stdio.h>
#include<string.h>
#include "commandProcessor.cpp"
using namespace matm;
class Ultility
{
Ultility(){} 
public:
 static void allTrim(char *str,char trimchar);
 static void trimExpression(char* str,char trimchar);
 static int isAssignment(char *str);
 static char* binaryToInteger(char * valuePart);
 static char* realToInteger(char *valuePart);
 static char* hexaToInteger(char *valuePart);
 static char* octalToInteger(char *valuePart);
 static int stringToInteger(char *valuePart);

};

void Ultility:: allTrim(char *str,char trimchar)
{
char temp [strlen(str)];
char * k =temp;
char *p=str;
while(*p ==trimchar) p++;
while(*p!='\0')
{

if(*p ==trimchar)
{
*k=' ';
k++;
while(*p ==trimchar)p++;
continue;
}
if(*p == '"')
{
*k='"';
k++;
p++;
while(*p && *p != '"')
{
*k=*p;
k++;
p++;
}
if(*p == ' ')
{
*k='"';
k++;
p++;
}
else
{
*k=*p;
k++;
p++;
}
continue;
}
*k=*p;
k++;
p++;

}

if (k>temp && *(k-1)==' ')k--;
*k='\0';
strcpy(str,temp);
}


void Ultility:: trimExpression(char*str,char trimchar)
{
char temp [strlen(str)];
char *k,*p;
k=temp;
p=str;
while(*p ==trimchar) p++;
while(*p!='\0')
{

if(*p ==trimchar)
{

while(*p ==trimchar)p++;
continue;
}
if(*p == '"')
{
*k='"';
k++;
p++;
while(*p && *p != '"')
{
*k=*p;
k++;
p++;
}
if(*p == ' ')
{
*k='"';
k++;
p++;
}
else
{
*k=*p;
k++;
p++;
}
continue;
}
*k=*p;
k++;
p++;

}

if (k>temp && *(k-1)==' ')k--;
*k='\0';
strcpy(str,temp);

}


int Ultility::isAssignment(char* str)
{
char*p=str;
int index,count;
index=0;
count=0;
while(*p)
{
if (*p == '=')
{
count= count+1;
}
index++;
p++;
}

if (count <1 || count >1)
{

return -1;
}
else
{
return index;
}

}//end of isAssignmnet() 


char * Ultility::binaryToInteger(char *valuePart)
{
return (char)0;
}//binaryToInteger() ends
 

char * Ultility::realToInteger(char *valuePart)
{
return (char* )"0.0";
}//realToInteger() ends

char * Ultility::hexaToInteger(char *valuePart)
{
return (char) 0;
}//hexaToInteger() ends

char * Ultility::octalToInteger(char *valuePart)
{
return (char) 0;
}//octalToInteger() ends

int Ultility::stringToInteger(char *valuePart)
{

return 0;
}//stringToInteger ends.



#endif