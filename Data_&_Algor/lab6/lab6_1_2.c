#include <stdio.h>
#include <stdlib.h>

struct Q{
    int data;
    struct Q *next;
};
struct Q *Front = NULL;
struct Q *Rear = NULL;

void enqueue(int);
int dequeue();
void displayQ();

int main()
{
    int i,n;
    for(i=1;i<1000;i*=2)
        enqueue(i);
    displayQ();
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        dequeue();
    displayQ();
    for(i=10;i>=1;i/=2)
        enqueue(i);
    displayQ();
}

void enqueue(int data){

    struct Q *new_node = (struct Q*)malloc(sizeof(struct Q));
    new_node->data = data;
    new_node->next = NULL;

    if(Front == NULL){
        Front = new_node;
        Rear = new_node;
    }
    else{
        Rear->next = new_node;
        Rear = new_node;
    }
}



int dequeue(){
    int data;
    if(Front == NULL){
        printf("\nQueue is Empty\n");
        return -1;
    }
    else{
        struct Q *ptr = Front;
        Front = Front->next;
        ptr->next = NULL;
        free(ptr);
        return 0;
    }

}

void displayQ(){
    int i;
    if(Front == NULL){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("front[ ");
        struct Q *ptr = Front;
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("]rear\n");
    }


}
