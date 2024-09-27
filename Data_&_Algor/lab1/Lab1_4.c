#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
    {
        char name[5];
        int score;
        bool pass;
    }Exam_data;

float findAVG(Exam_data *data,int count);

int main(){
    int num;
    scanf("%d",&num);
    
    Exam_data *examinee;

    examinee = malloc(num * sizeof(Exam_data));
    
    for(int i=0;i<num;i++){
        scanf("%4s",&examinee[i].name);
        scanf("%d",&examinee[i].score);
    }
    
    
    float scoretopass = findAVG(examinee,num);
    int passed = 0;

    for(int i=0;i<num;i++){
        examinee[i].pass = 0;
        if(examinee[i].score >= scoretopass){
            passed++;
            examinee[i].pass = 1;
        }
    }

    printf("%d\n",passed);

    for(int i=0;i<num;i++){
        if(examinee[i].pass == 1){
            printf("%s\n",examinee[i].name);    
        }
    }

    free(examinee);
    return 0;
}

float findAVG(Exam_data *data,int count){
    int sum = 0;
    for(int i=0;i<count;i++){
        sum += data[i].score;
    }
    return (float)sum / count;
}

