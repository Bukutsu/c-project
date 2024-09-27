#include <stdio.h>
#include <stdlib.h>

struct Treenode {
 int data;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
};
struct Treenode *Root;

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

struct Treenode* Tree_Find(struct Treenode* t,int key)
{
    while(t != NULL){
        if(t->data == key){
            return t;
        }
        if(t->data < key){
            t = t->rightChild;
        }else{
            t = t->leftChild;
        }
    }
    return NULL;
}

struct Treenode* FindMin(struct Treenode* t)
{
    while(t->leftChild != NULL){
        t = t->leftChild;
    }
    return t;
}

struct Treenode* FindMax(struct Treenode* t)
{
    while(t->rightChild != NULL){
        t = t->rightChild;
    }
    return t;
}

void Tree_delete(struct Treenode* t,int data)
{
    struct Treenode* x = NULL;
    struct Treenode* y = NULL;
    x = Tree_Find(t,data);
    if(x == NULL) printf("value is not found in the tree");
    else{
        if (x->leftChild != NULL && x->rightChild != NULL){
            y = FindMax(x->leftChild);
            x->data = y->data;
            Tree_delete(x->leftChild,y->data);
        }else{
            if(x->leftChild == NULL && x->rightChild == NULL){
                if(x->mother->leftChild == x){
                    x->mother->leftChild = NULL;
                }else if(x->mother->rightChild == x){
                    x->mother->rightChild = NULL;
                }
            }
            else if(x->leftChild == NULL && x->rightChild != NULL){
                if(x->mother->leftChild == x){
                    x->mother->leftChild = x->rightChild;
                }else if(x->mother->rightChild == x){
                    x->mother->rightChild = x->rightChild;
                }
            }
            else if(x->leftChild != NULL && x->rightChild == NULL){
                if(x->mother->leftChild == x){
                    x->mother->leftChild = x->leftChild;
                }else if(x->mother->rightChild == x){
                    x->mother->rightChild = x->leftChild;
                }
            }
        }
    }
}



int main()
{
  int a[]={56,26,200,18,28,190,213,12,24,27};
  int i,size;
  size=sizeof(a)/sizeof(a[0]);

  for(i=0;i<size;i++)
        Tree_insert(a[i]);

   printf("Min=%d\n",FindMin(Root)->data);
   printf("Max=%d\n",FindMax(Root)->data);

   struct Treenode *p;
   p=Tree_Find(Root,190);

  if(p!=NULL)
    printf("Found\n");
  else
    printf("Not found\n");

   Tree_delete(Root,190);
   Tree_delete(Root,26);

   Inorder(Root);
}

