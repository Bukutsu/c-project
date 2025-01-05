//6620501303 Kongyut Klongklaew 712
#include <stdio.h>
#include <stdlib.h>

int find_max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int main() {
    int n, W;
    printf("Enter n, W: ");
    scanf("%d %d", &n, &W);

    int wt[n];
    int val[n];
    int K[n + 1][W + 1];
    int max = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter value & weight of item %d: ", i + 1);
        scanf("%d %d", &val[i], &wt[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = find_max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
            printf("%d\t", K[i][w]);
            if(K[i][w] >= max){
                max = K[i][w];
            }
        }
        printf("\n");

        
    }
    

    int w = W;
    int temp_max = max;
    int selected[n];
    int count = 0;
    
    printf("knapsack contain items: ");
    for (int i = n; i >= 1; i--) {
        if (K[i][w] != K[i-1][w]) {
            selected[count++] = i;
            temp_max -= val[i-1];
            w -= wt[i-1];
        }
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d", selected[i]);
        if (i > 0) printf(",");
    }



    printf("\nMaximum Value: %d",max);

    return 0;
}