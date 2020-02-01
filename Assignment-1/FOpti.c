#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char b1[10000];
char b2[10000];

typedef struct node
{
    int value;
    struct node *next;
}node;

void equalize(char big[],char small[])
{
    int shift = strlen(big)-strlen(small);
    int smallLength = strlen(small);
    for(int i=0;i<shift;i++)
    {
        for(int i=strlen(small)-1;i>=0;i--)
        {
            small[i+1]=small[i];
        }
    }

    for(int i=0;i<shift;i++)
    {
        small[i]='0';
    }
}

void printans(node *head)
{
    if(head->next == NULL)
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
    int length;
    if(l1>l2)
    {
        equalize(b1,b2);
        length = l1;
    }
    else
    {
        equalize(b2,b1);
        length = l2;
    }
    node *head1 = (node*)malloc(sizeof(node));
    node *head2 = (node*)malloc(sizeof(node));
    head1->value = b1[length-1];
    head1->next=NULL;
    head2->value = b2[length-1];
    head2->next=NULL;

    node *temp1 = head1;
    node *temp2 = head2;

    for(int i=length-2;i>=0;i--)
    {
        node *n1 = (node *)malloc(sizeof(node));
        node *n2 = (node *)malloc(sizeof(node));
        n1->value = b1[i];
        n2->value = b2[i];
        n1->next=NULL;
        n2->next = NULL;
        temp1->next = n1;
        temp2->next = n2;
        temp1 = n1;
        temp2 = n2;
    }
    char carry='0';
    temp1 = head1;
    while(head2->next!=NULL)
    {
        char v1 = temp1->value;
        char v2 = head2->value;
        if(v1=='1' && v2=='1')
        {
            if(carry=='1')
            {
                carry='1';
                temp1->value='1';
            }
            else
            {
                carry='1';
                temp1->value='0';
            }
            
        }
        else if(v1=='0'&& v2=='0')
        {
            if(carry=='1')
            {
                carry='0';
                temp1->value = '1'; 
            }
            else
            {
                carry='0';
                temp1->value = '0';
            }
            
        }
        else
        {
            if(carry=='1')
            {
                carry='1';
                temp1->value = '0';
            }
            else
            {
                carry='0';
                temp1->value = '1';
            }
            
        }
        temp1 = temp1->next;
        head2 = head2->next;
        
    }

    char x1 = temp1->value;
    char x2 = head2->value;
    if(x1=='1' && x2=='1')
    {
        if(carry=='1')
        {
            temp1->value = '1';
            node *newnode = (node*)malloc(sizeof(node));
            temp1->next = newnode;
            newnode->value = '1';
            newnode->next = NULL;

        }
        else
        {
            temp1->value = '0';
            node *newnode = (node*)malloc(sizeof(node));
            temp1->next = newnode;
            newnode->value = '1';
            newnode->next = NULL;
        }
        
    }
    else if(x1=='0' && x2=='0')
    {
        if(carry=='1')
        {
            temp1->value = '1';
        }
        else
        {
            temp1->value='0';
        }
        
    }
    else
    {
        if(carry=='1')
        {
            temp1->value = '0';
            node *newnode = (node*)malloc(sizeof(node));
            temp1->next = newnode;
            newnode->value = '1';
            newnode->next= NULL;
        }
        else
        {
            temp1->value='1';
        }
        
    }
    
    printans(head1);
    
}