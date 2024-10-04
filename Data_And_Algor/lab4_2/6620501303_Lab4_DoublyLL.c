#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CHAR_LIMIT 31


struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;

void add_new_node(struct Node **head, int new_data,int node_placement);
void delete_node(struct Node **head,int node_placement);
void print_node_data(struct Node **head);
void print_reverted_node_data(struct Node **head);
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
            int placement_to_insert = *iptr - '0';
            iptr++;
            int input_data = *iptr - '0';
            add_new_node(&head, input_data,placement_to_insert+1);
        }
        else if (*iptr == 'L') {
            iptr++;
            int placement_to_insert = INT_MAX;
            int input_data = *iptr - '0';
            add_new_node(&head, input_data,placement_to_insert);
        }
    }
    
    else if(*iptr == 'D'){
        iptr++; 
        if (*iptr == 'F') {
            delete_node(&head,1);
        }
        else if (*iptr == 'A') {
            iptr++;
            int placement_to_delete = *iptr - '0';
            delete_node(&head,placement_to_delete);
        }
        else if (*iptr == 'L') {
            int placement_to_delete = INT_MAX;
            delete_node(&head,placement_to_delete);
        }
    }

    else if(*iptr == 'P'){
        print_node_data(&head);
    }
    else if(*iptr == 'R'){
        print_reverted_node_data(&head);
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

void delete_node(struct Node **head, int node_placement) {
    if (*head == NULL) {
        return;  // List is empty
    }

    struct Node *current = *head;

    // Deleting the first node
    if (node_placement == 1) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    // Find the node to delete
    int current_position = 1;
    while (current != NULL && current_position < node_placement) {
        current = current->next;
        current_position++;
    }

    // If node not found
    if (current == NULL) {
        return;
    }

    // Adjust the pointers
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    // Free the node
    free(current);
}

void add_new_node(struct Node **head, int new_data,int node_placement) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    // If the list is empty or node_placement is 1, add at the beginning
    if (*head == NULL || node_placement == 1) {
        new_node->next = *head;
        //if the list is not empty
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }

    // Find the position to insert
    struct Node *current = *head;
    int current_position = 1;
    
    while (current->next != NULL && current_position < node_placement - 1) {
        current = current->next;
        current_position++;
    }

    // Insert the new node
    new_node->next = current->next;
    new_node->prev = current;
    //if the last node is not empty
    if (current->next != NULL) {
    current->next->prev = new_node;
    }
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

void print_reverted_node_data(struct Node **head){
    struct Node *ptr = *head;
    while(ptr->next != NULL){ 
        ptr = ptr->next;
    }
    while(ptr != NULL){
        printf("%d",ptr->data);
        ptr = ptr->prev;
    }

}