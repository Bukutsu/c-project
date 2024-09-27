#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 10

int numCompare=0,numSwap=0;

void swap(int *xp,int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort(int A[], int n)
{
    int i,j,min_idx;
    for(i = 0;i< n-1;i++){
        min_idx = i;
        for (j = i+1 ; j < n;j++)
        numCompare++;
            if (A[j] < A[min_idx]){
                min_idx = j;
            }
                
        if(min_idx != i){
            swap(&A[min_idx],&A[i]);
            numSwap++;
        }
    }
}

void InsertionSort(int A[], int n)
{
    int i,j,key;
    for(i = 1;i<n;i++){
        key = A[i];
        j = i-1;
        numCompare++;
        while (j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
            numSwap++;
        }
        A[j+1] = key;
    }
}

void BubbleSort(int A[], int n)
{
    int i,j;
    bool swapped;
    for(i = 0;i < n-1;i++){
        swapped = false;
        
        for(j = 0;j < n - i - 1;j++){
            numCompare++;
            if(A[i] > A[i+1]){
                swap(&A[i],&A[i+1]);
                numSwap++;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void DisplayArray(int A[],int n){
    int i;
    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int A[MAX];
    int i;

    for(i=0;i<MAX;i++)
        A[i] = i+1;

    // for(i=0;i< MAX;i++){
    //     A[i] = 10-i;
    // }

    // srand((unsigned) time(NULL));
    // for (i=0;i< MAX;i++){
    //     A[i] = rand()%30 +1;
    // }

    printf("---Selection Sort---\n");
    DisplayArray(A,MAX);
    SelectionSort(A,MAX);
    DisplayArray(A,MAX);
    printf("#Comparison : %d\n#Swap : %d\n",numCompare,numSwap);

    numCompare = 0;
    numSwap = 0;
    printf("---Insertion Sort---\n");
    DisplayArray(A,MAX);
    InsertionSort(A,MAX);
    DisplayArray(A,MAX);
    printf("#Comparison : %d\n#Swap : %d\n",numCompare,numSwap);

    numCompare = 0;
    numSwap = 0;
    printf("---Bubble Sort---\n");
    DisplayArray(A,MAX);
    BubbleSort(A,MAX);
    DisplayArray(A,MAX);
    printf("#Comparison : %d\n#Swap : %d\n",numCompare,numSwap);
}