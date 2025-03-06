//6620501303 Kongyut Klongklaew 712
#include <stdio.h>

struct edge{
    int u;
    int v;
    int selected;
    int removed;
};


int is_incident(struct edge e1, struct edge e2) {
    return (e1.u == e2.u || e1.u == e2.v || 
            e1.v == e2.u || e1.v == e2.v);
}

void print_approx_vertex_cover(int E,struct edge edges[E]) {
    
    int selecting_index = 0;

    
    while(selecting_index < E) {
       
        if(edges[selecting_index].removed) {
            selecting_index++;
            continue;
        }
        

        edges[selecting_index].selected = 1;
        edges[selecting_index].removed = 1;
        
       
        for(int i = 0; i < E; i++) {
            if(!edges[i].removed && is_incident(edges[selecting_index], edges[i])) {
                edges[i].removed = 1;
            }
        }
        
        selecting_index++;
    }

    printf("Approximate Vertex Cover:");
    for(int i = 0; i < E;i++){
        if(edges[i].selected){
            printf(" (%d, %d)",edges[i].u,edges[i].v);
        }
    }
    printf("\n");
}   




int main(){
    int V,E;

    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);

    struct edge edges[E];

    printf("Enter the edges (u v) format\n");

    for(int i = 0;i < E;i++){
        scanf("%d %d",&edges[i].u,&edges[i].v);
        edges[i].selected = 0;
        edges[i].removed = 0;
    }


    print_approx_vertex_cover(E,edges);




    return 0;
}
