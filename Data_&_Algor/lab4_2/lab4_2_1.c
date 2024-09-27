#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
   int data;
   struct node *next;
   struct node *prev;
};

struct node *head=NULL;

void doublyMaker(){
    struct node *ptr;
    struct node *preptr;
    preptr = head;
    ptr = preptr->next;

    preptr->prev=NULL;

    while(ptr != NULL){
        ptr->prev = preptr;

        preptr = preptr->next;
        ptr = preptr->next;

    }
}



void DisplayLL()
{
  struct node *ptr;
  ptr = head;
  while(ptr->next != NULL)
  {
     ptr = ptr -> next;
  }

  while(ptr != NULL){
    printf("%d ",ptr->data);
    ptr = ptr -> prev;
  }
  printf("\n");
}

void DisplayAddressLL()
{
  struct node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("Node val=%d,add=%X\n", ptr -> data,ptr);
     printf("Next node add=%X\n",ptr->next);
     printf("Previous node add=%X\n",ptr->prev);

     ptr = ptr -> next;
  }
}

int main()
{
  int n;
  scanf("%d", &n);

    for(int i=n;i>0;i--){
        struct node *newnode = (struct node*)malloc(sizeof(struct node)) ;
        newnode->data = i;
        newnode->next = head;
        head = newnode;
    }

  doublyMaker();
  DisplayLL();
  //DisplayAddressLL();

  free(head);


}
