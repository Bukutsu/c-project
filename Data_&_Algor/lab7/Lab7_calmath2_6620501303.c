#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
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

void push(int data){
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

int pop(){
    int data=-1;
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

int compute(int oparand1,int oparand2,char oparator){
    int result = 0;
    switch (oparator)
    {
    case '+':
        result = oparand1 + oparand2;
        break;
    case '-':
        result = oparand1 - oparand2;
        break;
    case '*':
        result = oparand1 * oparand2;
        break;        
    case '/':
        result = oparand1 / oparand2;
        break;
    case '^':
        result = pow(oparand1,oparand2);
        break;
    default:
        break;
    }


    return result;
}

int main(){
    char input[MAXINTPUT];
    scanf("%[^\n]s",input);

    char current_char;
    int i = 0;
    while(input[i] != '\0'){
        current_char = input[i];
        //printf("oparating : %c\n",current_char);
        if(current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/' || current_char == '^'){
            int oparand2 = pop();
            int oparand1 = pop();
            push(compute(oparand1,oparand2,current_char));
            //printf("pushed : (%d X %d) = %d\n",oparand1,oparand2,compute(oparand1,oparand2,current_char));
        }
        else{
            push(current_char - '0');
            //printf("pushed : %d\n",current_char);
        }

        i++;
    }

    printf("%d",pop());


    free(top);
    return 0;
}