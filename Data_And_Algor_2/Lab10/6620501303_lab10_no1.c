//6620501303 Kongyut Klongklaew 712
#include <stdio.h>

#define INF 9999
#define NUM_VERTEX 5
#define NUM_EDGE 10

struct edge
{
    int u;
    int v;
    int w;
};


int Graph[NUM_VERTEX][NUM_VERTEX] = {  
    {0, 10, 0, 5, 0},
    {0, 0, 1, 2, 0},
    {0, 0, 0, 0, 4},
    {0, 3, 9, 0, 2},
    {7, 0, 6, 0, 0} 
};


void bellman_ford(int Graph[NUM_VERTEX][NUM_VERTEX],struct edge edges[NUM_EDGE],int *d,int *p,int s){
    for(int v = 0;v < NUM_VERTEX;v++){
        d[v] = INF; p[v] = -1;
    }
    d[s] = 0;

    printf("i\t");
    for(int i = 1; i <= NUM_VERTEX;i++){
        printf("%d\t",i);
    }

    for(int i = 1; i < NUM_VERTEX;i++){
        printf("\n%d",i);
        for(int j = 0;j < NUM_EDGE;j++){
            int curr_u = edges[j].u;
            int curr_v = edges[j].v;
            if(d[curr_u] + Graph[curr_u][curr_v] < d[curr_v]){
                d[curr_v] = d[curr_u] + Graph[curr_u][curr_v];
                p[curr_v] = curr_u;
            }
        }

        for(int j = 0;j < NUM_VERTEX;j++){
            printf("\t%d",d[j]);
        }
        
    }

    for(int i = 0;i < NUM_EDGE;i++){
            int curr_u = edges[i].u;
            int curr_v = edges[i].v;
            if(d[curr_u] + Graph[curr_u][curr_v] < d[curr_v]){
                printf("\nContain Negative cycle!!");
                return;
            }
    }

}

int main()
{
    struct edge edges[NUM_EDGE];
    
    int edge_count = 0;
    for(int i = 0;i < NUM_VERTEX;i++){
        for(int j = 0;j < NUM_VERTEX;j++){
            if(Graph[i][j] != 0){
                edges[edge_count].u = i;
                edges[edge_count].v = j;
                edges[edge_count].w = Graph[i][j];
                edge_count++;
            }
        }
    }

    printf("enter initial vertex : ");
    int s;
    scanf("%d",&s);
    s--;

    int d[NUM_VERTEX];
    int p[NUM_VERTEX];

    
    bellman_ford(Graph,edges,d,p,s);
    
    return 0;
}



