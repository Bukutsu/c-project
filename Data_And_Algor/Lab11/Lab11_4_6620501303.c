#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void min_heapify(int* heap,int n);
void max_heapify(int* heap,int n);
void remove_min_heap(int* heap);
void remove_max_heap(int* heap);
void swap(int* a, int* b);

int last_index = 0;

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
        last_index++;
    }

    printf("\nSorting (A)scending order\nSorting (D)escending order\nSelect choice:");
    char choice;
    scanf("%c",&choice);
    if(choice == 'A'){
        min_heapify(heap,n-1);

        for(int i = 0;i < n ;i++){
            printf("%d ",heap[0]);
            remove_min_heap(heap);
        }
    }else if(choice == 'D'){
        max_heapify(heap,n-1);

        for(int i = 0;i < n ;i++){
            printf("%d ",heap[0]);
            remove_max_heap(heap);
        }
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

void max_heapify(int* heap,int n){
    int par_index = n/2-1;
    int left_index,right_index;

    while(par_index >= 0){
        left_index = 2*par_index+1;
        right_index = 2*par_index+2;
        while(left_index < n){
            int max_index = par_index;

            if(heap[left_index] > heap[max_index]){
                max_index = left_index;
            }

            if(heap[right_index] > heap[max_index] && right_index < n){
                max_index = right_index;
            }

            if(max_index == par_index) break;

            swap(&heap[max_index],&heap[par_index]);

            par_index = max_index;
            left_index = 2*par_index+1;
            right_index = 2*par_index+2;
        }

        par_index--;
    }             
}


void remove_max_heap(int* heap){
    int index = 0;
    int left_index = 2*index+1;
    int right_index = 2*index+2;
    last_index--;

    heap[index] = heap[last_index];


    while(left_index < last_index){
        if(heap[index] >= heap[left_index] && heap[index] >= heap[right_index]){
            break;
        }
            
        if(heap[left_index] > heap[right_index]){
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

}

void remove_min_heap(int* heap){
    int index = 0;
    int left_index = 2*index+1;
    int right_index = 2*index+2;
    last_index--;

    heap[index] = heap[last_index];


    while(left_index < last_index){
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

}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
