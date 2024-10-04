#include <stdio.h>
#include <stdbool.h>
#define maxsize  5

int S[maxsize]={0};
int Top=-1;

...... isEmpty()
{
    if(       )
        return true;
    else
        return false;
}

....... isFull()
{
    if(    )
        return true;
    else
        return false;
}

...... push( data) {

    if (  )
    printf ( "\nStack is full\n" );
    else
    {

    }

}

........ pop()
{
  int data=-1;
  if (     )
     printf("\nStack is Empty\n");
  else{

  }
  return .....;
}

....... peek()
{


}
........ display()
{
  int i;
  if (     )
      printf("\nStack is Empty\n");
  else{


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
            if(isFull())
                printf("\nStack is Full\n");
            else
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
