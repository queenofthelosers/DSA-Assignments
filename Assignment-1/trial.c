#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int value;
    struct node *next;
}node;
char b1[1000];
char b2[1000];

void printans(node *head)
{
    if(head->next==NULL)
    {
        printf("%c",head->value);
        return;
    }
    printans(head->next);
    printf("%c",head->value);
}
int main()
{
    scanf("%[^\n]%*c",b1);
    scanf("%[^\n]%*c",b2);
    int l1 = strlen(b1);
    int l2 = strlen(b2);
    node *head1= (node *)malloc(sizeof(node));
    node *head2 = (node *)malloc(sizeof(node));
    head1->next=NULL;
    head2->next=NULL;
    head1->value=b1[l1-1];
    head2->value=b2[l2-1];
    node *temp1 = head1;
    node *temp2 = head2;
    if(l1>l2)
    {
        for(int i=l1-2;i>=0;i--)
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->value=b1[i];
            newnode->next = NULL;
            temp1->next = newnode;
            temp1 = newnode;
        }

        for(int i=l2-2;i>=0;i--)
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->value = b2[i];
            newnode->next = NULL;
            temp2->next = newnode;
            temp2 = newnode;
        }

        int shift = l1-l2;
        for(int i=0;i<shift;i++)
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->value = '0';
            newnode->next=NULL;
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    else
    {
        for(int i=l2-2;i>=0;i--)
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->value=b2[i];
            newnode->next = NULL;
            temp2->next = newnode;
            temp2 = newnode;
        }

        for(int i=l1-2;i>=0;i--)
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->value = b1[i];
            newnode->next = NULL;
            temp1->next = newnode;
            temp1 = newnode;
        }

        int shift = l2-l1;
        for(int i=0;i<shift;i++)
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->value = '0';
            newnode->next=NULL;
            temp1->next = newnode;
            temp1 = newnode;
        }
    }
    
    node *t1 = head1;
    node *t2 = head2;
    // while(head1!=NULL)
    // {
    //     printf("%c",head1->value);
    //     head1 = head1->next;
    // }
    // printf("\n");
    // while(head2!=NULL)
    // {
    //     printf("%c",head2->value);
    //     head2 = head2->next;
    // }
    char carry='0';
    while(head2->next!=NULL)
    {
        char v1 = t1->value;
        char v2 = head2->value;
        if(v1=='1' && v2=='1')
        {
            if(carry=='1')
            {
                carry='1';
                t1->value = '1';
            }
            else
            {
                carry='1';
                t1->value='0';
            }   
        }

        else if(v1=='0' && v2=='0')
        {
            if(carry=='1')
            {
                t1->value='1';
                carry=-'0';
            }
            else
            {
                t1->value='0';
                carry='0';
            }
            
        }

        else
        {
            if(carry=='1')
            {
                t1->value='0';
                carry='1';
            }
            else
            {
                t1->value='1';
                carry='0';
            }
            
        }
        t1=t1->next;
        head2 = head2->next;
    }
    char v1 = t1->value;
    char v2 = head2->value;
    if(v1=='1' && v2=='1')
    {
        if(carry=='1')
        {
            node *n = (node*)malloc(sizeof(node));
            n->value='1';
            t1->value = '1';
            t1->next = n;
            n->next=NULL;
        }
        else
        {
            node *n = (node*)malloc(sizeof(node));
            n->value='1';
            t1->value='0';
            t1->next=n;
            n->next=NULL;
        }
        
    }
    else if(v1=='0' && v2=='0')
    {
        if(carry=='1')
        {
            t1->value='1';
            carry='0';
        }
        else
        {
            t1->value='0';
            carry='0';
        }
        
    }
    else
    {
        if(carry=='1')
        {   
            t1->value='0';
            node *n = (node*)malloc(sizeof(node));
            t1->next=n;
            n->next=NULL;
            n->value='1';
            carry='0';
        }
        else
        {
            t1->value='1';
            carry='0';
        }
        
    }

    printans(head1);
    
}