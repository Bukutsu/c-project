#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXCHAR 100

struct node{
    char data;
    struct node *next;
};

struct node *top_text = NULL;
struct node *top_memory = NULL;

bool isEmpty(struct node *top)
{
    if(top == NULL)
        return true;
    else
        return false;
}


void push(struct node **top_ref,char data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;


    if(isEmpty(*top_ref)){
        *top_ref = new_node;
    }else{
        new_node->next = *top_ref;
        *top_ref = new_node;
    }
}

int pop(struct node **top_ref)
{
  int data=-1;
  if (isEmpty(*top_ref)){
    //should not reach here
  }
  else{
    struct node *ptr = *top_ref;
    *top_ref = (*top_ref)->next;
    ptr->next = NULL;

    data = ptr->data;
    free(ptr);
  }
  return data;
}

int peek(struct node *top)
{
    if(isEmpty(top)){
        return -1;
    }
    else{
        return top->data;
    }


}

//how? its magic!
void print_list_reversed(struct node* node) {
    if(node == NULL){
        return;
    }

    print_list_reversed(node->next);
    printf("%c", node->data);
}


int main(){
    char input[MAXCHAR];
    char result[MAXCHAR];

    do{     
        scanf("%s",input);
        //gets_s(input,MAXCHAR);
        if(strcmp(input,"WRITE") == 0){
            char to_write;
            scanf(" %c",&to_write);
            push(&top_text,to_write);
        }
        else if(strcmp(input,"UNDO") == 0){
            push(&top_memory,pop(&top_text));
        }
        else if(strcmp(input,"REDO") == 0){
            push(&top_text,pop(&top_memory));
        }
        else if(strcmp(input,"READ") == 0){
            if(top_text == NULL){
                printf("Blank document");
            }
            print_list_reversed(top_text);
            printf("\n");
        }
    }while(strcmp(input,"END") != 0);

   

    return 0;
}
