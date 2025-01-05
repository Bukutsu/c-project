//6620501303 Kongyut Klongklaew 712
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int matrix_chain_multiplication(int p[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        // Print leading spaces
        for (int s = 1; s < i; s++) {
            printf("      ");
        }
        for (int j = i; j < n; j++) {
            printf("%-6d", m[i][j]);
        }
        printf("\n");
    }

    return m[1][n - 1];
}


int main() {
    int d;
    printf("Please input number of d :");
    scanf("%d",&d);

    int M[d+1];

    for(int i = 0;i < d;i++){
        printf("Enter d%d :",i + 1);
        scanf("%d",&M[i]);
    }

    int result = matrix_chain_multiplication(M, d);
    printf("Minimum number of multiplications = %d\n", result);
    

    return 0;
}