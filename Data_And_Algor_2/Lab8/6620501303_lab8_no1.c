//6620501303 Kongyut Klongklaew 712
#include <stdio.h>
#include <limits.h>
#define INF 9999

int minIndex(int key[], int inMST[],int v) {
    int min = INF, min_index;

    for (int i = 0; i < v; i++) {
        if (inMST[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

void prim_algo(int v,int G[v][v]){
    int d[v],p[v],in_MST[v];

    for(int i = 0;i < v;i++){
        d[i] = INF; p[i] = -1;
        in_MST[i] = 0;
    }
    
    d[0] = 0;

    for (int i = 0; i < v; i++)
    {
        int u = minIndex(d,in_MST,v);
        in_MST[u] = 1;
        for(int j = 0; j < v;j++){
            if(G[u][j] && !in_MST[j] && G[u][j] < d[j]){
                d[j] = G[u][j];
                p[j] = u;
            }
        }

    }

    int weight = 0;
    for (int i = 1; i < v; i++) {
        printf("%d - %d \t%d \n", p[i], i, G[i][p[i]]);
        weight += G[i][p[i]];
    }

    printf("MST Weight = %d\n",weight);
}

int main() {
    int E,V;

    printf("Enter Number of Vertex: ");
    scanf("%d", &V);
    printf("Enter Number of Edges: ");
    scanf("%d", &E);

    int G[V][V];


    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            G[i][j] = 0;
        }
    }


    for (int i = 0; i < E; i++) {
        printf("Edge %d u, v, w = ", i + 1);
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = w;
        G[v][u] = w;
    }

    printf("====MST====\n");
    printf("Edge\tWeight\n");

    // Prim's algorithm
    prim_algo(V,G);

    return 0;
}
