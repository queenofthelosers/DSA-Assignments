#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
}node;

node *rotate(node *head, int k, char dir)
{
    if(dir=='R')
    {
        for(int i=0;i<k;i++){
            node *temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            //reached last node;
            node *newlast = temp->prev;
            newlast->next=NULL;
            node *newhead = (node*)malloc(sizeof(node));
            newhead->value=temp->value;
            newhead->prev=NULL;
            newhead->next=head;
            head = newhead;
        }

    }
    else
    {
        for(int i=0;i<k;i++)
        {
            node *temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            node *newlast = (node*)malloc(sizeof(node));
            newlast->value=head->value;
            newlast->next=NULL;
            temp->next=newlast;
            newlast->prev=temp;
            node *newhead = head->next;
            newhead->prev=NULL;
            head=newhead;
        }
    }
    return head;
}

int main()
{
    node *head = (node*)malloc(sizeof(node));
    scanf("%d",&head->value);
    head->next=NULL;
    head->prev=NULL;
    char x;
    scanf("%c",&x);
    node *temp = head;
    while(x!='\n')
    {
        node *newnode = (node*)malloc(sizeof(node));
        scanf("%d",&newnode->value);
        scanf("%c",&x);
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;
    }
 
    int k;
    char rot;
    scanf("%d %c",&k,&rot);
    head = rotate(head,k,rot);
    while(head!=NULL)
    {
        printf("%d ",head->value);
        head=head->next;
    }
    
}