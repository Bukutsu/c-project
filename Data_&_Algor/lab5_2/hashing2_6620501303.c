#include <stdio.h>
#define HTsize 10
int hashArray[HTsize]={0}; //hash table

int h(int k) //for generate hash function
{
    return k%HTsize;
}

void setHash(int n) //for insert number in hash table
{
    int index;
    index=h(n); //call genHashFn

    printf(" %d mod %d = %d\n",n,HTsize,n % HTsize);

    int i = 1;
    while(hashArray[index] != 0){
        if(n == hashArray[index]){
            printf("Duplicate number!\n");
            return;
        }


        printf(" (%d + %d) mod %d = %d\n",n % HTsize,i*i,HTsize,((n % HTsize)+ i*i) % HTsize);
        index = h(h(n) + i*i);
        i++;
        count++;

    }

    hashArray[index] = n;
    printf(" Put %d in H[%d]\n",n,index);

}



int main()
{
    int n,h;
    int count = 0;
    do{
        printf(" Enter number:");
        scanf("%d",&n);
        if(count >= HTsize){
        printf("Hash Table is full!\n");
        break;
        }

        count++;
        if(n>=1)
        setHash(n);
}while(n>=1);


//display hash table
for (h = 0; h < HTsize; h++)
printf("%d [%d]\n", h,hashArray[h]);

return 0;
}
