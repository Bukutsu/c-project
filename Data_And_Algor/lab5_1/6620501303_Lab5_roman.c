#include <stdio.h>
#define MAX_SIZE 5

int hash_table[MAX_SIZE];

int hash_function(char key)
{
    if(key == 'I')return 0;
    else if(key == 'V') return 1;
    else if(key == 'X') return 2;
    else if(key == 'L') return 3;
    else if(key == 'C') return 4;
    return -1;
}

void insert_to_hash(int number){
    while(number > 0){
        if(number >= 100){
            hash_table[hash_function('C')]++;
            number -= 100;
        }
        else if(number >= 50){
            if(number >= 90){
                hash_table[hash_function('X')]++;
                hash_table[hash_function('C')]++;
                number -= 90;
            }
            else{
                hash_table[hash_function('L')]++;
                number -= 50;
            }
        }
        else if(number >= 10){
            if(number >= 40){
                hash_table[hash_function('X')]++;
                hash_table[hash_function('L')]++;
                number -= 40;
            }
            else{
                hash_table[hash_function('X')]++;
                number -= 10;
            }
        }
        else if(number >= 5){
            if(number >= 9){
                hash_table[hash_function('X')]++;
                hash_table[hash_function('I')]++;
                number -= 9;
            }
            else{
                hash_table[hash_function('V')]++;
                number -= 5;
            }
        }
        else if(number >= 1){
            if(number >= 4){
                hash_table[hash_function('V')]++;
                hash_table[hash_function('I')]++;
                number -= 4;
            }
            else{
                hash_table[hash_function('I')]++;
                number--;
            }
            
        }
    }
}

int main(){
    int input;
    scanf("%d",&input);
    
    while(input > 0){
        insert_to_hash(input);
        input--;
    }

    for(int i=0;i<=4;i++){
        printf("%d ",hash_table[i]);
    }

    return 0;
}
