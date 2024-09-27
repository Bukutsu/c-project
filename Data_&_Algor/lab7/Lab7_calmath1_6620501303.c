#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXINTPUT 100

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

bool isEmpty(){
    if(top == NULL)
        return true;
    else
        return false;
}

void push(char data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(isEmpty()){
        top = new_node;
    }
    else{
        new_node->next = top;
        top = new_node;
    }
}

char pop(){
    char data=-1;
    if (isEmpty()){
        //should not reach here
        printf("stack is empty");
    }
    else{
        struct node *ptr = top;
        top = top->next;
        ptr->next = NULL;

        data = ptr->data;
        free(ptr);
  }
    return data;
}

int peek(){
    if(isEmpty()){
        return -1;
    }
    else{
        return top->data;
    }


}

int main(){
    char input[MAXINTPUT];
    scanf("%[^\n]s",input);

    int i = 0;
    while(input[i] != '\0'){
        if(input[i] >= '0' && input[i] <= '9'){
            printf("%c",input[i]);
        }
        else if(input[i] == '('){
            push(input[i]);
        }
        else if(input[i] == ')'){
            while(peek() != '('){
                printf("%c",pop());
            }
            pop();
        }
        else if(input[i] == '+' || input[i] == '-'){
            while(peek() == '*' || peek() == '/' || peek() == '^' || peek() == '-' || peek() == '+'){
                printf("%c",pop());
            }
            push(input[i]);
        }
        else if(input[i] == '*' || input[i] == '/'){
            while(peek() == '^' || peek() == '*' || peek() == '/'){
                printf("%c",pop());
            }
            push(input[i]);
        }
        else if(input[i] == '^'){
            push(input[i]);
        }

        i++;
    }
    
    while(peek() != -1){
        printf("%c",pop());
    }

    free(top);
    return 0;
}