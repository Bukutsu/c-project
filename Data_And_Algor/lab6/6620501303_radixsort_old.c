#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct qnode{
    int data;
    int priority;
    struct qnode *next;
};


struct qnode *front = {NULL};
struct qnode *rear = {NULL};



void enqueue(int data,int priority);
int dequeue();
void print_node(struct qnode *head);

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
                    num[j] = ptr->data;
                    j++;
                }
                ptr = ptr->next;
            }
        }

        for(i=0;i<n;i++){ 
            dequeue();
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

void print_node(struct qnode *head){
    struct qnode *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);

        ptr = ptr->next;
    }
    printf("\n");
}

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

int dequeue(){
    int data;
    if(front == NULL){
        printf("\nqueue is empty\n");
        return -1;
    }
    else{
        struct qnode *ptr = front;
        data = ptr->data;
        front = front->next;
        ptr->next = NULL;
        free(ptr);
        return data;
    }
    
}

