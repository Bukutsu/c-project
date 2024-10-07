#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void insert_heap(int data);
bool is_min_heap(int *heap,int n);
void min_heapify(int* heap,int n);
void swap(int* a, int* b);
void print_heap_by_level(int *heap,int n);

int main(){
    int input_count = 0;
    int data;
    int i,n=20;
    int heap[n];
    srand((unsigned) time(NULL));


    printf("Number before sorting\n");
    for(int i = 0;i < n ;i++){
        heap[i] = rand()%100+1;
        printf("%d ",heap[i]);
    }

    

    return 0;
}

void min_heapify(int* heap,int n){
    int par_index = n/2-1;
    int left_index,right_index;

    while(par_index >= 0){
        left_index = 2*par_index+1;
        right_index = 2*par_index+2;
        while(left_index < n){
            int index = par_index;
            if(heap[index] <= heap[left_index] && heap[index] <= heap[right_index]){
                break;
            }
                
            if(heap[left_index] < heap[right_index]){
                swap(&heap[index],&heap[left_index]);
                index = left_index;
            }
            else{
                swap(&heap[index],&heap[right_index]);
                index = right_index;
            }

            left_index = 2*index+1;
            right_index = 2*index+2;
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


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
