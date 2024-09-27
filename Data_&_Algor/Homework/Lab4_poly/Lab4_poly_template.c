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

}
// Compare degree of exponential, return values are 0,1,-1
int compareExp(int e1,int e2)
{

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

int main()
{
    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;

    int n=5,i;
    int a1[] ={6,2,3,8,0};
    int a2[] ={3,18,0,0,23};
    int ex,co;

    //create list in decreasing order add at the head
    //similar to practice
    for(i=0;i<n;i++)
    {

    }
    printf("1st Polynomial: ");
    displayPoly(head1);

    for(i=0;i<n;i++)
    {

    }
    printf("2nd Polynomial: ");
    displayPoly(head2);

    //add poly
    p1=head1;
    p2=head2;
    p3=head3;

    while(p1!=NULL && p2!=NULL)
    {
        switch (compareExp(p1->exp,p2->exp))
        {


        }//end switch

        //create new node and add it in the resulted polynomial

    }//end while

    //check whether p1 is not null, Loop for creating new node and add it in the resulted polynomial


   //check whether p2 is not null, Loop for creating new node and add it in the resulted polynomial


    // Display resultant List
    printf("\nAdded polynomial: ");
    displayPoly(head3);

    //free memory
    return 0;
}//end main
