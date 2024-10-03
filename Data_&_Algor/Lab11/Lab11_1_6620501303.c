#include <stdio.h>
#define MAXINPUT 100

int min_heap[MAXINPUT];

int n = 0;

void insert_heap(int data);
void swap(int* a, int* b);

int main(){
    int input_count = 0;
    int data;
    scanf("%d",&input_count);
    for(int i = 0;i < input_count ;i++){
        scanf("%d",&data);
        insert_heap(data);
    }

    int level = 1;
    int current_level_node = 0;
    for(int i=0;i < n;i++){
        current_level_node++;
        printf("%d ",min_heap[i]);

        if(current_level_node == level){
            level *= 2;
            current_level_node = 0;
            printf("\n");
        }
        
        
        
    }

    return 0;
}


void insert_heap(int data){
    int index = n;
    n++;
    min_heap[index] = data;

    while (index >= 0){
        int parent_index = (index-1)/2;
        if(min_heap[index] < min_heap[parent_index]){
            swap(&min_heap[index],&min_heap[parent_index]);
            index = parent_index;
        }
        else break;
    }

}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}