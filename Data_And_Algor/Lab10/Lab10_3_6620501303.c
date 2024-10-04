#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSTACK 50
struct Treenode {
    int data,ht;
    struct Treenode *leftChild,*rightChild;
};
struct Treenode *Root;

struct Treenode *stack[MAXSTACK];
int top = -1;


struct Treenode* createNode(int data);
void push(struct Treenode* data);
struct Treenode* pop();
int max(int num1,int num2);
int height(struct Treenode *x);
int bf_node(struct Treenode *t);
struct Treenode* Tree_insert(struct Treenode* root, int data);
void print_node_inorder(struct Treenode *t);
struct Treenode* right_rotate(struct Treenode *x);
struct Treenode* left_rotate(struct Treenode *x);
bool is_left_node(struct Treenode *x);

int main()  {
    int input = 0;
    while(input >= 0){
        printf("Insert node:");
        scanf("%d",&input);
        if(input < 0) break;
         Root = Tree_insert(Root, input);
    }

    print_node_inorder(Root);

    return 0;
}

struct Treenode* createNode(int data){
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->ht=0;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
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

int bf_node(struct Treenode *t){
    return height(t->leftChild)-height(t->rightChild);
}


struct Treenode* Tree_insert(struct Treenode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->leftChild = Tree_insert(root->leftChild, data);
    } else if (data > root->data) {
        root->rightChild = Tree_insert(root->rightChild, data);
    } else {
        return root;
    }

    root->ht = 1 + max(height(root->leftChild), height(root->rightChild));

    int balance = bf_node(root);

    if (balance > 1 && data < root->leftChild->data) {
        return right_rotate(root);
    }

    if (balance < -1 && data > root->rightChild->data) {
        return left_rotate(root);
    }

    if (balance > 1 && data > root->leftChild->data) {
        root->leftChild = left_rotate(root->leftChild);
        return right_rotate(root);
    }

    if (balance < -1 && data < root->rightChild->data) {
        root->rightChild = right_rotate(root->rightChild);
        return left_rotate(root);
    }

    return root;
}


struct Treenode* right_rotate(struct Treenode *x){
    printf("Right Rotate at node: %d\n",x->data);

    struct Treenode *y = x->leftChild;
    struct Treenode *z = y->rightChild;

    y->rightChild = x;
    x->leftChild = z;


    y->ht = max(height(y->leftChild), height(y->rightChild)) + 1;
    x->ht = max(height(x->leftChild), height(x->rightChild)) + 1;

    return y;
}

struct Treenode* left_rotate(struct Treenode *x){
    printf("Left Rotate at node: %d\n",x->data);

    struct Treenode *y = x->rightChild;
    struct Treenode *z = y->leftChild;

    y->leftChild = x;
    x->rightChild = z;

    y->ht = max(height(y->leftChild), height(y->rightChild)) + 1;
    x->ht = max(height(x->leftChild), height(x->rightChild)) + 1;


    return y;
}


void print_node_inorder(struct Treenode *t){
    if(t != NULL){
        print_node_inorder(t->leftChild);
        printf("%d(BF=%d)",t->data,bf_node(t));
        print_node_inorder(t->rightChild);
    }
    return;
}