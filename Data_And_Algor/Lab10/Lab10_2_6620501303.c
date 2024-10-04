#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int max(int num1,int num2){
    if(num1 >= num2) return num1;
    return num2;
}

int height(struct Treenode *x){
    if(x == NULL) return 0;
    return 1+max(height(x->leftChild),height(x->rightChild));
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



bool is_AVL(struct Treenode* t)
{

    if(t != NULL){
        is_AVL(t->leftChild);
        int bf = height(t->leftChild)-height(t->rightChild);
        if(bf < -1 || bf > 1){
            return false;
        }
        is_AVL(t->rightChild);
    }
}


int main()  {
  int input = 0;
  while(input >= 0){
    scanf("%d",&input);
    if(input < 0) break;
    Tree_insert(input);
  }

    if(is_AVL(Root)){
        printf("an AVL Tree");
    }else printf("Not an AVL Tree");


  return 0;
}
