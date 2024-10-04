#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 50
struct Treenode {
    int data,ht;
    struct Treenode *leftChild,*rightChild;
    struct Treenode *mother;
};
struct Treenode *Root;

struct Treenode *stack[MAXSTACK];
int top = -1;

struct Treenode* createNode(int data){
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->ht=0;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}

void push(struct Treenode* data){
    if(top == MAXSTACK-1) printf("Stack Overflow\n");
    else{
        top++;
        stack[top] = data;
    }
}

struct Treenode* pop(){
    struct Treenode* data;
    if(top == -1) printf("Stack underflow\n");
    else{
        data = stack[top];
        top--;
    }
    return data;
}

void inorder(struct Treenode* t)
{
    if(t != NULL){
        inorder(t->leftChild);
        printf("%d (BF=%d)\n",t->data,height(t->leftChild)-height(t->rightChild));
        inorder(t->rightChild);
    }

    return;
}

void Tree_insert(int data) {
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
        push(y);
    }
    x->mother = y;
    if(y == NULL) Root = x;
    else{
        if(x->data < y->data) y->leftChild = x;
        else y->rightChild = x;
    }
    while(top != -1){
        struct Treenode* z = pop();
        z->ht = height(z);
    }
}

int height(struct Treenode *x){
    if(x == NULL) return 0;
    return 1+max(height(x->leftChild),height(x->rightChild));
}

int max(int num1,int num2){
    if(num1 >= num2) return num1;
    return num2;
}

int main()  {
  int a[]={17,3,19,1,6,18,22,4,25};
  int i,size;
  size=sizeof(a)/sizeof(a[0]);
  for(i=0;i<size;i++)
     Tree_insert (a[i]);
  inorder(Root);
  return 0;
}
