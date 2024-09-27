#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n){
    bool prime = 1;
    if(n == 1)prime = 0;
    if(n % 2 == 0 && n != 2)
        prime = 0;
    else{
        for(int i = 3; i < n-1 ; i += 2){
            if(n%i == 0){
                prime = 0;
                break;
            }
        }
    }
    return prime;
}

int main (){
    int n;
    scanf("%d",&n);

    int lower = n-1;
    int upper = n+1;

    while(1){
        if(isPrime(n)){
            printf("%d",n);
            break;
        }
        if(isPrime(lower)){
            printf("%d",lower);
            break;
        }

        if(isPrime(upper)){
            printf("%d",upper);
            break;
        }
        lower--;
        upper++;
    }
    return 0;
}
