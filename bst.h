
#ifndef __bst_h
#define __bst_h
#define TRUE 1
#define true 1
#define True 1
#define FALSE 0 
#define False 0 
#define false 0
#include<malloc.h>
#include<stdio.h>

namespace matm
{

typedef struct __$$__binary_search_tree_node
{
void *data;
struct __$$__binary_search_tree_node *left,*right;
int weight;
}BST_NODE;


typedef struct  __$$__binary_search_tree
{
struct __$$__binary_search_tree_node *root;
int (*comparator)(void*,void*); 
/*function pointer
Function pointer holds the address of the function.
Syntax->
ReturnType  (*functionPointerVariableName)(paramters);
*/
}BINARY_SEARCH_TREE;


typedef struct  __$$__binary_search_tree_iterator
{
BST_NODE *root;
char order_type;
}BINARY_SEARCH_TREE_ITERATOR;

typedef struct __$$__binary_search_tree_node_position
{
int pre_order_position;
int post_order_position;
int in_order_position;

}BINARY_SEARCH_TREE_NODE_POSITION;



BINARY_SEARCH_TREE * create_bst(int (*comparator)(void *,void *))
{
//this function will create bst and it'll return the root of the newly created bst;
struct __$$__binary_search_tree *bst= (struct __$$__binary_search_tree*)malloc(sizeof(struct __$$__binary_search_tree));
bst->comparator=comparator;
bst->root=NULL;
return bst;
}//create_bst() ends

int getWeight(BST_NODE *node)
{
if(node==NULL)return 0 ;
return node->weight;
}


BINARY_SEARCH_TREE_NODE_POSITION  insert_in_bst(BINARY_SEARCH_TREE *bst,void *data,bool *isAdded)
{

//BINARY_SEARCH_TREE signifies the root of the tree
//since,we're maintaing mutiple bst also and each tree will have different root node..
//void* is the address of the data is fed to the bst.
//bool* is required to accept the address of bool type 
//variable in which we can assign true or false in case of 
//successful insertion operation or due to any failure
//BINARY_SEARCH_TREE_NODE_POSITION  signifies
//that we will allocate the position of the node as per as different traversal 
//techniques and assign it's position of tree in various members of the structure.

//Create a node first
int inOrderPos,preOrderPos,postOrderPos=0;
int comparisionResult,cp,fcp;

inOrderPos=0;
preOrderPos=0;
*isAdded=false;
BST_NODE *ptr,*t1,*t2;
BST_NODE *newNode=(BST_NODE *)malloc(sizeof(struct __$$__binary_search_tree_node)*1);
newNode->left=NULL;
newNode->right=NULL;
newNode->data=data;
newNode->weight=0;

BINARY_SEARCH_TREE_NODE_POSITION bstNodePosition ;
bstNodePosition.in_order_position=-1;
bstNodePosition.post_order_position=-1;
bstNodePosition.pre_order_position=-1;
if(bst->root == NULL)
{
bst->root = newNode;
bstNodePosition.in_order_position=0;
bstNodePosition.post_order_position=0;
bstNodePosition.pre_order_position=0;
*isAdded=true;
return bstNodePosition;
}

//if control reaches here then the root is definetly present.

/*
let's traverse the tree while inserting itself....
in inorder traversal first we visit the left most node then root and lastly the right node.
since we are already maintaining the weight and weight of each node contains the number 
of childern plus it's children subtrees. 
So,we will calculate the position of the node in inorder traversal using weight and by applying
some math on it.
Let's assume an scenario where the newly inserted node is in the leftMost part of the leftSubTree
Then it's position is going to be zero definetly.
Let's assume another scenario where the newly inserted node is the right tree, then it's obvious
that whatever the position may be it's definetly greater than the sum of all the left child of the
grandparent(root for that new node) of the right tree. Since, the newly inserted node is not the root
(PS it can never be the root as it's a leaf node we don't have 
to worry about the left and right suntrees for the newly inserted node)
instead it's the right node therefore the position of the root is to be considered therfore we will increment 
the sum by one. Since, we have not counted the left node and only the left subtree 
therefore we need to increment sum by 1.
##post order traversal using weight##
Since, we will be finding the Post Order Position of newly inserted node then it can never be a parent node.
And if it's the root node we will simply return 0.
In post order Traversal first we traverse the left then right and lastly the root.
if the node is in the left side - do nothing
if node is in right side - 
  if parent->left exits 
     position = position + weightOfTheLeftSubTreeOfTheParent ;
##PRE-ORDER-TRAVERSAL##
pre order traversal 
root,left,right
if the node is insereted in left side
    preOrderPosition ++
if node is inserted in the right
   if parent->left exits
      preOrderPosition=preOrderPosition+parent->left->weight+2
   else
     preOrderPosition=preOrderPosition+1;
*/
t1=bst->root;
while(1)
{
comparisionResult=bst->comparator(t1->data,data);
if(comparisionResult==0)
{
//if(t1->left) inOrderPos=inOrderPos+t1->left->weight+1; //we have to check this.
return bstNodePosition;
//here the bstPosition will return a null value
//and we have not inserted the node in the bst therefore,to show that
//we have assigned false to the boolean variable.
}


if(comparisionResult>0)
{
preOrderPos++;
if(!t1->left)
{
t1->left=newNode;
*isAdded=true;

break;
}
else
{
t1=t1->left;
}
}
else
{
if(t1->left!=NULL)
{
inOrderPos=inOrderPos+t1->left->weight+2;
preOrderPos=preOrderPos+t1->left->weight+2;
postOrderPos=postOrderPos+t1->left->weight+1;
}
else
{
preOrderPos=+preOrderPos+1;
inOrderPos=inOrderPos+1;
}

if(!t1->right)
{
t1->right=newNode;
*isAdded=true;

break;
}
else
{
t1=t1->right;
}
}

}//while loop ends

//printf("insertion process is completed\n");
//if the control reaches here then it means definetly the node is inserted.
/*
now here's few things to consider:-
1.If i insert a new node in the tree then the weight of the other nodes in the path will become invalid.
*/
//we have to traverse the tree and assign the positions to the newly created node.
//inorder traversal


bstNodePosition.in_order_position = inOrderPos;
bstNodePosition.pre_order_position=preOrderPos;
bstNodePosition.post_order_position=postOrderPos;

//weight balancing by applying math using the current position to the newly inserted node position 
cp=inOrderPos;
t1=bst->root;
//printf("Weight of root %d left %d right %d",t1->weight,t1->left->weight,t1->right->weight);
while(cp!=0)
{
if(t1->left) fcp= cp - t1->left->weight -2;
else fcp = cp-1;
t1->weight++;
if(fcp>=0)
{
cp=fcp;
t1=t1->right;
}
else
{
t1=t1->left;
}
}
while(t1->left)
{
t1->weight++;
t1=t1->left;
}
//while ends
//printf("weight of root:%d ",bst->root->weight);
//if(bst->root->left!=NULL)printf("weight of left:%d ",bst->root->left->weight);
//if(bst->root->right!=NULL)printf("weight of right:%d ",bst->root->right->weight);
//for now to check if the program is working properly we will return the other as 0,0
*isAdded=true;
return bstNodePosition;
//if of isAdded ends
}//insert_in_bst () ends


void * remove_from_bst(BINARY_SEARCH_TREE *tree,void *data,bool *isRemoved,BINARY_SEARCH_TREE_NODE_POSITION *bstNodePosition)
{
BST_NODE *t1,*t2,*j;
void *removedData;
int comparisionResult,nodePos;
*isRemoved=false;
nodePos=0;
t1=tree->root;
if(t1==NULL)return NULL;
while(1)
{

if(t1 == NULL)break;
comparisionResult=tree->comparator(t1->data,data);
if(comparisionResult==0)
{
break;
}

t2=t1;


if(comparisionResult>0)
{
t1=t1->left;
printf("left");
}
else
{

if(t1->left) nodePos=nodePos+t1->left->weight+2;
else nodePos=nodePos+1;
t1=t1->right;

}

}//while ends
printf("removed ");

if(t1==NULL) 
{
printf("not found");
return NULL;
}

removedData=t1->data;
//delete operation on leaf node.
if(t1->left==NULL && t1->right==NULL) 
{
printf("rd %d",(int)t1->data);	
//here we are comparing the addresses stored in the pointer.
if(t2->left == t1)
{
t2->left == NULL;
*isRemoved = true;
}
else
{
printf("%d",(int)t2->data);
t2->right=NULL;

free(t1);
*isRemoved = true;
}
printf("leaf node ");
}//if of delete operation on leaf node ends
else
{//else 1 starts
//if control reaches here means the node is having a left or right subtree or both.
if(t1->left!=NULL && t1->right==NULL)
{

if(t2->left==t1)
{
t2->left=t1->left;
}
else
{
t2->right=t1->left;
}
*isRemoved = true;
}//the node which is to be deleted has only left subtree/child
else
{
//else 2 starts
if(t1->left==NULL && t1->right!=NULL)
{

if(t2->left == t1)
{
t2->left=t1->right;
}
else
{
t2->right=t1->right;
}
*isRemoved = true;
}//the node which is to be deleted has only right subtree/child
else
{
//else 3 starts
//if control reaches here then it means it has both left and right subtree/child

if(t2->left==t1) t2->left=t1->left;
else t2->right=t1->left;
t1->left=t1->right;
*isRemoved = true;

}//else 3 ends

}//else 2 ends

}//else 1 ends
free(t1);
printf("data removed");
//Now we have to adjust the weight
j=tree->root;
int currentPosition,rp,fcp;
currentPosition=0;
rp=nodePos;
while(currentPosition<rp)
{
if(j->left) fcp= currentPosition+j->left->weight+2;
else fcp=currentPosition+1;
j->weight--;
if(fcp<=rp)
{
currentPosition=fcp;
j=j->right;
}
else
{
j=j->left;
}

}

if(j!=NULL)
{
while(j->left!=NULL)
{
j->weight--;
j=j->left;
}
}
printf("function ends");
return removedData;
}//remove_from_bst() ends

void * find_in_bst(BINARY_SEARCH_TREE *tree,void *elementToFind,boolean* success,BINARY_SEARCH_TREE_NODE_POSITION *position)
{
void*  element;
if(success) *success=false;
int comparisionResult=0;



}


/*
void * remove_by_in_order_position_from_bst(BINARY_SEARCH_TREE *,int,boolean *);
void * remove_by_pre_order_position_from_bst(BINARY_SEARCH_TREE *,int,boolean *);
void * remove_by_post_order_position_from_bst(BINARY_SEARCH_TREE *,int,boolean *);
BINARY_SEARCH_TREE_ITERATOR * bst_forward_in_order_iterator(BINARY_SEARCH_TREE
*,int);
BINARY_SEARCH_TREE_ITERATOR *
bst_forward_pre_order_iterator(BINARY_SEARCH_TREE *,int);
BINARY_SEARCH_TREE_ITERATOR *
bst_forward_post_order_iterator(BINARY_SEARCH_TREE *,int);
BINARY_SEARCH_TREE_ITERATOR *
bst_forward_level_order_iterator(BINARY_SEARCH_TREE *,int);
BINARY_SEARCH_TREE_ITERATOR * bst_reverse_in_order_iterator(BINARY_SEARCH_TREE
*,int);
BINARY_SEARCH_TREE_ITERATOR * bst_reverse_pre_order_iterator(BINARY_SEARCH_TREE
*,int);
BINARY_SEARCH_TREE_ITERATOR *
bst_reverse_post_order_iterator(BINARY_SEARCH_TREE *,int);
BINARY_SEARCH_TREE_ITERATOR *
bst_reverse_level_order_iterator(BINARY_SEARCH_TREE *,int);
boolean bst_has_next(BINARY_SEARCH_TREE_ITERATOR *);
void * bst_next(BINARY_SEARCH_TREE_ITERATOR *);
void clear_bst(BINARY_SEARCH_TREE *);
int bst_size(BINARY_SEARCH_TREE *);
boolean contains(BINARY_SEARCH_TREE *,void
*,BINARY_SEARCH_TREE_NODE_POSITION *);
void * fetch_inorder(BINARY_SEARCH_TREE *,int,boolean *);
void * fetch_pre_order(BINARY_SEARCH_TREE *,int,boolean *);
void * fetch_post_order(BINARY_SEARCH_TREE *,int,boolean *);
void * free_bst(BINARY_SEARCH_TREE *);
*/

}//namespace matm ends



#endif