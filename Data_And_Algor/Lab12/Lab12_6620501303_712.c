#include <stdio.h>
#define MAXSTACK 10
int n;

char stack[MAXSTACK];
int top = -1;

void DFT(char *V,int G[n][n],int status[n]);


int main(int argc, char const *argv[])
{
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
    //BFT(V,G,status);


    return 0;
}

void DFT(char *V,int G[n][n],int status[n]){
    //step 0
    for(int i = 0;i < n;i++){
        status[i] = 1;
    }

    //step 1
    push(V[0]);

    //step 3
    while(top > 0){
        printf("%c ",pop());

    }

}

void push(char data){
    if(top >= MAXSTACK - 1){
        printf("Stack Overflow");
    }

    top++;
    stack[top] = data;
}

char pop(){
    if(top < 0){
        printf("Stack Underflow");
    }

    char data = stack[top];
    top--;
    return data;
}