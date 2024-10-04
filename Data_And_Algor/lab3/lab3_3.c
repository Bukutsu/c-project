#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main(){
    int n,maxWeight;

    scanf("%d %d",&n,&maxWeight);

    int *weights = malloc(n * sizeof(n));

    for(int i = 0;i < n;i++){
        scanf("%d",&weights[i]);
    }

    //sorting weight
    bubble_sort(weights,n);

    int count = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= maxWeight) {
            currentWeight += weights[i];
            count++;
        }
    }
       


    printf("%d", count);

    free(weights);
    return 0;
}