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
  new_node->data = value;

  new_node->next=NULL;

    //hash function
    int key = value % 7;
    new_node->next=hash_table[key];
    hash_table[key] = new_node;
}

void printChain()
{
    struct node *ptr;
    for(int i=0;i<Size;i++){
        ptr = hash_table[i];
        printf("chain[%d]-->",i);
        while(ptr != NULL){
            printf("%d -->",ptr->data);
            ptr = ptr->next;
        }

        printf("NULL\n");
    }
}

int search_item(int x){
    struct node *ptr;
    for(int i=0;i<Size;i++){
        ptr = hash_table[i];
        int count = 0;
        while(ptr != NULL){
            count++;
            if(ptr->data == x){
                return count;
            }
            ptr = ptr->next;
        }
    }
    return -1;
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
 insertChain(49);
 insertChain(24);
 printChain();

 printf("%d\n",search_item(15));
 printf("%d\n",search_item(50));

 return 0;
}



