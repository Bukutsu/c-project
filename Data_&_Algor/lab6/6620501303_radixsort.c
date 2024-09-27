#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct qnode{
    int data;
    int priority;
    struct qnode *next;
};


struct qnode *front = NULL;
struct qnode *rear = NULL;



void enqueue(int data,int priority);
int dequeue(int data_to_remove);

int main()
{
    
    int i,n=20;
    srand((unsigned) time(NULL)); //Initializes random number generator
    int num[n];
    printf("Number before sorting\n");
    for(i=0;i<n;i++){ 
        num[i]=rand(); //random number between 0-32767
        printf("%d ",num[i]);
    }

    printf("\n");



// Fill your code here for sorting number using Radix sort


    int digit = 1;
    while(digit < 100000){
        for(i=0;i<n;i++){ 
            int current_num = num[i] / digit;
            int current_digit = current_num % 10;
            enqueue(num[i],current_digit);
        }

        int j = 0;
        for(i=0;i<10;i++){
            struct qnode *ptr = front;
            while(ptr != NULL){
                if(ptr->priority == i){
                    num[j] = dequeue(ptr->data);
                    j++;
                }
                ptr = ptr->next;
            }
        }

        digit *= 10;
    }

    

    printf("\n");
    printf("Number after sorting\n");
    for(i=0;i<n;i++){ 
    printf("%d ",num[i]);
    }

    return 0;
}

// void print_node(struct qnode *head){
//     struct qnode *ptr = head;
//     while(ptr != NULL){
//         printf("%d ",ptr->data);

//         ptr = ptr->next;
//     }
//     printf("\n");
// }

void enqueue(int data,int priority){
    struct qnode *new_node = (struct qnode*)malloc(sizeof(struct qnode));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if(front == NULL){
        front = new_node;
        rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue(int data_to_remove) {
    int data = -1;
    if (front == NULL) {
        printf("\nQueue is empty\n");
        return data;
    }

    struct qnode *preptr = NULL;
    struct qnode *ptr = front;

    while (ptr != NULL && ptr->data != data_to_remove) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\nElement not found in queue\n");
        return data;
    }

    data = ptr->data;

    if (preptr == NULL) {
        // Removing the first element
        front = ptr->next;
    } else {
        preptr->next = ptr->next;
    }

    if (front == NULL) {
        // Queue is now empty
        rear = NULL;
    }

    free(ptr);
    return data;
}

