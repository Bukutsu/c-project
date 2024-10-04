#include <stdio.h>
#include <stdlib.h>

struct Treenode {
 char data;
 struct Treenode *leftChild;
 struct Treenode *rightChild;
};
struct Treenode *Root = NULL;

struct Treenode* createNode(char );
void SetLeft(struct Treenode* , char );
void SetRight(struct Treenode*, char );
void preorder(struct Treenode *);
void postorder(struct Treenode *);

int main()
{
   struct Treenode *pn,*tnode;

  //create Exptree for Lab8
  //create root node
  tnode=createNode('*');
  if(Root == NULL)
    Root=tnode;

  //create node level 1
  SetLeft(Root,'+');
  SetRight(Root,'-');

  //create node level 2
  pn=Root->rightChild;
  SetLeft(pn,'E');
  SetRight(pn,'F');


  //create node level 3
  pn=Root->leftChild;
  SetLeft(pn,'*');
  SetRight(pn,'/');

    //create node level 4
  pn=pn->leftChild;
  SetLeft(pn,'A');
  SetRight(pn,'B');
  pn=Root->leftChild->rightChild;
  SetLeft(pn,'C');
  SetRight(pn,'D');

  //call preorder and postorder
    printf("Prefix :");
    preorder(Root);
    printf("\n");
    printf("Postfix :");
    postorder(Root);

   free(tnode);
   free(pn);

  return 0;
}

void SetLeft(struct Treenode* pn, char data){
    struct Treenode *new_node = createNode(data);

    if (pn->leftChild == NULL)
        pn->leftChild = new_node;
    else
        printf("Node in-used\n");

}

void SetRight(struct Treenode* pn, char data){
     struct Treenode *new_node = createNode(data);

    if (pn->rightChild == NULL)
        pn->rightChild = new_node;
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

void preorder(struct Treenode *pn){
    if(pn != NULL){
        printf("%c ",pn->data);
        preorder(pn->leftChild);
        preorder(pn->rightChild);
    }else
    return;
}

void postorder(struct Treenode *pn){
    if(pn != NULL){
        postorder(pn->leftChild);
        postorder(pn->rightChild);
        printf("%c ",pn->data);
    }else
    return;
}

