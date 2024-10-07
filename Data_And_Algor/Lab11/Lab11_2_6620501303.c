#include <stdio.h>
#include <stdbool.h>

void insert_heap(int data);
bool is_min_heap(int *heap,int n);
void heapify(int* heap,int n);
void swap(int* a, int* b);
void print_heap_by_level(int *heap,int n);

int main(){
    int input_count = 0;
    int data;
    scanf("%d",&input_count);
    int min_heap[input_count];

    for(int i = 0;i < input_count ;i++){
        scanf("%d",&min_heap[i]);
    }

    if(is_min_heap(min_heap,input_count)){
        printf("a Min-Heap");
        
    }else{
        printf("Not a Min-Heap\n");
        heapify(min_heap,input_count);
        print_heap_by_level(min_heap,input_count);

    }

    return 0;
}

void heapify(int* heap,int n){
    int par_index = n/2-1;
    int left_index,right_index;

    while(par_index >= 0){
        left_index = 2*par_index+1;
        right_index = 2*par_index+2;
        while(left_index < n){
            int min_index = par_index;

            if(heap[left_index] < heap[min_index]){
                min_index = left_index;
            }

            if(heap[right_index] < heap[min_index] && right_index < n){
                min_index = right_index;
            }

            if(min_index == par_index) break;

            swap(&heap[min_index],&heap[par_index]);


            par_index = min_index;
            left_index = 2*par_index+1;
            right_index = 2*par_index+2;
        }

        par_index--;
        
    }
                
}
    

bool is_min_heap(int *heap,int n) {
    int par_index = n/2-1;
    int left_index = 2*par_index+1;
    int right_index = 2*par_index+2;

    while(par_index >= 0){
        if(heap[par_index] >= heap[right_index] || heap[par_index] >= heap[left_index]) return false;

        par_index--;
        left_index = 2*par_index+1;
        right_index = 2*par_index+2;
    }
    
    return true;
}

void print_heap_by_level(int *heap,int n){
    int level = 1;
    int current_level_node = 0;
    for(int i=0;i < n;i++){
        current_level_node++;
        printf("%d ",heap[i]);

        if(current_level_node == level){
            level *= 2;
            current_level_node = 0;
            printf("\n");
        }
        
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}
