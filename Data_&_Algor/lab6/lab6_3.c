#include <stdio.h>
#define maxsize  10
int Q[maxsize]={0};
int Front=-1, Rear=-1;
int size=0;

void enqueue(int);
void dequeue();
void displayQ();

int main()
{
    char input[100];
    fgets(input,100,stdin);

    int i = 0;
    while(input[i] != '\0'){
        
        if(input[i] >= 'A' && input[i] <= 'Z'){
            enqueue(input[i]);
        }
        else if(input[i] >= '1' && input[i] <= '9'){
            int num = input[i] - '0';
            for(int j = 0;j<num;j++){
                dequeue();
            }
        }
        else if(input[i] == '0'){
            printf("%d%d",Front,Rear);
        }

        
        i++;
    }

    return 0;
}

void enqueue(int data){
    if(size == maxsize)
        printf("!");
    else{
        if(Front == -1 && Rear == -1){
            Front = 0;
            Rear = 0;
        }
        else{
            Rear = (Rear + 1) % maxsize;
        }
        Q[Rear] = data;
        size++;
    }
}

void dequeue(){
    if(size == 0){
        printf("!");
    }
    else{
        printf("%c",Q[Front]);
        Front = (Front + 1) % maxsize;
        size--;
    }
}

void displayQ(){
    int i;
    if(size == 0){
        printf("!");
    }
    else{
        printf("front[ ");
        for(i = Front;i<size+Front;i++){
            printf("%d ",Q[i % maxsize]);
        }
        printf("]rear\n");
    }
}
