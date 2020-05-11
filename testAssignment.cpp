#include<string.h>
#include<stdio.h>
#include "TMUltility.cpp"
int main()
{
int index=0;
char a[30]={"  a    = =  10  "};


printf(a);
index=Ultility::isAssignment(a);
if(index==-1)
{
printf("Not an assignment\n");

}
else
{
printf("assignment operation\n");
printf("Index:%d\n",index);
}
return 0;
}