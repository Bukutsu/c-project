//6620501303 Kongyut Klongklaew 712
#include <stdio.h>

struct edge{
    int u;
    int v;
};


void generate_combinations(int vertex, int k, int V, int visited[], struct edge edges[], int E, int *found) {

    if (k == 0) {

        for (int i = 0; i < E; i++) {
            if (!visited[edges[i].u] && !visited[edges[i].v]) {
                return;  
            }
        }
        *found = 1;  
        return;
    }
    

    if (vertex >= V) return;
    

    visited[vertex] = 1;
    generate_combinations(vertex + 1, k - 1, V, visited, edges, E, found);
    if (*found) return;  
    
    visited[vertex] = 0;
    generate_combinations(vertex + 1, k, V, visited, edges, E, found);
}

int check_vertex_cover(struct edge *edges, int V, int E, int K) {
    int visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    
    int found = 0;
    generate_combinations(0, K, V, visited, edges, E, &found);
    return found;
}




int main(){
    int V,E;

    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);

    struct edge edges[E];

    printf("Enter edges Cost (u,v)\n");

    for(int i = 0;i < E;i++){
        scanf("%d %d",&edges[i].u,&edges[i].v);
    }

    printf("Enter the size of Vertex Cover (k): ");
    int K;
    scanf("%d", &K);

    if (check_vertex_cover(edges, V, E, K)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }



    return 0;
}
