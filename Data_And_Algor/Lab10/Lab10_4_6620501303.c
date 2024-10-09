#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSTACK 50
#define MAXINPUT 100
struct Treenode {
    int data,ht;
    struct Treenode *leftChild,*rightChild;
};
struct Treenode *Root;

struct Treenode* createNode(int data);
int max(int num1,int num2);
int height(struct Treenode *x);
int bf_node(struct Treenode *t);
struct Treenode* Tree_insert(struct Treenode* root, int data);
void print_node_inorder(struct Treenode *t);
void print_node_preorder(struct Treenode *t);
void print_node_postorder(struct Treenode *t);
struct Treenode* right_rotate(struct Treenode *x);
struct Treenode* left_rotate(struct Treenode *x);
bool is_node_found(struct Treenode *t,int key,int level);


int main()  {
    char input[MAXINPUT];
    int i = 0;
    fgets(input,MAXINPUT,stdin);
    while(input[i] != '\0'){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            Root = Tree_insert(Root,input[i]);
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
    return new_node;
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
    //printf("Right Rotate at node: %d\n",x->data);

    struct Treenode *y = x->leftChild;
    struct Treenode *z = y->rightChild;

    y->rightChild = x;
    x->leftChild = z;


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