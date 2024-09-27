#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#define MAXINTPUT 100
#define MAX_VARIABLES 52

struct node{
    int data;
    struct node *next;
};
struct node *top_postfix_cal = NULL;
struct node *front_postfix = NULL;
struct node *rear_postfix = NULL;
struct node *top_cal = NULL;

bool isEmpty(struct node **top_ref);
void push(struct node **top_ref,int data);
int pop(struct node **top_ref);
int peek(struct node **top_ref);
void str_to_postfix(char *str);
void print_node(struct node **top_ref);
void enqueue(char data);
void calculate_postfix(struct node **top_ref);
int compute(int oparand1,int oparand2,char oparator);

int main(){
    printf("Enter infix:");
    char input[MAXINTPUT];
    scanf("%[^\n]s",input);

    printf("Postfix:");
    str_to_postfix(input);
    print_node(&front_postfix);
    calculate_postfix(&front_postfix);

    return 0;
}


bool isEmpty(struct node **top_ref){
    if(*top_ref == NULL)
        return true;
    else
        return false;
}

void push(struct node **top_ref,int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(isEmpty(&(*top_ref))){
        *top_ref = new_node;
    }
    else{
        new_node->next = *top_ref;
        *top_ref = new_node;
    }
    //debug
    //printf("\npushed : %c\n",data);
}

int pop(struct node **top_ref){
    int data=-1;
    if (isEmpty(&(*top_ref))){
        //should not reach here
        printf("stack underflow");
    }
    else{
        struct node *ptr = *top_ref;
        *top_ref = (*top_ref)->next;
        ptr->next = NULL;

        data = ptr->data;
        free(ptr);
  }
    //debug
    //printf("\npoped : %c",data);
    return data;
}

int peek(struct node **top_ref){
    if(isEmpty(&(*top_ref))){
        return -1;
    }
    else{
        return (*top_ref)->data;
    }
}

void str_to_postfix(char *str){
    int i = 0;
    while(str[i] != '\0'){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            enqueue(str[i]);
        }
        else if(str[i] == '('){
            push(&top_postfix_cal,str[i]);
        }
        else if(str[i] == ')'){
            while(peek(&top_postfix_cal) != '('){
                enqueue(pop(&top_postfix_cal));
            }
            pop(&top_postfix_cal);
        }
        else if(str[i] == '+' || str[i] == '-'){
            while(peek(&top_postfix_cal) == '*' || peek(&top_postfix_cal) == '/' || peek(&top_postfix_cal) == '^' || peek(&top_postfix_cal) == '-' || peek(&top_postfix_cal) == '+'){
                enqueue(pop(&top_postfix_cal));
            }
            push(&top_postfix_cal,str[i]);
        }
        else if(str[i] == '*' || str[i] == '/'){
            while(peek(&top_postfix_cal) == '^' || peek(&top_postfix_cal) == '*' || peek(&top_postfix_cal) == '/'){
                enqueue(pop(&top_postfix_cal));
            }
            push(&top_postfix_cal,str[i]);
        }
        else if(str[i] == '^'){
            while(peek(&top_postfix_cal) == '^'){
                enqueue(pop(&top_postfix_cal));
                pop(&top_postfix_cal);
            }

            push(&top_postfix_cal,str[i]);
        }
        i++;
    }

    while(peek(&top_postfix_cal) != -1){
        enqueue(pop(&top_postfix_cal));
    }
}

void print_node(struct node **top_ref){
    struct node *ptr = *top_ref;

    while(ptr != NULL){
        printf("%c",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(char data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(front_postfix == NULL){
        front_postfix = new_node;
        rear_postfix = new_node;
    }
    else{
        rear_postfix->next = new_node;
        rear_postfix = new_node;
    }
}


void calculate_postfix(struct node **top_ref) {
    char current_char;
    struct node *ptr = *top_ref;
    int assigned_values[MAX_VARIABLES] = {0};  
    int is_assigned[MAX_VARIABLES] = {0};  

    while (ptr != NULL) {
        current_char = ptr->data;
        if (current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/' || current_char == '^') {
            int operand2 = pop(&top_cal);
            int operand1 = pop(&top_cal);
            push(&top_cal, compute(operand1, operand2, current_char));
        }
        else if (isalpha(current_char)) {
            int index;
            if (islower(current_char)) {
                index = current_char - 'a';
            } else {
                index = current_char - 'A' + 26;
            }
            
            if (!is_assigned[index]) {
                printf("Enter value of %c: ", current_char);
                scanf("%d", &assigned_values[index]);
                is_assigned[index] = 1;
            }
            push(&top_cal, assigned_values[index]);
        }
        else if (isdigit(current_char)) {
            push(&top_cal, current_char - '0');
        }
        ptr = ptr->next;
    }
    printf("Result = %d\n", pop(&top_cal));
}

int compute(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return (int)pow(operand1, operand2);
        default:  return 0;  // Error case
    }
}

