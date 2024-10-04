#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXINPUT 100

struct stack{
    char data;
    struct stack *next;
};

struct stack *top = NULL;

bool isEmpty()
{
    if(top == NULL)
        return true;
    else
        return false;
}


void push(char data) {
    struct stack *new_node = (struct stack*)malloc(sizeof(struct stack));
    new_node->data = data;
    new_node->next = NULL;


    if(isEmpty()){
        top = new_node;
    }else{
        new_node->next = top;
        top = new_node;
    }
}

int pop()
{
  int data=-1;
  if (isEmpty()){
    //should not reach here
  }
  else{
    struct stack *ptr = top;
    top = top->next;
    ptr->next = NULL;

    data = ptr->data;
    free(ptr);
  }
  return data;
}

int peek()
{
    if(isEmpty()){
        return -1;
    }
    else{
        return top->data;
    }


}
bool is_palindrome(char input[]){
    int i = 0;
    int input_length = strlen(input);
    int half_input_length = input_length / 2;
    while(i < half_input_length){
        if(peek() == tolower(input[i])){
            pop();
        }
        else if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') ||(input[i] >= '0' && input[i] <= '9')){
            push(tolower(input[i]));
        }
        i++;
    }

    if(input_length % 2 == 0){
        i = half_input_length;
    }
    else{
        i = half_input_length+1;
    }

    while(input[i] != '\0'){
        if(peek() == tolower(input[i])){
            pop();
        }
        else if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') ||(input[i] >= '0' && input[i] <= '9')){
            push(tolower(input[i]));
        }
        i++;

    }

    if(isEmpty()){
        return true;
    }

    return false;
}

bool is_double_palindrome(char input[]){
    int i = 0;
    int input_length = strlen(input);
    int half_input_length = input_length / 2;

    while(i < half_input_length/2){
        if(peek() == tolower(input[i])){
            pop();
        }
        else if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') ||(input[i] >= '0' && input[i] <= '9')){
            push(tolower(input[i]));
        }
        i++;
    }

    if((input_length / 2) % 2 == 0){
        i = half_input_length/2;
    }
    else{
        i = (half_input_length/2)+1;
    }

    while(i < half_input_length){
        if(peek() == tolower(input[i])){
            pop();
        }
        else if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') ||(input[i] >= '0' && input[i] <= '9')){
            push(tolower(input[i]));
        }
        i++;
    }
    

    if(isEmpty()){
        return true;
    }

    return false;
}


int main(){
    char input[MAXINPUT];
    scanf("%[^\n]s",input);
    //fgets(input,MAXINPUT,stdin);
    if(is_palindrome(input)){
        if(is_double_palindrome(input)){
            printf("Double Palindrome");
        }
        else{
            printf("Palindrome");
        }
    }
    else{
        printf("No");
    }



    return 0;
}
