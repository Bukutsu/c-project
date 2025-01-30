//6620501303 Kongyut Klongklaew 712
#include <stdio.h>
#include <limits.h>

int V;

int minIndex(int key[], int inMST[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (inMST[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

int main() {
    int E;

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
    int d[V];
    int p[V];
    int inMST[V];


    for (int v = 0; v < V; v++) {
        d[v] = INT_MAX;
        p[v] = -1;
        inMST[v] = 0;
    }

    d[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minIndex(d, inMST);
        inMST[u] = 1;

        for (int v = 0; v < V; v++) {
            if (G[u][v] && inMST[v] == 0 && G[u][v] < d[v]) {
                d[v] = G[u][v];
                p[v] = u;
            }
        }
    }

    int weight = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", p[i], i, G[i][p[i]]);
        weight += G[i][p[i]];
    }

    printf("MST Weight = %d",weight);

    return 0;
}
