#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct stack{
    int data;
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


void push(int data) {
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
  if (isEmpty())
     printf("\nStack is Empty\n");
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
        printf("\nStack is Empty\n");
        return -1;
    }
    else{
        return top->data;
    }


}
void display()
{
    if(isEmpty()){
        printf("\nStack is Empty\n");
    }
    else{
        struct stack *ptr = top;
        while(ptr != NULL){
            printf("\n%d",ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
   int item, option;

   do
   {
      printf("\n *****MAIN MENU*****");
      printf("\n 1. PUSH");
      printf("\n 2. POP");
      printf("\n 3. PEEK");
      printf("\n 4. DISPLAY");
      printf("\n 5. EXIT");
      printf("\n Enter your option: ");
      scanf("%d", &option);

     switch(option)
     {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &item);
            //if(isFull())
            //    printf("\nStack is Full\n");
            //else
                push(item);
        break;

        case 2:
            if(isEmpty())
               printf("\nStack is Empty\n");
            else
            {
                 item = pop();
                 printf("\n The value deleted from stack is: %d", item);
            }
        break;

        case 3:
            item=peek();
            if (item != -1)
               printf("\n The value stored at top of stack is: %d", item);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Bye ...\n"); break;

        default: printf("Unknown option\n"); break;

     }//end switch
   }while(option !=5);
  return 0;
}
