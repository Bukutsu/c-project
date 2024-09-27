#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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


int main()
{
    char input[100];
    fgets(input,100,stdin);
    int count = 0;
    int i = 0;
    while(input[i] != '\0'){
        if(input[i] == '{' || input[i] == '[' || input[i] == '('){
            push(input[i]);
            count++;
        }
        else if(input[i] == '}'){
            if(peek() == '{'){
                pop();
                count--;
            }
            else{
                printf("-1");
                return 0;
            }
        }
        else if(input[i] == ']'){
            if(peek() == '['){
                pop();
                count--;
            }
            else{
                printf("-1");
                return 0;
            }
        }
        else if(input[i] == ')'){
            if(peek() == '('){
                pop();
                count--;
            }
            else{
                printf("-1");
                return 0;
            }
        }
        i++;
    }

    if(isEmpty()){
        printf("0");
    }
    else{
        printf("%d",count);
    }


    return 0;
}
