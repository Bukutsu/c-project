#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CHAR_LIMIT 31


struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void add_new_node(struct Node **head, int new_data,int node_placement);
void print_node_data(struct Node **head);
int search_node_data(struct Node **head,int num_to_find);

int main(){
    char input[CHAR_LIMIT];
    fgets(input,CHAR_LIMIT,stdin);

    char *iptr = input;
   
    while (*iptr != '\0') {
    if (*iptr == 'N') {
        iptr++; 
        if (*iptr >= '0' && *iptr <= '9') {
            int input_data = *iptr - '0'; // Convert char to int
            add_new_node(&head, input_data,1);
            }
        }
    else if(*iptr == 'I'){
        iptr++; 
        if (*iptr == 'F') {
            iptr++;
            int input_data = *iptr - '0'; 
            add_new_node(&head, input_data,1);
        }
        else if (*iptr == 'A') {
            iptr++;
            int placement_to_intsert = *iptr - '0';
            iptr++;
            int input_data = *iptr - '0';
            add_new_node(&head, input_data,placement_to_intsert+1);
        }
        else if (*iptr == 'L') {
            iptr++;
            int placement_to_intsert = INT_MAX;
            int input_data = *iptr - '0';
            add_new_node(&head, input_data,placement_to_intsert);
        }
    }
    
    else if(*iptr == 'P'){
        print_node_data(&head);
    }
    else if(*iptr == 'S'){
        iptr++; 
        if (*iptr >= '0' && *iptr <= '9') {
            int input_data = *iptr - '0'; // Convert char to int
            printf("%d",search_node_data(&head,input_data));
        }
    }
    
        iptr++;
    }

    free(head);
    return 0;
}

void add_new_node(struct Node **head, int new_data,int node_placement) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    // If the list is empty or node_placement is 1, add at the beginning
    if (*head == NULL || node_placement == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Find the position to insert
    struct Node* current = *head;
    int current_position = 1;
    
    while (current->next != NULL && current_position < node_placement - 1) {
        current = current->next;
        current_position++;
    }

    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
}

int search_node_data(struct Node **head,int num_to_find){
    struct Node *ptr = *head;
    int num_of_node = 0;
    while(ptr != NULL){
        num_of_node++;
        if(ptr->data == num_to_find){
            return num_of_node;
        }
        ptr = ptr->next;
    }
    return -1;
}


void print_node_data(struct Node **head){
    struct Node *ptr = *head;
    while(ptr != NULL){
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
}