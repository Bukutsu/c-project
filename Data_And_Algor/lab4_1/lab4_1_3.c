#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int data;
    struct Node *next;
}Node;

Node *head=NULL;

void bubble_sort_ll(Node *head);
void swap_node(Node *a,Node *b);
void print_node_data(Node *head);
void add_new_node(Node **head,int new_data);
void DisplayAddressLL();

int main(){
    srand(time(NULL));
    int n,k,current_input=0;
    printf("Enter n: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->data = rand()%100 +1;
        new_node->next = head;
        head = new_node;
    }

    print_node_data(head);
    bubble_sort_ll(head);
    print_node_data(head);
    DisplayAddressLL();

    printf("\nEnter value of newnode: ");
    scanf("%d",&k);

    add_new_node(&head,k);

    print_node_data(head);

    DisplayAddressLL();

    free(head);
    return 0;
}

void print_node_data(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void swap_node(Node *a,Node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubble_sort_ll(Node *head){
    bool swapped;
    Node *ptr1 = head;
    Node *lptr = NULL;

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

void add_new_node(Node **head, int new_data) {
    Node *new_node = malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = NULL;

    // Case 1: Insert at the beginning
    if (*head == NULL || new_data < (*head)->data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *ptr = *head;
    Node *prev = NULL;

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
  Node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("Node val=%d,add=%X\t ", ptr -> data,ptr);
     printf("Next node add=%X\n",ptr->next);

     ptr = ptr -> next;
  }
}