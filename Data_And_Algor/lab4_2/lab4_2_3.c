#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void bubble_sort_ll(struct Node *head);
void swap_node(struct Node *a,struct Node *b);
void print_node_data(struct Node *head);
void add_new_node(struct Node **head,int new_data);
void DisplayAddressLL();

int main(){
    int n,k,current_input=0;
    printf("Enter n: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&current_input);
        new_node->data = current_input;
        new_node->next = head;
        head = new_node;
    }

    bubble_sort_ll(head);
    print_node_data(head);

    printf("\nEnter value of newnode: ");
    scanf("%d",&k);

    add_new_node(&head,k);

    print_node_data(head);

    DisplayAddressLL();

    free(head);
    return 0;
}

void print_node_data(struct Node *head){
    struct Node *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void swap_node(struct Node *a,struct Node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubble_sort_ll(struct Node *head){
    bool swapped;
    struct Node *ptr1 = head;
    struct Node *lptr = NULL;

    do{
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap_node(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while(swapped);
}

void add_new_node(struct Node **head, int new_data) {
    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    // Case 1: Insert at the beginning
    if (*head == NULL || new_data < (*head)->data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct Node *ptr = *head;
    struct Node *prev = NULL;

    // Traverse to find the correct position
    while (ptr != NULL && ptr->data <= new_data) {
        prev = ptr;
        ptr = ptr->next;
    }

    // Case 2: Insert in the middle
    if (ptr != NULL) {
        new_node->next = ptr;
        prev->next = new_node;
    }
    // Case 3: Insert at the end
    else {
        prev->next = new_node;
    }
}

void DisplayAddressLL()
{
  struct Node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("Node val=%d,add=%X\t ", ptr -> data,ptr);
     printf("Next node add=%X\n",ptr->next);

     ptr = ptr -> next;
  }
}