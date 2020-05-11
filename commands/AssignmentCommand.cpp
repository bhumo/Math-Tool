
#ifndef  AssignmentCommand_cpp
#define AssignmnetCommand_cpp
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include "..\TMUltility.cpp"
#include "..\CommandProcessor.cpp"
#include "..\DataManager.cpp"
using namespace matm;

class AssignmentCommand: public CommandProcessor
{
int indexOfEqualTo ;
char* commandLine;
public:


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
void assignInteger(char *variablePart , char *valuePart)
{
printf("variable part:(%s), value part: (%s)\n",variablePart,valuePart);
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
int isVariable(char *str)
{
char *s=str;
char *pin1,*pin2;
int k,i;
for(s;*s==' ';s++);
//first non space character
if(*s=='\0') return (int)(s-str); 
pin1=s;
pin2=s;
if(! ( (*s>=97 &&*s<=122)||(*s>=65 &&*s<=90)||(*s=='$')||(*s=='_') ) )
{
return (int)(s-str);
//error has ocured
}
s++;
//atleast one valid first non space character is there.
if(*s=='\0')return-1;
for(s;*s!='\0';s++)
{

if(*s==' ')
{
pin2=s;
s++;
while(s!='\0'&&*s==' ')s++;
if(*s=='\0') return-1;

return (int)(pin2-pin1);
}

if(!((*s>=97 &&*s<=122)||(*s>=65 && *s<=90)||(*s=='$')||(*s=='_')||(*s>=48 && *s<=57)))
{
return (int)(s-str);
}
}
pin2=s;
return -1;
}//isVariable ends

void process(DataManager *dataManager)
{
char *variablePart, *valuePart;
char *pin1,*pin2;
int k,i;
k=0;
char *ptr ;
variablePart=(char*)malloc(sizeof(char)*(this->indexOfEqualTo+1));
valuePart=(char*)malloc(sizeof(char)*(strlen(this->commandLine)-this->indexOfEqualTo+1));
strncpy(variablePart,this->commandLine,this->indexOfEqualTo);
variablePart[indexOfEqualTo]='\0';
strcpy(valuePart,this->commandLine+this->indexOfEqualTo+1);
k=isVariable(variablePart);
if(k!=-1)
{
printf("%s\n",this->commandLine);
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
printf("variable validate\n");
//variable part is valid
//now we have to validate value part
ptr=valuePart;
pin1=valuePart;
while(*ptr!='\0' && *ptr==' ')*ptr++;
//ptr points to first non-space character
if(*ptr=='\0')
{
//this means there's no value part therfore print error
printf("%s\n",commandLine);
k=ptr-valuePart+indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol");
free(variablePart);
free(valuePart);
return;
}
//if control reaches here then it means there's some value part.
pin1=ptr;
if(*ptr=='\'' || *ptr=='\"')//check for single quote or double quote
{
char quote= *ptr; //the ascii quote which the ptr is pointing is stored in the 

ptr++;
while(*ptr && *ptr!= quote)ptr++;
if(*ptr == '\0')
{
printf("%s\n",this->commandLine);
k =ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
while(*ptr)
{
if(*ptr==quote && *(ptr-1)!=92)
{
ptr++;
while(*ptr && *ptr==quote)ptr++;

ptr++;
while(*ptr && *ptr==' ')ptr++;
if(*ptr!='\0')
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol");
free(variablePart);
free(valuePart);
return;
}
}
ptr++;
}
//if it comes here then it's a string
Ultility::allTrim(variablePart,' ');
Ultility::allTrim(valuePart,' ');
assignString(variablePart,valuePart);


}//if for single or double quote ends.
//if control reaches here that means there's no single and double quote i.e, not a string.

if(*ptr == 'T' || *ptr == 't'  || *ptr == 'f' ||*ptr == 'F')
{
//check for boolean constant
bool booleanConstant = false;
bool isbool=false;
ptr++;
//we will check if it's a boolean constant or else it could be a variable.
if(*ptr == ' ')
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+ this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol");
free(variablePart);
free(valuePart);
return;
}
if(*ptr && *ptr!= ' ')
{
if((strncmp(ptr,"rue",3)==0)||(strncmp(ptr,"RUE",3)==0))
{
booleanConstant = true;
isbool =true;
}
else
{
if((strncmp (ptr,"alse",4)==0)|| (strncmp(ptr,"ALSE",4)==0))
{
booleanConstant = false;
isbool =true;
}
else
{
 isbool = false;
}
}
}//if condition for checking the boolean constant after getting T,t,F,f
if(isbool == true)
{
Ultility::allTrim(variablePart, ' ');
assignBoolean(variablePart,booleanConstant);
}
}//boolean constant check ends
if(*ptr=='N'||*ptr=='n')
{
ptr++;
if(*ptr==' ')
{
while(*ptr && *ptr== ' ')ptr++;
if(*ptr != '\0')
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol");
free(variablePart);
free(valuePart);
return;
//error code
}
}
if(*ptr && *ptr!= ' ')
{
if((strncmp(ptr,"ULL",3)==0)||(strncmp(ptr,"ull",3)==0))
{
Ultility::allTrim(variablePart,' ');
assignNull(variablePart);
}
}
}//if control reaches here then, the value part neither contains string,boolean constant,null constant.
//that means now we have to check for only numeric constant and the variable part.
//for numerical constant we have numbers starting with 0 is octal , only 0 is integer, 0b is binary, ox is hexadecimal
//if it's octal,binary or hexa value then it can not contain + or - sign.
//with decimal we will allow positive and negative values and also for integers.
if(*ptr == '+'||*ptr == '-' || *ptr == '.' || *ptr == '.' || *ptr =='0'|| (*ptr>=48 && *ptr<=57)) //if for numeric constant condition starts
{
int sign=0;
//if value of sign is 0 means no sign is specified
//if value of sign is 1 means + is specified
//if value of sign is -1 meand - is specified
if(*ptr == '+')
{
sign =1;
ptr++;
}
if(*ptr == '-')
{
sign=-1;
ptr++;
}
if(*ptr == '0')//starts with 0 part starts here
{
ptr++;
if(*ptr==' '||*ptr=='\0')
{
pin2=ptr;
//if there's space in secound block,
//then there could be more space and finally terminated without any other character in middle, 
//then it's a zero or if on the secound block there's '/0' then assignIntger 0 to the variablePart.

while(*ptr!='\0' && *ptr==' ')ptr++;

if(*ptr=='\0')
{
*pin2='\0';
Ultility::allTrim(variablePart,' ');
assignInteger(variablePart,(char)0);//assign 0 as integer.
}
else
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;+i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
}//if for getting space or '\0' in secound block ends.

//check if there's no dot and no sign only then we will allow 
if(*ptr!='.' && sign!=0)//means there's no dot and there's a sign specified (i.e the value of sign is not 1 or -1)
{
//error code
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
if(*ptr=='b')//binary part starts
{
ptr++;
pin1 = ptr;
if(*ptr=='\0' || *ptr ==' ')
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
while(*ptr)
{
if(*ptr == ' ')
{
pin2=ptr;
ptr++;
while(*ptr && *ptr==' ')ptr++;

if(*ptr == '\0')
{
*pin2 = '\0';
Ultility::allTrim(variablePart,' ');
assignInteger(variablePart,Ultility::binaryToInteger(pin1));
//do some processing to assign the binary after triming
return;
}
else
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
}
if(!(*ptr== '1' || *ptr == '0' ))
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}

ptr++;
}
pin2=ptr;//it points to the block where /0 is placed
Ultility::allTrim(variablePart,' ');
assignInteger(variablePart,Ultility::binaryToInteger(pin1));
return;
//if control reaches here that means the value part is correct
//we can assign the binary value after some processing
}//binary part ends

if(*ptr == 'x')//hexa decimal part starts
{
ptr++;
pin1=ptr;
if(*ptr=='\0' || *ptr==' ')
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
//if control reches here then definetly there is a non space character.
while(*ptr)
{
if(*ptr == ' ')
{
ptr++;
while(*ptr && *ptr==' ')ptr++;
if(*ptr=='\0')
{
Ultility::allTrim(variablePart,' ');
assignInteger(variablePart,Ultility::hexaToInteger(pin1));
return;
}
else
{
//error code
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
return;
}
}
if(!((*ptr<=48 && *ptr>=57)||(*ptr>=65 && *ptr<=70)||(*ptr>=97 && *ptr<=102)))
{
//error code
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
return;
}
ptr++;
}
}//hexa decimal if ends.
//if it's not integer,binary,hexa then it must be octal or decimal.
//first let's check for decimal
if(*ptr=='.')
{
if(sign!=0)pin1=ptr-2;
else pin1 =ptr-1;
//means that the if it contains a sign then pin1 will point to the specfied sign
//if no sign is there then it will also consider the first digit(in this case,0).
ptr++;
if(*ptr=='\0' || *ptr==' ')
{
while(*ptr && *ptr==' ')ptr++;
if(*ptr=='\0')
{
Ultility::allTrim(variablePart,' ');

assignRealNumber(variablePart,(char*)"0.0");
return;
}
else
{
//error code
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
}
while(*ptr)
{
if(*ptr==' ')
{
pin2=ptr;
ptr++;
while(*ptr && *ptr== ' ')ptr++;
if(*ptr!='\0')
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
else
{
*pin2='\0';
Ultility::allTrim(variablePart,' ');
assignRealNumber(variablePart,Ultility::realToInteger(pin1));
return;
}
}
if(!(*ptr>=48 && *ptr<=57))
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
ptr++;
}
pin2=ptr;
Ultility::allTrim(variablePart,' ');
assignRealNumber(variablePart,Ultility::realToInteger(pin1));
return;
}

//now we only have to check for octal

while(*ptr)
{
if(!(*ptr>=48 && *ptr<=57))
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ octal value must be in range(0-7)\n");
free(variablePart);
free(valuePart);
return;
}
if(*ptr==' ')
{
pin2=ptr;
ptr++;
while(*ptr && *ptr== ' ')ptr++;
if(*ptr=='\0')
{
*pin2='\0';
Ultility::allTrim(variablePart,' ');
assignInteger(variablePart,Ultility::octalToInteger(pin1));
return;
}
else
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ octal value must be in range(0-7)\n");
free(variablePart);
free(valuePart);
return;
}

}
*ptr++;
}
}//if for starts with 0 ends

if(*ptr == '.')//starts with dot part (i.e, decimal)
{
ptr++;
if(*ptr==' ' || *ptr =='\0')
{
//error code
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ value expected after .\n");
free(variablePart);
free(valuePart);
return;
}

if(sign==0)
{
pin1=ptr-1;
}
else
{
pin1=ptr-2;
}

while(*ptr)
{
if(!(*ptr<=48 && *ptr>=57))
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol");
free(variablePart);
free(valuePart);
return;
}
if(*ptr == ' ')
{
pin2=ptr;
while(*ptr && *ptr== ' ')ptr++;
if(*ptr=='\0')
{
*pin2='\0';
Ultility::allTrim(variablePart,' ');
assignRealNumber(variablePart,Ultility::realToInteger(pin1));
}
else
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ octal value must be in range(0-7)\n");
free(variablePart);
free(valuePart);
return;
}
}//if of space ends
ptr++;
}//while ends
pin2=ptr;
Ultility::allTrim(variablePart, ' ');
assignRealNumber(variablePart,Ultility::realToInteger(pin1));
}//start with . part ends

if(*ptr >=48 && *ptr<=57) //starts with digit
{
if(sign==0)pin1=ptr;
else pin1=ptr-2;
ptr++;
bool foundDot =false;
while(*ptr && *ptr!=' ')
{
if(*ptr== '.')
{
ptr++;
if(foundDot)
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
else
{
foundDot=true;
}
}//if for dot found ends.
if(*ptr<48 || *ptr>57)
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
ptr++;
}//while ends;

if(*ptr=='\0')
{
if(foundDot==false)
{
Ultility::allTrim(variablePart,' ');
assignInteger(variablePart,pin1);
return;
}
Ultility::allTrim(variablePart,' ');
assignRealNumber(variablePart,Ultility::realToInteger(pin1));
return;
}
//when the control will come out of the while loop
//either the string is terminated or the space is found
//we have already checked for terminated string
//so now we only have to check if there  exists any other character other than '\0' in the string.
pin2=ptr;
while(*ptr && *ptr==' ')ptr++;
if(*ptr!='\0')
{
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ unexpected symbol\n");
free(variablePart);
free(valuePart);
return;
}
*pin2='\0';
if(foundDot == false)
{
Ultility::allTrim(variablePart,' ');
assignInteger(variablePart,pin1);
return;
}
Ultility::allTrim(variablePart,' ');
assignRealNumber(variablePart,Ultility::realToInteger(pin1));
return;
}//starts with digit ends
}//condition for numeric constant ends
//if we have reached here then for sure the right part is not a constant.
//that means it has to be variable.
//we have to first check if it's a valid varible name.
//if it has a valid variable name then we have to check if it's already defined or not (by checking t in map)
//if the variable is not defined then we will print the error.
k=isVariable(valuePart);
if(k!=-1)
{
//error code
printf("%s\n",this->commandLine);
k=ptr-valuePart+this->indexOfEqualTo;
for(i=0;i<k;i++)printf(" ");
printf("^ invalid symbol in identifier\n");
return;
}
//if control reaches here that means we have a valid variable name
//now we only have to check if the variable in value part is defined or not.
Ultility::allTrim(variablePart,' ');
Ultility::allTrim(valuePart, ' ');
assignValue(variablePart,valuePart);
return;
}//process() ends

 bool canProcess(char *commandLine)
{
this->commandLine = commandLine;
this->indexOfEqualTo=-1;
char *s=commandLine;
int base=(int)s;//it will contain the base address
for(s;*s ==' ';s++);

if(*s == '\0') return false;
//first non space character

for(s;*s!='\0';s++)
{

if(*s=='\'') 
{

s++;
while(*s!='\'' && *s!='\0')s++;
if(*s=='\0')break;
continue;
}
//if you find double quote
if(*s=='\"')
{

s++;
while(*s!='\"' && *s!='\0')s++;

if(*s=='\0')return false;
continue;
}

if(*s=='=') 
{

if(*s=='=' && *(s+1)=='=')break;
this->indexOfEqualTo=(int)(s-commandLine);
printf("Index of = : %d\n",this->indexOfEqualTo);
return true;
}
}
//for loop ends means there's no equal to sign.
return false;
}


};

#endif