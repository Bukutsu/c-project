//6620501303 Kongyut Klongklaew 712
#include <stdio.h>
#include <limits.h>

int V = 5;

int min_index(int *d, int *visited) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && d[v] < min) {
            min = d[v];
            min_index = v;
        }
    }

    return min_index;
}


void dijkstra(int G[V][V],int E,int s,int *d,int *p){
    int visited[V];

    for(int i = 0;i < V;i++){
        d[i] = INT_MAX;
        p[i] = -1;
        visited[i] = 0;
    }
    int num_d = V - 1;
    d[s] = 0;


    while (num_d >= 0){
        int u = min_index(d,visited);
        visited[u] = 1;

        for(int v = 0;v < V;v++){
            if(!visited[v] && G[u][v] != 0 && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v] ;
                p[v] = u;
            }
        }
        num_d--;
    }

   

}








int main() {
    int Graph[5][5] = { {0,10,0,5,0},
                        {0,0,1,2,0},
                        {0,0,0,0,6},
                        {0,3,9,0,2},
                        {7,0,6,0,0}};
    int E = 10;
    int d[V];
    int p[V];
    int s;

    printf("enter initial vertex: ");
    scanf("%d",&s);

    s--;
    dijkstra(Graph,E,s,d,p);

    for(int i = 0; i < V; i++) {
        if(i != s) {
            int curr = i;
            if(p[curr] != -1) {
                printf("%d -> %d : distance = %d\n", 
                       p[curr]+1, curr+1, d[i]);
            }
        }
    }

    return 0;
}
