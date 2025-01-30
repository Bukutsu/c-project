//6620501303 Kongyut Klongklaew 712
//Time Complexity would be O(N) because it would have to iterate through all activity.
#include <stdio.h>
#include <stdlib.h>
struct activity
{
    int id;
    int si;
    int fi;
};

int compare(const void* a, const void* b)
{
    return ((struct activity*)a)->fi
           - ((struct activity*)b)->fi;
}

void print_activity_selection(struct activity A[],int n){

    printf("\nActivities are selected n : ");

    int j = 0;
    printf("%d ",A[0].id + 1);
    for(int i = 1;i < n; i++){
        if(A[i].si >= A[j].fi){
            printf("%d ",(A[i].id) + 1);

            j = i;
        }
    }

}



int main(){
    int n;

    printf("Input number of Activity (n) = ");
    scanf("%d",&n);

    struct activity arr[n];

    for(int i = 0; i<n; i++){

        int s , f;
        printf("Input Enter S and F of Activity %d =  ",i+1);
        scanf("%d %d", &s, &f);

        arr[i].id = i;
        arr[i].si = s;
        arr[i].fi = f;
    }

    qsort(arr, n, sizeof(struct activity), compare);
    for(int i = 0; i<n; i++){

        printf("Act %d: %d - %d " ,arr[i].id + 1, arr[i].si, arr[i].fi );
    }





    print_activity_selection(arr,n);

}
