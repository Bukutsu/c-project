#include <stdio.h>
int n;



int main(int argc, char const *argv[])
{
    int i,j;
    printf("Enter number of vertices");
    scanf("%d",&n);

    int status[n]; // Array for tracking status of each node
    int G[n][n]; // Array for representing Graph
    char V[n+1]; // Array for representing set of vertices

    printf("Enter node's name:");
    //Fill in your code
    printf("Enter the adjacency matrix:\n");
    //Fill in your code
    printf("DFS Traversal: ");
    DFT(V,G,status);
    printf("\nBFS Traversal: ");
    BFT(V,G,status);


    return 0;
}
