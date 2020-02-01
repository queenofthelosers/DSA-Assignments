#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
}node;

int main()
{
    node *head1 = (node*)malloc(sizeof(node));
    head1->next = NULL;
    head1->prev = NULL;
    scanf("%d",&head1->value);
    char x;
    scanf("%c",&x);
    node *temp = head1;
    while(x!='\n')
    {
        node *newnode = (node*)malloc(sizeof(node));
        scanf("%d",&newnode->value);
        scanf("%c",&x);
        newnode->next = NULL;
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }

    node *head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    head2->prev=NULL;
    scanf("%d",&head2->value);
    scanf("%c",&x);
    temp = head2;
    while(x!='\n')
    {
        node *newnode = (node*)malloc(sizeof(node));
        scanf("%d",&newnode->value);
        scanf("%c",&x);
        newnode->next = NULL;
        temp->next = newnode;
        newnode->prev= temp;
        temp = newnode;
    }

    node *travel1 = head1;
    node *travel2 = head2;

    node *anshead = (node*)malloc(sizeof(node));
    node *anstemp = anshead;
    if(travel1->value > travel2->value)
    {
        anstemp->value=travel2->value;
        travel2 = travel2->next;
        anstemp->next=NULL;
        anstemp->prev=NULL;
    }
    else
    {
        anstemp->value = travel1->value;
        travel1 = travel1->next;
        anstemp->next = NULL;
        anstemp->prev=NULL;
    }

    while(travel1!=NULL && travel2!=NULL)
    {
        node *n = (node*)malloc(sizeof(node));
        if(travel1->value > travel2->value)
        {
            n->value = travel2->value;
            n->next=NULL;
            n->prev=anstemp;
            anstemp->next = n;
            anstemp = n;
            travel2 = travel2->next;
        }
        else
        {
            n->value=travel1->value;
            n->next=NULL;
            n->prev = anstemp;
            anstemp->next = n;
            anstemp = n;
            travel1=travel1->next;
        }
    }

    if(travel1==NULL)
    {
  
        while(travel2!=NULL)
        {
            node *n = (node*)malloc(sizeof(node));
            n->value = travel2->value;
            n->next = NULL;
            n->prev = anstemp;
            anstemp->next = n;
            anstemp = n;
            travel2 = travel2->next;
        }
    }
    else
    {
      
        while(travel1!=NULL)
        {
            node *n = (node*)malloc(sizeof(node));
            n->value = travel1->value;
            n->next = NULL;
            n->prev = anstemp;
            anstemp->next=n;
            anstemp = n;
            travel1 = travel1->next;
        }
    }
    
    while(anshead!=NULL)
    {
        printf("%d ",anshead->value);
        anshead = anshead->next;
    }
    
    
    
}