#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    char value;
    struct node *next;
}node;
node *head1=NULL;
node *head2=NULL;
node *ans = NULL;

void reverse()
{
    node *current=head1;
    node *prev1=NULL;
    node *nextnode;
    while(current!=NULL)
    {
        nextnode=current->next;
        current->next=prev1;
        prev1=current;
        current=nextnode;
    }
    head1=prev1;
    current =head2;
    node *prev2=NULL;
    while(current!=NULL)
    {
        nextnode=current->next;
        current->next=prev2;
        prev2=current;
        current=nextnode;
    }
    head2=prev2;
}

void add(int greater)
{
    if(greater==1)
    {
        char carry='0';
        node *temp = head1;
        while(head2!=NULL)
        {
            char val1 = temp->value;
            char val2 = head2->value;
            if(val1=='1' && val2=='1')
            {
                if(carry=='1')
                {
                    temp->value='1';
                    carry='1';
                }
                else
                {
                    temp->value='0';
                    carry='1';
                }
                
            }
            else if(val1=='0' && val2=='0')
            {
                if(carry=='1')
                {
                    temp->value='1';
                    carry='0';
                }
                else
                {
                    temp->value='0';
                    carry='0';
                }
                
            }
            else
            {
                if(carry=='1')
                {
                    temp->value='0';
                    carry='1';
                }
                else
                {
                    temp->value='1';
                    carry='0';
                }
                
            }
            head2=head2->next;
            temp=temp->next;
        }

        while(temp->next!=NULL)
        {
            char val = temp->value;
            if(val=='1' && carry=='1')
            {
                temp->value='0';
                carry='1';
            }
            else if(val=='0' && carry=='1')
            {
                temp->value='1';
                carry='0';
            }
            else if (val=='1' && carry=='0')
            {
                temp->value='1';
                carry='0';
            }
            else
            {
                temp->value='0';
                carry='0';
            }
            
            
            temp=temp->next;
        }
        char x=temp->value;
        if(x=='1' && carry=='1')
        {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->next=NULL;
            temp->value='0';
            newnode->value='1';
            temp->next=newnode;
        }
        else if(x=='1' && carry=='0')
        {
            temp->value='1';
            carry='0';
        }
        else if(x=='0' && carry=='1')
        {
            temp->value='1';
            carry='0';
        }
        else
        {
            temp->value='0';
            carry='0';
        }
        
        
        
    }

    if(greater==2)
    {
        char carry='0';
        node *temp = head1;
        while(head2!=NULL)
        {
            char val1 = temp->value;
            char val2 = head2->value;
            if(val1=='1' && val2=='1')
            {
                if(carry=='1')
                {
                    temp->value='1';
                    carry='1';
                }
                else
                {
                    temp->value='0';
                    carry='1';
                }
                
            }
            else if(val1=='0' && val2=='0')
            {
                if(carry=='1')
                {
                    temp->value='1';
                    carry='0';
                }
                else
                {
                    temp->value='0';
                    carry='0';
                }
                
            }
            else
            {
                if(carry=='1')
                {
                    temp->value='0';
                    carry='1';
                }
                else
                {
                    temp->value='1';
                    carry='0';
                }
                
            }
            head2=head2->next;
            temp=temp->next;
        }
        

    }
    
}

int main()
{
    head1 = (node*)malloc(sizeof(node));
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
    head2 = (node*)malloc(sizeof(node));
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

   reverse();
   //both bit strings have been reversed
    node *h1 = head1;
    node *h2 = head2;
    int size1=0;
    int size2=0;
    while(h1!=NULL)
    {
        size1++;
        h1=h1->next;
    }
    while(h2!=NULL)
    {
        size2++;
        h2=h2->next;
    }
    if(size1>size2)
    {
        add(1);
        reverse();
        while(head1!=NULL)
        {
            printf("%c",head1->value);
            head1=head1->next;
        }
    }
    else if(size2>size1)
    {
        add(0);
        //print head2
    }
    else
    {
        add(2);
    }
    
    
}