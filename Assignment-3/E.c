#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

int main()
{
    node *head = (node*)malloc(sizeof(node));
    scanf("%d",&head->value);
    head->next= NULL;
    char x;
    scanf("%c",&x);
    node *temp = head;
    while(x!='\n')
    {
        node *newnode = (node*)malloc(sizeof(node));
        scanf("%d",&newnode->value);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        scanf("%c",&x);
    }
    //last node will be in temp
    temp = head->next;
    node *toptemp=head;
    while(temp->next!=NULL)
    {
        node *bottomtemp=head;
        node *previous;
        while(bottomtemp->next!=NULL)
        {
            previous = bottomtemp;
            bottomtemp=bottomtemp->next;
        }
        toptemp->next = bottomtemp;
        bottomtemp->next = temp;
        toptemp = temp;
        previous->next = NULL;

        if(temp->next!=NULL)
        {
            temp = temp->next;
        }
        else
        {
            break;
        } 
    }

    node *printer = head;
    while(printer!=NULL)
    {
        printf("%d ",printer->value);
        printer= printer->next;
    }
}