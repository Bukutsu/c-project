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
int search_item(int n){
 struct node *ptr;
  ptr = head;
  int count=0;
  while(ptr != NULL)
  {
    count++;
     if(ptr->data == n){
        return count;
     }

     ptr = ptr -> next;
  }
    return -1;
}




int main()
{
    int n = 6;
    int arrays[]={10,2,33,-3,65,67};


    for(int i=n;i>=0;i--){
        struct node *newnode = (struct node*)malloc(sizeof(struct node)) ;
        newnode->data = arrays[i];
        newnode->next = head;
        head = newnode;
    }

    printf("%d\n",search_item(65));
    printf("%d\n",search_item(50));

  free(head);

  //DisplayLL();
  //DisplayAddressLL();

}