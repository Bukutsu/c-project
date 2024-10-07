#include <stdio.h>
#include<stdlib.h>
struct polynode
{
	int coef;
	int exp;
	struct polynode *next;
};
struct polynode *head1 = NULL, *head2 = NULL, *head3 = NULL;


void displayPoly(struct polynode *head)
{
    struct polynode *ptr = head;
    while(ptr != NULL){
        if(ptr->coef != 0){
            if(ptr->coef > 0 && ptr != head){
                printf("+");
            }
            if(ptr->exp == 0){
                printf("%d ",ptr->coef);
            }
            else if(ptr->exp == 1){
                if(ptr->coef == 1)
                printf("x ");
                else{
                    printf("%dx ",ptr->coef);
                }
            }
            else{
                printf("%dx^%d ",ptr->coef,ptr->exp);
            }
        }
        ptr = ptr->next;
    }
    printf("\n");
}

// Compare degree of exponential, return values are 0,1,-1
int compareExp(int e1,int e2)
{
    if(e1 > e2){
        return 1;
    }
    else if(e1 < e2){
        return -1;
    }
    return 0;
}

struct polynode* createNode(int e, int c)
{
    struct polynode *new_node;
    new_node= (struct polynode*) malloc(sizeof(struct polynode));
    new_node->exp =e;
    new_node->coef = c;
    new_node->next=NULL;
    return new_node;
}

void freeList(struct polynode *head) {
    struct polynode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;

    int n=15,i;
    int a1[] ={1,0,0,0,0,0,0,0,2,0,0,0,0,0,3};
    int a2[] ={0,0,0,0,0,0,10,0,0,0,-3,0,0,0,8};
    int ex,co;

    //create list in decreasing order add at the head
    //similar to practice
    for(i=0;i<n;i++)
    {
        new_node = createNode(i,a1[i]);
        new_node->next = head1;
        head1 = new_node;
    }

    printf("1st Polynomial: ");
    displayPoly(head1);

    for(i=0;i<n;i++)
    {
        new_node = createNode(i,a2[i]);
        new_node->next = head2;
        head2 = new_node;
    }
    printf("2nd Polynomial: ");
    displayPoly(head2);

    //add poly
    p1=head1;
    p2=head2;
    p3=head3;

    while(p1!=NULL && p2!=NULL)
    {   
        int result = 0;
        switch (compareExp(p1->exp,p2->exp))
        {
            case -1:
            new_node = createNode(p2->exp,p2->coef);
            p2 = p2->next;

            break;

            case 0: 
            result = p1->coef + p2->coef;
            if (result != 0) { 
                new_node = createNode(p1->exp, result);
            }
            p1 = p1->next;
            p2 = p2->next;
            break;
           
            case 1:
            new_node = createNode(p1->exp,p1->coef);
            p1 = p1->next;
            break;

            
        }//end switch

        //create new node and add it in the resulted polynomial
        if (new_node != NULL) {
        if (head3 == NULL) {
            head3 = new_node; // Initialize head3
            p3 = head3;       // Initialize p3 to head3
        } else {
            p3->next = new_node;
            p3 = p3->next;
        }
    }
        
    }//end while

    //check whether p1 is not null, Loop for creating new node and add it in the resulted polynomial
    while(p1 != NULL){
        new_node = createNode(p1->exp,p1->coef);
        p3->next = new_node;
        p3 = p3->next;
        p1 = p1->next;
    }


   //check whether p2 is not null, Loop for creating new node and add it in the resulted polynomial
    while(p2 != NULL){
        new_node = createNode(p2->exp,p2->coef);
        p3->next = new_node;
        p3 = p3->next;
        p2 = p2->next;
    }

    // Display resultant List
    printf("\nAdded polynomial:\n");
    displayPoly(head3);

    //free memory
    freeList(head1);
    freeList(head2);
    freeList(head3);



    return 0;
}//end main