#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

void split(node *src, node **frontref, node **backref)
{
    node *fast = src->next;
    node *slow = src;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *frontref = src;
    *backref = slow->next;
    slow->next=NULL;
}

node *merge(node *a, node *b)
{
    node *result = NULL;
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    if(a->value<=b->value)
    {
        result = a;
        result->next = merge(a->next,b);
    }
    else
    {
        result = b;
        result->next = merge(a,b->next);
    }
    
}
void mergesort(node **headref)
{
    node *head = *headref;
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    node *a;
    node *b;
    split(head,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *headref = merge(a,b);
}
int main()
{
    node *head = (node*)malloc(sizeof(node));
    char x;
    scanf("%d",&head->value);
    scanf("%c",&x);
    head->next=NULL;
    node *temp=head;
    while(x!='\n')
    {
        node *newnode = (node*)malloc(sizeof(node));
        scanf("%d",&newnode->value);
        scanf("%c",&x);
        temp->next=newnode;
        newnode->next=NULL;
        temp=newnode;
    }
    mergesort(&head);

    while(head!=NULL)
    {
        printf("%d ",head->value);
        head = head->next;
    }
}