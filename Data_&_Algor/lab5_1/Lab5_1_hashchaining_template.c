#include<stdio.h>
#include<stdlib.h>
#define Size 7

struct  node
{
  int data;
  struct node *next;
};
struct node *hash_table[Size];   //array of pointer

void insertChain(int value)
{
  struct node *new_node;
  new_node= (struct node*) malloc(sizeof(struct node));
  //assign value to the new_node

  new_node->next=NULL;


}

void printChain()
{

}


int main()
{
   int i;

   for(i=0;i<Size;i++)     //initialize a chained hash table
     hash_table[i]=NULL;

 insertChain(15);
 insertChain(22);
 insertChain(95);
 insertChain(56);
 insertChain(12);
 insertChain(27);
 insertChain(63);
 printChain();



 return 0;
}
