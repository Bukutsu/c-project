#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
int n;

struct graph_node{
    char name;
    struct graph_node *next;
};

int stack[MAXSIZE];
int top = -1;

int queue[MAXSIZE];
int size = 0;
int front = -1;
int rear = -1;

struct graph_node* create_node(char name);
void insert_node(char name,struct graph_node **root);
void print_adjacent_node(struct graph_node *root);
void DFT(char *V,struct graph_node **vertices,int status[n]);
void push(int data);
int pop();
void BFT(char *V,struct graph_node **vertices,int status[n]);
void enqueue(int data);
int dequeue();


int main(){
    int i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int status[n]; // Array for tracking status of each node
    char V[n+1]; // Array for representing set of vertices

    struct graph_node *vertices[n];

    for(int i = 0;i < n;i++){
        vertices[i] = NULL;
    }

    printf("Enter node's name:");
    scanf("%s",V);

    printf("Enter the adjacency matrix:\n");
    int current;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&current);
            if(current == 1){
                insert_node(V[j],&vertices[i]);
            }
        }
    }

    printf("\n");
    for(int i = 0;i < n;i++){
        printf("[%c]-> ",V[i]);
        print_adjacent_node(vertices[i]);
        printf("\n");
    }

    printf("DFS Traversal: ");
    DFT(V,vertices,status);
    printf("\nBFS Traversal: ");
    BFT(V,vertices,status);


    return 0;
}

struct graph_node* create_node(char name){
    struct graph_node *new_node = malloc(sizeof(struct graph_node));
    new_node->name = name;
    new_node->next = NULL;

    return new_node;
};

void insert_node(char name,struct graph_node **root){
    struct graph_node *new_node = create_node(name);

    if(*root == NULL){
        *root = new_node;
        return;
    }

    new_node->next = *root;
    *root = new_node;
}

void print_adjacent_node(struct graph_node *root){
    struct graph_node *ptr = root;
    if(ptr == NULL){
        printf("NULL");
    }
    while(ptr != NULL){
        printf("%c",ptr->name);
        if(ptr->next != NULL) printf("->");
        ptr = ptr -> next;
    }
}

void DFT(char *V,struct graph_node **vertices,int status[n]){
    //step 0
    for(int i = 0;i < n;i++){
        status[i] = 1;
    }

    //step 1
    push(0);
    status[0]= 2;

    //step 3
    int node = 0;
    struct graph_node *ptr = vertices[node];
    while(top >= 0){
        node = pop();
        printf(" %c",V[node]);
        status[node] = 3;

        ptr = vertices[node];
  
        while(ptr != NULL){
            int i;
            for(i = 0;i < n;i++){
                if(V[i] == ptr->name){
                    break;
                }
            }

            if(status[i] == 1){
                push(i);
                status[i] = 2;
            }

            ptr = ptr->next;
        }
    }
}

void push(int data){
    if(top >= MAXSIZE - 1){
        printf("Stack Overflow");
    }

    top++;
    stack[top] = data;
}

int pop(){
    if(top < 0){
        printf("Stack Underflow");
    }

    int data = stack[top];
    top--;
    return data;
}

void BFT(char *V,struct graph_node **vertices,int status[n]){
    //step 0
    for(int i = 0;i < n;i++){
        status[i] = 1;
    }

    //step 1
    enqueue(0);
    status[0]= 2;

    //step 3
    int node = 0;
    struct graph_node *ptr = vertices[node];
    while(size > 0){
        node = dequeue();
        printf(" %c",V[node]);
        status[node] = 3;

        ptr = vertices[node];
  
        while(ptr != NULL){
            int i;
            for(i = 0;i < n;i++){
                if(V[i] == ptr->name){
                    break;
                }
            }

            if(status[i] == 1){
                enqueue(i);
                status[i] = 2;
            }

            ptr = ptr->next;
        }
    }

}

void enqueue(int data){
    if(size == MAXSIZE){
        printf("Overflow");
    }

    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear + 1) % MAXSIZE;
    }

    queue[rear] = data;
    size++;
}

int dequeue(){
    int data;
    if(size == 0){
        printf("underflow");
    }
    else{
        data = queue[front];
        front = (front + 1 ) % MAXSIZE;
        size--;
    }

    return data;
}
