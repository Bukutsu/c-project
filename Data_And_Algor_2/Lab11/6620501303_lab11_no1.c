//6620501303 Kongyut Klongklaew 712
#include <stdio.h>
#include <limits.h>

#define INF 9999

struct edge{
    int u;
    int v;
    int w;
};


int min(int a,int b){
    if(a <= b) return a;

    return b;
}


void floyd_warshall(struct edge *edges,int V,int E){
    int D[V][V];

    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++){
            if(i == j){
                D[i][j] = 0;
            }else{
                D[i][j] = INF;
            }
        }
    }

    for(int i = 0;i < E;i++){
        D[edges[i].u - 1][edges[i].v - 1] = edges[i].w;
    }

    for(int k = 0;k < V;k++){
        printf("D[%d]\n",k+1);

        for(int i = 0;i < V;i++){

            for(int j = 0;j < V;j++){
                if(i == j){
                    D[i][j] = 0;
                }
                else{
                    if(D[i][k] != INF && D[k][j] != INF){
                        D[i][j] = min(D[i][j],D[i][k] + D[k][j]);
                    }

                }

                if(D[i][j] >= INF){
                    printf("\tINF");
                }else{
                    printf("\t%d",D[i][j]);
                }

            }

            printf("\n");
        }

    }

}



int main(){
    int V,E;

    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);

    struct edge edges[E];

    printf("Enter edges Cost (u,v,w)\n");

    for(int i = 0;i < E;i++){
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }

    floyd_warshall(edges,V,E);

    return 0;
}
