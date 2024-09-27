#include <stdio.h>
#define maxsize 100
int Q[maxsize] = {0};
int front = -1,rear = -1;
int size=0;


void enqueue(int data){
    if(size == maxsize)
        printf("\nQueue is full\n");
    else{
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % maxsize;
        }
        Q[rear] = data;
        size++;
    }
}


int main(){
    int N,K;
    int i;
    int input;
    scanf("%d %d",&N,&K);

    for(i = 0;i<N;++i){
        scanf("%d",&input);
        enqueue(input); 
    }
    
    for(i = K-1;i>=front;i--){
        printf("%d ",Q[i % maxsize]); 
    }
    
    front += K;
    size -= K;

    for(i = front;i<size+front;i++){
        printf("%d ",Q[i % maxsize]);
    }

    return 0;
}
