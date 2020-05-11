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


BINARY_SEARCH_TREE_NODE_POSITION*  insert_in_bst(BINARY_SEARCH_TREE *bst,void *data,bool *isAdded)
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


BINARY_SEARCH_TREE_NODE_POSITION *bstNodePosition=NULL;
//Create a node first
BST_NODE *ptr,*t1,*t2;
BST_NODE *newNode=(BST_NODE *)malloc(sizeof(struct __$$__binary_search_tree_node)*1);
newNode->left=NULL;
newNode->right=NULL;
newNode->data=data;
newNode->weight=0;
bstNodePosition=(BINARY_SEARCH_TREE_NODE_POSITION *)malloc(sizeof(BINARY_SEARCH_TREE_NODE_POSITION)*1);
bstNodePosition->in_order_position=-1;
bstNodePosition->post_order_position=-1;
bstNodePosition->pre_order_position=-1;
if(bst->root == NULL)
{
bst->root = newNode;
bstNodePosition->in_order_position=0;
bstNodePosition->post_order_position=0;
bstNodePosition->pre_order_position=0;
*isAdded=true;
return bstNodePosition;
}
else
{

//if control reaches here then the root is definetly present.
if(bst->comparator(bst->root->data,newNode->data)>0)
{
//bst->root->data is greater than newNode->data
//this signifies that the data that is to inserted is smaller than the data of root
//hence it has to be inserted in the left subtree of the node.
//check if there's a left child of root or not

ptr=bst->root;
t1=ptr;
t2=NULL;
while(t1!=NULL)
{

t2=t1;
if(bst->comparator(t1->data,newNode->data)>0)
{
t1=t1->left;
continue;
}
if(bst->comparator(t1->data,newNode->data)<0)
{
t1=t1->right;
continue;
}
if(bst->comparator(t1->data,newNode->data)==0)
{
*isAdded=false;
return bstNodePosition;

//here the bstPosition will return a null value
//and we have not inserted the node in the bst therefore,to show that
//we have assigned false to the boolean variable.
}
}//while loop ends
if(bst->comparator(t2->data,newNode->data)>0)
{
t2->left=newNode;
*isAdded = true;
}
else
{
t2->right=newNode;
*isAdded=true;
}
//printf(" inserted in left side ");
}//if of left subtree ends
if(bst->comparator(bst->root->data,newNode->data)<0)
{

//bst->root->data is smaller than newNode->data
//this signifies that the data that is to inserted is greater than the data of root
//hence it has to be inserted in the right subtree of the node.

t1=bst->root;
t2=NULL;
while(t1!=NULL)
{

t2=t1;
if(bst->comparator(t1->data,newNode->data)>0)
{
t1=t1->left;
continue;
}

if(bst->comparator(t1->data,newNode->data)<0)
{

t1=t1->right;
continue;
}
if(bst->comparator(t1->data,newNode->data)==0)
{

*isAdded=false;
return bstNodePosition;//here the bstPosition will return a null value
//and we have not inserted the node in the bst therefore,to show that
//we have assigned false to the boolean variable.
}
}

if(bst->comparator(t2->data,newNode->data)>0)
{
t2->left=newNode;
*isAdded=true;
}
else
{
t2->right=newNode;
*isAdded = true;
}
//printf(" inserted in right side ");
}//if of right tree ends
if(bst->comparator(bst->root->data,newNode->data)==0)
{
//equal to 0 means both the values are equal
*isAdded=false;
return bstNodePosition;
//here the bstPosition will return a null value
//and we have not inserted the node in the bst therefore,to show that
//we have assigned false to the boolean variable.
}
}//else ends..
//printf("insertion process is completed\n");
//if the control reaches here then it means definetly the node is inserted.
/*
now here's few things to consider:-
1. If i insert a new node in the tree then previous positions of the tree nodes will becomes invalid.
2.If i insert a new node in the tree then the weight of the other nodes in the subtree 
   will have to be inscremented as per as insertion.
*/
//we have to traverse the tree and assign the positions to the newly created node.
/*
let's traverse the tree 
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
*/
//inorder traversal
//we have not updated the weight yet.


if(*isAdded == true)
{
t1=bst->root;
t2=NULL;
int inOrderPst = -1;
bool inOrderTraversal = false;
while(1)
{
t2=t1;
//if(t1==NULL)break;
if(bst->comparator(t1->data,data)>0)
{
t1=t1->left;
continue;
}
if(bst->comparator(t1->data,data)<0)
{
inOrderPst = inOrderPst+getWeight(t1->left) + 1+1;
t1=t1->right;
continue;
}
if(bst->comparator(t1->data,data)==0)
{
inOrderPst++;
inOrderTraversal=true;
break;
}
} //while ends

if(inOrderTraversal == true)
{

bstNodePosition->in_order_position = inOrderPst;

}

//pre-order traversal using the weight
int preOrderPos =-1;
t1=bst->root;
t2=NULL;
while(1)
{
t2=t1;
if(bst->comparator(t1->data,data)>0)
{
preOrderPos++;
t1=t1->left;
continue;
}
if(bst->comparator(t1->data,data)<0)
{
preOrderPos = preOrderPos + getWeight(t1->left)+1+1;
t1=t1->right;
continue;
}
if(bst->comparator(t1->data,data)==0)
{
preOrderPos++;

break;
}
}
bstNodePosition->pre_order_position=preOrderPos;


//post order traversal using weight
/*
Since, we will be finding the Post Order Position of newly inserted node then it can never be a parent node.
And if it's the root node we will simply return 0.
In post order Traversal first we traverse the left then right and lastly the root.
if the node is in the left side - do nothing
if node is in right side - position = position + weightOfTheLeftSubTreeOfTheParent + 1(because the weight doesn't count the left node);

*/
int postOrderPos =-1;
t1=bst->root;
t2=NULL;
while(1)
{
t2=t1;
if(t1 == NULL)break;
if(bst->comparator(t1->data,data)>0)
{

t1=t1->left;
continue;
}
if(bst->comparator(t1->data,data)<0)
{
postOrderPos = postOrderPos + getWeight(t1->left)+1;
t1=t1->right;
continue;
}
if(bst->comparator(t1->data,data)==0)
{
postOrderPos++;
break;
}
}


bstNodePosition->post_order_position=postOrderPos;
//weight balancing
//we don't have to worry if the node is going to be balanced or not because 
//if control reavhes here for sure the data is inserted in the tree.

t1=bst->root;
t2=NULL;

while(1)
{
if(t1==NULL)break;

t2=t1;
if(bst->comparator(t1->data,data)>0)
{
t1->weight++;
t1=t1->left;
continue;
}
if(bst->comparator(t1->data,data)<0)
{
t1->weight++;
t1=t1->right;
continue;
}
if(bst->comparator(t1->data,data)==0)break;
}//while ends
//printf("weight of root:%d ",bst->root->weight);
//if(bst->root->left!=NULL)printf("weight of left:%d ",bst->root->left->weight);
//if(bst->root->right!=NULL)printf("weight of right:%d ",bst->root->right->weight);
//for now to check if the program is working properly we will return the other as 0,0
*isAdded=true;
return bstNodePosition;
}//if of isAdded ends
}//insert_in_bst () ends


}//namespace matm ends



#endif