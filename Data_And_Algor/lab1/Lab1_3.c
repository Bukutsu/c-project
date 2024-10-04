#include <stdio.h>
#include <stdlib.h>

int gcd(int n,int m);
int findGCD(int arr[], int n);

int main(){
    int count;
    scanf("%d",&count);
    int *num = malloc(count * sizeof(int));

    for(int i=0;i<count;i++){
        scanf("%d",&num[i]);
    }

    printf("%d",findGCD(num,count));

    return 0;
    free(num);
}


int findGCD(int arr[],int n){
    int result = arr[0];
    for (int i = 1;i < n;i++){
        result = gcd(arr[i],result);
    }

    if(result <= 1){
        return 1;
    }
    return result;
}

int gcd(int n,int m){
    if(n <= 0)
    return m;
    return gcd(m % n,n);
}