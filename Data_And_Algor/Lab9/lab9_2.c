#include <stdio.h>
#include <stdlib.h>
struct Treenode {
 int data;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
};
struct Treenode *Root=NULL;

struct Treenode* createNode(int data)
{
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}


void Tree_insert(int data)
{
    struct Treenode* x = createNode(data);
    struct Treenode* y = NULL;
    struct Treenode* t = Root;

    while(t != NULL){
        y = t;
        if(data < t->data){
            t = t->leftChild;
        }else{
            t = t->rightChild;
        }
    }
    x->mother = y;
    if(y == NULL) Root = x;
    else{
        if(x->data < y->data) y->leftChild = x;
        else y->rightChild = x;
    }
}

void Inorder(struct Treenode* t)
{
    if(t != NULL){
        Inorder(t->leftChild);
        printf("%d ",t->data);
        Inorder(t->rightChild);
    }

    return;
}


int main()
{
   int i,count=20;
   int num[count];

   srand((unsigned) time(NULL));      //Initializes random number generator
   printf("Number before sorting\n");
   for(i=0;i<count;i++)
   {
      num[i]=rand();
      Tree_insert(num[i]);             //random number between 0-32767
      printf("%d ",num[i]);
   }
   printf("\nNumber after sorting\n");
    Inorder(Root);


   return 0;
}
