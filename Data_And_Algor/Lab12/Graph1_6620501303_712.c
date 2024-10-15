#include <stdio.h>
#define MAXSTACK 10
int n;

int stack[MAXSTACK];
int top = -1;

int queue[MAXSTACK];
int size = 0;
int front = -1;
int rear = -1;

void DFT(char *V,int G[n][n],int status[n]);
void push(int data);
int pop();
void BFT(char *V,int G[n][n],int status[n]);
void enqueue(int data);
int dequeue();


int main(){
    int i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int status[n]; // Array for tracking status of each node
    int G[n][n]; // Array for representing Graph
    char V[n+1]; // Array for representing set of vertices

    printf("Enter node's name:");
    scanf("%s",V);


    printf("Enter the adjacency matrix:\n");
    for(int i = 0;i < n;i++){

        for(int j = 0;j < n;j++){
            scanf("%d",&G[i][j]);
        }
    }

    printf("DFS Traversal: ");
    DFT(V,G,status);
    printf("\nBFS Traversal: ");
    BFT(V,G,status);


    return 0;
}

void DFT(char *V,int G[n][n],int status[n]){
    //step 0
    for(int i = 0;i < n;i++){
        status[i] = 1;
    }

    //step 1
    push(0);
    status[0]= 2;

    //step 3
    int node = 0;
    while(top >= 0){
        node = pop();
        printf(" %c",V[node]);
        status[node] = 3;

        for(int i = 0;i < n;i++){
            if(G[node][i] == 1 && status[i] == 1){
                push(i);
                status[i] = 2;
            }
        }
    }

}

void push(int data){
    if(top >= MAXSTACK - 1){
        printf("Stack Overflow");
    }

    top++;
    stack[top] = data;
}

int pop(){
    if(top < 0){
        printf("Stack Underflow");
    }

    int data = stack[top];
    top--;
    return data;
}

void BFT(char *V,int G[n][n],int status[n]){
    //step 0
    for(int i = 0;i < n;i++){
        status[i] = 1;
    }

    //step 1
    enqueue(0);
    status[0]= 2;

    //step 3
    int node = 0;
    while(size > 0){
        node = dequeue();
        printf(" %c",V[node]);
        status[node] = 3;

        for(int i = 0;i < n;i++){
            if(G[node][i] == 1 && status[i] == 1){
                enqueue(i);
                status[i] = 2;
            }
        }
    }

}


void enqueue(int data){
    if(size == MAXSTACK){
        printf("Overflow");
    }

    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear + 1) % MAXSTACK;
    }

    queue[rear] = data;
    size++;
}

int dequeue(){
    int data;
    if(size == 0){
        printf("underflow");
    }
    else{
        data = queue[front];
        front = (front + 1 ) % MAXSTACK;
        size--;
    }

    return data;
}
