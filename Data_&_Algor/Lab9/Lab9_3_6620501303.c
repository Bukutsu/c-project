#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXINPUT 100
struct Treenode {
    int data;
    struct Treenode *leftChild,*rightChild;
    struct Treenode *mother;
};
struct Treenode *Root=NULL;

struct Treenode* createNode(int data);
void Tree_insert(int data);
struct Treenode* Tree_Find(struct Treenode* t,int key);
int tree_find_level(struct Treenode* t,int key);
struct Treenode* FindMin(struct Treenode* t);
struct Treenode* FindMax(struct Treenode* t);
void Tree_delete(struct Treenode* t,int data);
void inorder(struct Treenode* t);
void preorder(struct Treenode* t);
void postorder(struct Treenode* t);

int main(){
    char input[MAXINPUT];
    fgets(input,MAXINPUT,stdin);
    input[strcspn(input, "\n")] = 0;

    int i = 0;
    while(input[i] != '\0'){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            if(tree_find_level(Root,input[i]) == -1){
                Tree_insert(input[i]);
            }  
        }
        else if(input[i] == '0'){
            Tree_delete(Root,input[++i]);
        }
        else if(input[i] == '1'){
            printf("%d",tree_find_level(Root,input[++i]));
        }
        else if(input[i] == '2'){
            preorder(Root);
        }
        else if(input[i] == '3'){
            inorder(Root);
        }
        else if(input[i] == '4'){
            postorder(Root);
        }
        else if(input[i] == '5'){
            printf("%c",(FindMin(Root))->data);
            printf("%c",(FindMax(Root))->data);
        }

        i++;
    }

    return 0;
}

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

int tree_find_level(struct Treenode* t,int key){
    int count = 0;
    while(t != NULL){
        if(t->data == key){
            return count;
        }
        if(t->data < key){
            t = t->rightChild;
        }else{
            t = t->leftChild;
        }
        count++;
    }
    return -1;
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
    if(x == NULL) printf("-1") ;
    else{
        if (x->leftChild != NULL && x->rightChild != NULL){
            y = FindMin(x->rightChild);
            x->data = y->data;
            Tree_delete(x->rightChild,y->data);
        }else{
            if(x->leftChild == NULL && x->rightChild == NULL){
                if(x->mother->leftChild == x){
                    x->mother->leftChild = NULL;
                }else if(x->mother->rightChild == x){
                    x->mother->rightChild = NULL;
                }
                free(x);
            }
            else if(x->leftChild != NULL && x->rightChild == NULL){
                if(x->mother->leftChild == x){
                    x->mother->leftChild = x->leftChild;
                    x->leftChild->mother = x->mother;
                }else if(x->mother->rightChild == x){
                    x->mother->rightChild = x->leftChild;
                    x->leftChild->mother = x->mother;
                }
                free(x);
            }
            else if(x->leftChild == NULL && x->rightChild != NULL){
                if(x->mother->leftChild == x){
                    x->mother->leftChild = x->rightChild;
                    x->rightChild->mother = x->mother;
                }else if(x->mother->rightChild == x){
                    x->mother->rightChild = x->rightChild;
                    x->rightChild->mother = x->mother;
                }
                free(x);
            }
            
        }
    }
}

void inorder(struct Treenode* t)
{
    if(t != NULL){
        inorder(t->leftChild);
        printf("%c",t->data);
        inorder(t->rightChild);
    }

    return;
}

void preorder(struct Treenode* t)
{
    if(t != NULL){
        printf("%c",t->data);
        preorder(t->leftChild);
        preorder(t->rightChild);
    }

    return;
}

void postorder(struct Treenode* t)
{
    if(t != NULL){
        postorder(t->leftChild);
        postorder(t->rightChild);
        printf("%c",t->data);
    }

    return;
}
