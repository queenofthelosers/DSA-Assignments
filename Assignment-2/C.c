#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int value;
    struct node *next;
}node;
int listindex=0;
int process(char instruction[])
{
    if(strlen(instruction)==3)
    {
        //instruction is add
        return 1;
    }
    else if(strlen(instruction)==5)
    {
        //instruction is fetch
        return 2;
    }
    else if(strlen(instruction)==6)
    {
        //could be insert or remove
        if(instruction[0]=='r')
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
    else
    {
        return 5;
    }
}

void printlist(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

node *reverselist(node *head)
{
    node *current = head;
    node *prev = NULL;
    node  *nextnode;
    while(current!=NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
    return head;
}

node * machine(node *head,int process_code)
{
    if(process_code==1) //add a value
    {
        node *temp = head;
        
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        node *n = (node*)malloc(sizeof(node));
        scanf("%d",&n->value);
        n->next = NULL;
        temp->next = n;
        listindex++;
        printlist(head);
        printf("\n");
    }
        
    

    else if(process_code==2) //to fetch
    {
        int position;
        scanf("%d",&position);
        if(position>listindex)
        {
            printf("ELEMENT NOT FOUND\n");
        }
        else
        {
            node *temp = head;
            for(int i=1;i<position;i++)
            {
                temp=temp->next;
            }
            printf("%d\n",temp->value);
        }
        
    }
    
    else if(process_code==3) //remove first and last occurrence of number
    {
        int num;
        scanf("%d",&num);
        node *temp = head;
        node *previous;
        int flag1=0;
        int flag2=0;
        while(temp!=NULL)
        {
            if(temp->value==num)
            {
                if(temp==head)
                {
                    head = temp->next;
                }
                else
                {
                    previous->next = temp->next;
                }
                flag1=1;
                break;
            }
            previous = temp;
            temp = temp->next;
        }

        head = reverselist(head);
        temp = head;
        while(temp!=NULL)
        {
            if(temp->value==num)
            {
                if(temp==head)
                {
                    head = temp->next;
                }
                else
                {
                    previous->next = temp->next;
                }
                break;
                flag2=1;
            }
            previous = temp;
            temp = temp->next;
        }
        head = reverselist(head);

        if(flag1==0 && flag2==0)
        {
            printf("ELEMENT NOT FOUND\n");
        }
        else
        {
            listindex-=2;
            printlist(head);
            printf("\n");
        }
        
        
    }

    else if(process_code==4) //insert y at position x
    {
        int y,x;
        scanf("%d %d",&y,&x);
        node *n = (node*)malloc(sizeof(node));
        n->value=y;
        if(x==1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            node *temp = head;
            node *prev;
            for(int i=1;i<x;i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next=n;
            n->next=temp;
            
        }   
        listindex++;
        printlist(head);
        printf("\n");
    }

    else
    {
        head = reverselist(head);
        printlist(head);
        printf("\n");
    }
    
    return head;
    
}


int main()
{
    int n;
    scanf("%d",&n);
    node *head = (node*)malloc(sizeof(node));
    char firstins[1000];
    scanf("%s",firstins);
    int pcode = process(firstins);
    if(pcode!=1)
    {
        printf("NO ELEMENTS\n");
    }
    else
    {
        listindex++;
        scanf("%d",&head->value);
        head->next = NULL;
        printlist(head);
        printf("\n");
    }
    
    for(int i=0;i<n-1;i++)
    {
        char ins[1000];
        scanf("%s",ins);
        int process_code = process(ins);
        head = machine(head,process_code);     
        
    }
    
    
}