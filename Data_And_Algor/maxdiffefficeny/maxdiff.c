#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maxdiff1(int *x,int n){
    int i,j,diff,max=0;

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            diff = abs(x[i]-x[j]);
            if(diff>max)
            max=diff;
        }
    }
}

void maxdiff2(int *x,int n){
    int i,max,min,maxdiff;
    max=x[0];
    min=x[0];
    for(i=1;i<n;i++){
        if(x[i] > max) max=x[i];
        if(x[i] < min) min=x[i];
    }
    maxdiff=max-min;
}

int main(){
    srand(time(NULL));
    int n = 3200;
    clock_t start_t, end_t;
    double total_t;

    //time maxdiff1
    while(n<250000){
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("n=%d\n",n);

        for(int i = 0;i < n; i++){
            arr[i] = rand() % 100;
        }

        start_t = clock();
        maxdiff1(arr,n);
        end_t = clock();

        total_t = (double)(end_t - start_t);
        printf("Approx milliseconds: %f\n",total_t);

        free(arr);
        n *= 2;
    }

    printf("\n\t---Maxdiff2---\n\n");
    n = 3200;

    //time maxdiff2
    while(n<250000){
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("n=%d\n",n);

        for(int i = 0;i < n; i++){
            arr[i] = rand() % 100;
        }

        start_t = clock();
        maxdiff2(arr,n);
        end_t = clock();

        total_t = (double)(end_t - start_t);
        printf("Approx milliseconds: %f\n",total_t);

        free(arr);
        n *= 2;
    }
    return 0;
}