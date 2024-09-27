#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
   int data;
   struct node *next;
};

struct node *head=NULL;

void DisplayLL()
{
  struct node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("%d ", ptr -> data);
     ptr = ptr -> next;
  }
  printf("\n");
}

void DisplayAddressLL()
{
  struct node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("Node val=%d,add=%X\t ", ptr -> data,ptr);
     printf("Next node add=%X\n",ptr->next);

     ptr = ptr -> next;
  }
}

int main()
{
  srand((unsigned) time(NULL));
  int n;
  scanf("%d", &n);

    for(int i=0;i<n;i++){
        struct node *newnode = (struct node*)malloc(sizeof(struct node)) ;
        newnode->data = rand()%100 +1;
        newnode->next = head;
        head = newnode;
    }


  free(head);

  DisplayLL();
  DisplayAddressLL();

}