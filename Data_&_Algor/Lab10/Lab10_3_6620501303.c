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


struct Treenode* createNode(int data);
void push(struct Treenode* data);
struct Treenode* pop();
int max(int num1,int num2);
int height(struct Treenode *x);
int bf_node(struct Treenode *t);
void Tree_insert(int data);
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
        Tree_insert(input);
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

int bf_node(struct Treenode *t){
    return height(t->leftChild)-height(t->rightChild);
}


void Tree_insert(int data){
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
        if(top < MAXSTACK - 1) {
            push(y);
        } else {
            printf("Stack overflow during insertion. Tree may be incomplete.\n");
            return;
        }
    }
    x->mother = y;

    if(y == NULL) Root = x;
    else{
        if(x->data < y->data) y->leftChild = x;
        else y->rightChild = x;
    }

    // Balancing and height adjustment
    while(top != -1){
        struct Treenode* z = pop();
        z->ht = max(height(z->leftChild), height(z->rightChild)) + 1;
        int bf = bf_node(z);

        if(bf > 1 && bf_node(z->leftChild) <= -1){
            printf("Left-Right Double Rotate\n");
            z->leftChild = left_rotate(z->leftChild);
            z = right_rotate(z);
        }
        else if(bf < -1 && bf_node(z->rightChild) >= 1){
            printf("Right-Left Double Rotate\n");
            z->rightChild = right_rotate(z->rightChild);
            z = left_rotate(z);
        }
        else if(bf > 1){
            z = right_rotate(z);
        }else if(bf < -1){
            z = left_rotate(z);
        }

        // Update mother pointers after rotation
        if(z->leftChild) z->leftChild->mother = z;
        if(z->rightChild) z->rightChild->mother = z;

        // Update Root if necessary
        if(z->mother == NULL) Root = z;
        else if(is_left_node(z)) z->mother->leftChild = z;
        else z->mother->rightChild = z;
    }
}

bool is_left_node(struct Treenode *x){
    if (x == NULL || x->mother == NULL) {
        return false; 
    }
    return (x->mother->leftChild == x);
}

struct Treenode* right_rotate(struct Treenode *x){
    printf("Right Rotate at node: %d\n",x->data);

    struct Treenode *y = x->leftChild;
    struct Treenode *z = y->rightChild;

    y->rightChild = x;
    x->leftChild = z;

    y->mother = x->mother;
    x->mother = y;
    if(z) z->mother = x;

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

    y->mother = x->mother;
    x->mother = y;
    if(z) z->mother = x;

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