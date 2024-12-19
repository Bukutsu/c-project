//1.3 : Best case would occur when the finding number is already in the middle and time complexity would be O(1)
//1.4 : Worst case would occur when their is no finding number in the array and time complexity would be O(logn)
#include <stdio.h>
#include <stdbool.h>

bool binary_search(int list[],int min, int max, int key){

    if (max < min){
        return false;
    }
    else{
        int mid = (max+min) / 2;
        if (list[mid] > key) {
            return binary_search(list,min,mid - 1,key);
        }
        else if (list[mid] < key){
            return binary_search(list,mid+1,max,key);
        }
        else return mid;
    }


}

int main(int argc, char const *argv[])
{
    int array[] = {2, 2,3 ,5 ,7 ,9 ,10 ,27};
    int n = sizeof(array)/sizeof(array[0]);
    int num;

    printf("Enter n:");
    scanf("%d",&num);

    if(binary_search(array,0,n-1,num)){
        printf("Found");
    }else{
        printf("Not Found");
    }

    return 0;
}
