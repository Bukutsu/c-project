#include <stdio.h>
#include <stdbool.h>
#define MAXTREE 100
#define MAXSIZE 50
int tree[MAXTREE] = {0};

int stack[MAXSIZE] = {0};
int top = -1;
int size = 0;

bool is_full(){
    if(top == MAXSIZE -1) return 1;
    return 0;
}

bool is_empty(){
    if(top == -1) return 1;
    return 0;
}

void push(int data){
    if(!is_full()){
        top++;
        stack[top] = data;
    }
}

int pop(){
    int data = -1;
    if(!is_empty()){
        data = stack[top];
        top--;
    }
    return data;
}

void inorder(int node){
    while(!is_empty() || node < size){
        if(node < size && tree[node] != -1){
            push(node);
            node = 2*node+1;
        }else{
            node = pop();
            if(tree[node] != 0)
            printf("%d ",tree[node]);
            node = 2*node+2;
        }
    }
}

bool is_BST(int node){
    int prev = -1;
    while(!is_empty() || node < size){
        if(node < size){         
            push(node);
            node = 2*node+1;
        }else{
            node = pop();
            if(tree[node] != 0){
                if(prev >= tree[node]) return 0;
                prev = tree[node];
            }
            node = 2*node+2;
        }
    }
    return 1;
}

int sum_of_low_to_high(int node,int low,int high){
    int sum = 0;
        while(!is_empty() || node < size){
            if(tree[node] >= low && tree[node] <= high)
                sum += tree[node];
            if(node < size && tree[node] != -1){
                push(node);
                node = 2*node+1;
            }else{
                node = pop();
                node = 2*node+2;
            }
    }
    return sum;
}

int main(){
    int max_input_num = 0;
    int current_input = 0;
    int node = 0;

    scanf("%d",&max_input_num);
    
    int i = 0;
    for (int i = 0; i < max_input_num; i++) {
        scanf("%d", &tree[i]);
        if (tree[i] != -1) {
            size++;
        }
    }

    int low,high = 0;
    
    
    if(is_BST(0)){
        scanf("%d %d",&low,&high);
        printf("1\n");
        printf("%d",sum_of_low_to_high(0,low,high));
    }
    else printf("0\n");

    

    return 0;
}
