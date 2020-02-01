#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char value;
    struct node *next;
}node;

int main()
{
    node *head1 = (node*)malloc(sizeof(node));
    char ch;
    scanf("%c",&ch);
    head1->value=ch;
    head1->next=NULL;
    node* temp=head1;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='\n')
        {
            break;
        }
        else
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->next=NULL;
            newnode->value=ch;
            temp->next=newnode;
            temp=newnode;
        }
    
    }
    //first bit string obtained
    node *head2 = (node*)malloc(sizeof(node));
    scanf("%c",&ch);
    head2->value=ch;
    head2->next=NULL;
    temp=head2;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='\n')
        {
            break;
        }
        else
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->next=NULL;
            newnode->value=ch;
            temp->next=newnode;
            temp=newnode;
        }
    
    }
    //second bit string obtained

    int size1=0;
    int size2=0;
    node* p1=head1;
    node *p2=head2;
    while(p1!=NULL)
    {
        printf("%c",p1->value);
        size1++;
    }
    while(p2!=NULL)
    {
        printf("%c",p2->value);
        size2++;
    }

}