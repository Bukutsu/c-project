#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 50
#define NUMALPHA 26

char alpha[NUMALPHA];
int char_count[NUMALPHA];

int n = 0;

void insert_heap(char data);
void swap(int* a, int* b);
void swap_char(char* a, char* b);
void heapify(char* heap,int* num_heap);
void remove_heap();

int main(){
    char input[MAXINPUT];
    scanf("%[^\n]s",input);

    int i = 0;
    while(input[i] != '\0'){
        insert_heap(input[i]);
        i++;
    }

    heapify(alpha,char_count);
    


    while(n != 0){
        for(int j = char_count[0];j > 0;j--){
            printf("%c",alpha[0]);
        }
        remove_heap();
    }

    return 0;
}

void insert_heap(char data){
    for(int i = 0;i < n;i++){
        if(alpha[i] == data){
            char_count[i]++;
            return;
        }
    }

    int index = n;
    n++;
    alpha[index] = data;
    char_count[index]++;
}

void heapify(char* heap,int* num_heap){
    int par_index = n/2-1;
    int left_index,right_index;

    while(par_index >= 0){
        left_index = 2*par_index+1;
        right_index = 2*par_index+2;
        while(left_index < n){
            int max_index = par_index;

            if(num_heap[left_index] > num_heap[max_index]){
                max_index = left_index;
            }

            if(num_heap[right_index] > num_heap[max_index] && right_index < n){
                max_index = right_index;
            }

            if(max_index == par_index) break;

            swap_char(&heap[max_index],&heap[par_index]);
            swap(&num_heap[max_index],&num_heap[par_index]);

            par_index = max_index;
            left_index = 2*par_index+1;
            right_index = 2*par_index+2;
        }

        par_index--;
        
    }
                
}

void remove_heap(){
    int index = 0;
    int left_index = 2*index+1;
    int right_index = 2*index+2;
    n--;

    alpha[index] = alpha[n];
    char_count[index] = char_count[n];

    while(left_index < n){
        if(char_count[index] >= char_count[left_index] && char_count[index] >= char_count[right_index]){
            break;
        }
            
        if(char_count[left_index] > char_count[right_index]){
            swap_char(&alpha[index],&alpha[left_index]);
            swap(&char_count[index],&char_count[left_index]);
            index = left_index;
        }
        else{
            swap_char(&alpha[index],&alpha[right_index]);
            swap(&char_count[index],&char_count[right_index]);
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

void swap_char(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}