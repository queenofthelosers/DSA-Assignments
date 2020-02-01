#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int main()
{
    node *head = (node*)malloc(sizeof(node));
    int v;
    scanf("%d",&v);
    head->data=v;
    head->next=NULL;
    char x;
    scanf("%c",&x);
    node *temp=head;
    while(x!='\n')
    {
        scanf("%d",&v);
        scanf("%c",&x);
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data=v;
        newnode->next=NULL;
        temp->next = newnode;
        temp=newnode;
    }

    //given that it is sorted, delete the duplicates

    node *travel1;
    node *travel2;
    travel1 = head;
    travel2 = head->next;
    while(travel1->next!=NULL)
    {
        if(travel1->data == travel2->data)
        {
            travel1->next = travel2->next;
            travel2 = travel2->next;
        }
        else
        {
            travel1=travel1->next;
            travel2=travel2->next;
        }
        
    }

    int counter=0;
    node *countnode=head;
    while(countnode!=NULL)
    {
        counter++;
        countnode=countnode->next;
    }
    printf("%d\n",counter);
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
   
}