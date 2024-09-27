#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXINPUT 50

struct Treenode {
 int data;
 struct Treenode *leftChild;
 struct Treenode *rightChild;
};

struct stack_node{
    struct Treenode *data;
    struct stack_node *next;
};

struct Treenode *Root = NULL;
struct stack_node *Top = NULL;

struct Treenode* createNode(char );
void SetLeft(struct Treenode* ,struct Treenode* data);
void SetRight(struct Treenode*,struct Treenode* data);
bool isEmpty();
void push(struct Treenode* data);
struct Treenode* pop();
void print_infix(struct Treenode *pn);
int evaluate(struct Treenode *pn);

int main()
{
   struct Treenode *pn,*tnode;
   char input[MAXINPUT];
    fgets(input,MAXINPUT,stdin);
    int index = strlen(input) - 2;

    //create tree from input uwu xd
    for(int i = index;i >= 0;i--){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            tnode = createNode(input[i]);
            SetLeft(tnode,pop());
            SetRight(tnode,pop());
            push(tnode);
        }
        else{
            tnode = createNode(input[i]);
            push(tnode);
        }
    }
    print_infix(Top->data);
    printf("=%d",evaluate(Top->data));

   free(tnode);
   free(pn);

  return 0;
}

void SetLeft(struct Treenode* pn,struct Treenode* data){
    if (pn->leftChild == NULL)
        pn->leftChild = data;
    else
        printf("Node in-used\n");

}

void SetRight(struct Treenode* pn,struct Treenode* data){
    if (pn->rightChild == NULL)
        pn->rightChild = data;
    else
        printf("Node in-used\n");

}

struct Treenode* createNode(char data){
    struct Treenode *new_node = (struct Treenode*)malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;

    return new_node;
}

void print_infix(struct Treenode *pn){
    if(pn != NULL){
        if(pn->data == '+' || pn->data == '-' || pn->data == '*' || pn->data == '/'){
            printf("(");
            print_infix(pn->leftChild);
            printf("%c",pn->data);
            print_infix(pn->rightChild);
            printf(")");
        }
        else{
            printf("%c",pn->data);
        }
    }else
    return;
}

bool is_leaf(struct Treenode *pn){
    if(pn->leftChild == NULL && pn->rightChild == NULL) return true;
    return false;
}

int evaluate(struct Treenode *pn){
    if(pn == NULL) return 0;
    if(is_leaf(pn)) return (pn->data) - '0';
    int x = evaluate(pn->leftChild);
    int y = evaluate(pn->rightChild);
    char operator = pn->data;
    //debug
    //printf("\n");
    //printf("%d %c %d",x,operator,y);
    switch (operator)
    {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
    default: return 0;
    }
}

bool isEmpty()
{
    if(Top == NULL)
        return true;
    else
        return false;
}

void push(struct Treenode* data){
    struct stack_node *new_node = malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->next = NULL;

    if(isEmpty()){
        Top = new_node;
    }else{
        new_node->next = Top;
        Top = new_node;
    }
    //debug
    //printf("\npushed : %c",data->data);
}



struct Treenode* pop(){
    struct Treenode* data;
  if (isEmpty()){
    printf("Stack underflow");
  }
  else{
    struct stack_node *ptr = Top;
    Top = Top->next;
    ptr->next = NULL;

    data = ptr->data;
    //debug
    //printf("\npoped: %c",ptr->data->data);
    free(ptr);
  }
 
  return data;
}

