#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSTACK 50
#define MAXINPUT 100
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
void print_node_preorder(struct Treenode *t);
void print_node_postorder(struct Treenode *t);
struct Treenode* right_rotate(struct Treenode *x);
struct Treenode* left_rotate(struct Treenode *x);
bool is_left_node(struct Treenode *x);
bool is_node_found(struct Treenode *t,int key,int level);


int main()  {
    char input[MAXINPUT];
    int i = 0;
    fgets(input,MAXINPUT,stdin);
    while(input[i] != '\0'){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            Tree_insert(input[i]);
        }
        else if(input[i] == '1'){
           if(!is_node_found(Root,input[++i],0)){
            printf("-1");
           }
        }
        else if(input[i] == '2'){
            print_node_preorder(Root);
        }
        else if(input[i] == '3'){
            print_node_inorder(Root);
        }
        else if(input[i] == '4'){
            print_node_postorder(Root);
        }

        i++;
    }

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
            //printf("Stack overflow during insertion. Tree may be incomplete.\n");
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
        z->ht = height(z);
        int bf = bf_node(z);

        if(bf > 1 && bf_node(z->leftChild) <= -1){
           // printf("Left-Right Double Rotate\n");
            z->leftChild = left_rotate(z->leftChild);
            z = right_rotate(z);
        }
        else if(bf < -1 && bf_node(z->rightChild) >= 1){
           // printf("Right-Left Double Rotate\n");
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
    //printf("Right Rotate at node: %d\n",x->data);

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
    //printf("Left Rotate at node: %d\n",x->data);

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




bool is_node_found(struct Treenode *t,int key,int level){
    if(t == NULL) return false;
        
    if (t->data == key) {
        printf("%d",level);
        return true;
    }
        
    bool res1 = is_node_found(t->leftChild, key , level + 1);
    if(res1) return true; 
 
    bool res2 = is_node_found(t->rightChild, key, level + 1);
 
    return res2;

}



void print_node_preorder(struct Treenode *t){
    if(t != NULL){
        printf("%c",t->data);
        print_node_preorder(t->leftChild);
        print_node_preorder(t->rightChild);
    }
    return;
}

void print_node_inorder(struct Treenode *t){
    if(t != NULL){
        print_node_inorder(t->leftChild);
        printf("%c",t->data);
        print_node_inorder(t->rightChild);
    }
    return;
}

void print_node_postorder(struct Treenode *t){
    if(t != NULL){
        print_node_postorder(t->leftChild);
        print_node_postorder(t->rightChild);
        printf("%c",t->data);
    }
    return;
}