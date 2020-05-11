#include "bst.h"
#include<stdio.h>
#include <stdlib.h>

using namespace matm;

int comparator( void* root,void* data)
{
if((int)root>(int)data)return 1;
if((int)root<(int)data)return -1;
return 0;
}


int main()
{
BINARY_SEARCH_TREE *bst= create_bst(comparator);
bool isAdded=false;
printf("bst created\n");
BINARY_SEARCH_TREE_NODE_POSITION bstPos= insert_in_bst(bst,(void*)4,&isAdded);
printf("IN - %d ",bstPos.in_order_position);
printf("PRE -%d ",bstPos.pre_order_position);
printf("POST -%d ",bstPos.post_order_position);
printf("4 inserted\n");

isAdded=false;
bstPos= insert_in_bst(bst,(void*)3,&isAdded);
printf("IN - %d ",bstPos.in_order_position);
printf("PRE -%d ",bstPos.pre_order_position);
printf("POST -%d ",bstPos.post_order_position);
printf("3 inserted\n");

isAdded=false;
bstPos= insert_in_bst(bst,(void*)2,&isAdded);
printf("IN - %d ",bstPos.in_order_position);
printf("PRE -%d ",bstPos.pre_order_position);
printf("POST -%d ",bstPos.post_order_position);
printf("2 inserted\n");

isAdded=false;
bstPos= insert_in_bst(bst,(void*)1,&isAdded);
printf("IN - %d ",bstPos.in_order_position);
printf("PRE -%d ",bstPos.pre_order_position);
printf("POST -%d ",bstPos.post_order_position);
printf("1 inserted\n");

isAdded=false;
bstPos= insert_in_bst(bst,(void*)5,&isAdded);
printf("IN - %d ",bstPos.in_order_position);
printf("PRE -%d ",bstPos.pre_order_position);
printf("POST -%d ",bstPos.post_order_position);
printf("5 inserted\n");

isAdded=false;
int *data =(int*) remove_from_bst(bst,(void*)5,&isAdded,NULL);
if(isAdded==false) printf("not found");
else printf("removed");


return 0;
}