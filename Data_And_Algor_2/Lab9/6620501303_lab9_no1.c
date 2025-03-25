//6620501303 Kongyut Klongklaew 712
#include <stdio.h>

struct edge{
    int u;
    int v;
    int w;
};

int compare(const void *a, const void *b) {

    struct edge *edgeA = (struct edge *)a;
    struct edge *edgeB = (struct edge *)b;

    return (edgeA->w - edgeB->w);
}

int find_set(int v,int *parent){
    if(v == parent[v]) return v;
    return find_set(parent[v],parent);
}

void union_set(int a,int b,int *parent){
    a = find_set(a,parent);
    b = find_set(b,parent);
    if(a != b) parent[b] = a;

}

int main() {
    int E,V;

    printf("Enter Number of Vertex: ");
    scanf("%d", &V);
    printf("Enter Number of Edges: ");
    scanf("%d", &E);

    struct edge edges[E];
    struct edge MST[V];

    int n = 0;
    int parent[V];

    for (int i = 0; i < E; i++) {
        printf("Edge %d u, v, w = ", i + 1);
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    printf("====MST====\n");
    printf("Edge\tWeight\n");

    // Kruskal's algorithm

        //make set
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

        //sort edges
    qsort(edges,E,sizeof(edges[0]),compare);


//    for (int i = 0; i < E; i++) {
//        for(int j = 0;j < E - 1;j++){
//            if(edges[j].w > edges[j + 1].w){
//                struct edge temp = edges[j];
//                edges[j] = edges[j + 1];
//                edges[j + 1] = temp;
//            }
//        }
//    }

        //union-find
    for (int i = 0; i < E;i++){
        if(find_set(edges[i].u,parent) != find_set(edges[i].v,parent)){
            MST[n] = edges[i];
            n++;
            union_set(edges[i].u,edges[i].v,parent);
        }
    }

        //print
    int weight = 0;
    for (int i = 0; i < n; i++) {
        printf("%d - %d \t%d \n", MST[i].u, MST[i].v, MST[i].w);
        weight += MST[i].w;
    }

    printf("MST Weight = %d",weight);

    return 0;
}
