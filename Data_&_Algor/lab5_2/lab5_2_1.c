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

    if(hashArray[index] == 0){
        hashArray[index] = n;
    }else{
        printf("Cannot insert, H[%d] is not empty!\n",index);
    }

}
int main()
{
    int n,h;
    do{
        printf(" Enter number:");
        scanf("%d",&n);
        if(n>=1)
        setHash(n);
}while(n>=1);


//display hash table
for (h = 0; h < HTsize; h++)
printf("%d [%d]\n", h,hashArray[h]);

return 0;
}
