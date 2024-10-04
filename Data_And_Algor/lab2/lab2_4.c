#include <stdio.h>

int main(){
    int n,count = 0;

    scanf("%d",&n);

    for(int i=1;i <= n;i++){
        int num = i;
        while (num > 0){
            count++;
            num /= 10;
        }
    }

    printf("%d",count);

    return 0;
}