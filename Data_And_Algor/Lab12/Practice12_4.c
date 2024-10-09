#include <stdio.h>
#define SIZE 5

void getDegree(int G[SIZE][SIZE],int k,int *inDeg,int *outDeg);


int main(int argc, char const *argv[])
{
    int G[SIZE][SIZE] = {0};
    G[0][1] = 1;
    G[0][2] = 1;
    G[1][0] = 1;
    G[2][0] = 1;
    G[3][0] = 1;
    int outDeg = 0;
    int inDeg = 0;

    getDegree(G,0,&inDeg,&outDeg);

    printf("%d\n",inDeg);
    printf("%d\n",outDeg);

    return 0;
}

void getDegree(int G[SIZE][SIZE],int k,int *inDeg,int *outDeg){
    for (int i = 0; i < SIZE; i++)
    {
        if(G[i][k] != 0){
            (*inDeg)++;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        if(G[k][i] != 0){
            (*outDeg)++;
        }
    }
}