#include <stdio.h>
#include <stdbool.h>
#define MAXINPUT 100

int min_heap[MAXINPUT];

int n = 0;

void insert_heap(int data);
bool is_min_heap(int heap[]);
void swap(int* a, int* b);

int main(){
    int input_count = 0;
    int data;
    scanf("%d",&input_count);
    n = input_count;
    for(int i = 0;i < input_count ;i++){
        scanf("%d",&min_heap[i]);
    }

    if(is_min_heap(min_heap)){
        printf("a Min-Heap");
    }else{
        printf("Not a Min-Heap");
    }

    return 0;
}

bool is_min_heap(int heap[]) {

}

