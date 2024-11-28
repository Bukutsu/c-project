#include <stdio.h>

void print_prime(int n){
    int prime[n+1];
    for(int i = 0;i <= n;i++){
        prime[i] = i;
    }

    int i = 2;
    while(i <= n){
        int j = i;
        while(j <= n){
            if(prime[j] == 0 || prime[j] % i == 0 || prime[j] >= i*i){
                prime[j] = 0;
            }
            j++;
        }
        printf("%d",i);
        i++;
    }

    
}

int main(){
    print_prime(100);

    return 0;
}