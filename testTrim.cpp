#include<string.h>
#include "TMUltility.cpp"
#include<stdio.h>
#include<iostream>

int main()
{

char a [120]={"     God     is    greart \"   god is   great    \"  \"  hello    \"    god is cool   "};
char b[20]={"    a     =   10  "};
char c[50]={"    b   =     \"God is great\"        "};

printf("(%s)\n",a);
Ultility::allTrim(a,' ');
printf("(%s)\n",a);
printf("(%s)\n",b);
Ultility::trimExpression(b,' ');
printf("(%s)\n",b);
printf("(%s)\n",c);
Ultility::trimExpression(c,' ');
printf("(%s)\n",c);
return 0;
}
