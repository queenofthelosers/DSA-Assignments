#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
}node;

void printans(node * ptr)
{
    if(ptr->next==NULL)
    {
        printf("%c",ptr->data);
        return;
    }
    printans(ptr->next);
    printf("%c",ptr->data);

}
char b1[1000000];
char b2[1000000];
void main()
{
    scanf("%[^\n]%*c",b1);
    scanf("%[^\n]%*c",b2);
    int l1=strlen(b1);
    int l2=strlen(b2);
    node *head1=(node *)malloc(sizeof(node));
    node *head2=(node *)malloc(sizeof(node));
    node *ptr1=head1;
    node *ptr2=head2;
    int max=0;
    if(l1>l2)
    {
        max=l1;
        for(int i=l1-1;i>0;i--)
        {
            ptr1->data=b1[i];
            ptr1->next=(node*)malloc(sizeof(node));
            ptr1=ptr1->next;
        }
        ptr1->data=b1[0];
        ptr1->next=NULL;
        for(int i=l2-1;i>=0;i--)
        {
            ptr2->data=b2[i];
            ptr2->next=(node*)malloc(sizeof(node));
            ptr2=ptr2->next;
        }
        for(int i=0;i<l1-l2-1;i++)
        {
            ptr2->data='0';
            ptr2->next=(node*)malloc(sizeof(node));
            ptr2=ptr2->next;
        }
        ptr2->data='0';
        ptr2->next=NULL;
        
    }
    else
    {
        max=l2;
        for(int i=l2-1;i>0;i--)
		{
		    ptr2->data=b2[i];
		    ptr2->next=(node*)malloc(sizeof(node));
		    ptr2=ptr2->next;
		}
		ptr2->data=b2[0];
		ptr2->next=NULL;
        for(int i=l1-1;i>0;i--)
        {
            ptr1->data=b1[i];
            ptr1->next=(node*)malloc(sizeof(node));
            ptr1=ptr1->next;
        }
        for(int i=0;i<l2-l1-1;i++)
        {
            ptr1->data='0';
            ptr1->next=(node*)malloc(sizeof(node));
            ptr1=ptr1->next;
        }
        ptr1->data='0';
        ptr1->next=NULL;
    }
    ptr1=head1;
    ptr2=head2;
    while(ptr1->next!=NULL)
    {
        printf("%c",ptr1->data);
        ptr1=ptr1->next;
    }
    printf("%c",ptr1->data);
    printf("\n");
    while(ptr2->next!=NULL)
    {
        printf("%c",ptr2->data);
        ptr2=ptr2->next;
    }
    printf("%c",ptr2->data);
    printf("\n");
    node *headans=(node*)malloc(sizeof(node));
    node *ptrh=headans;
    int carry=0;
    ptr1=head1;
    ptr2=head2;
    for(int i=0;i<max;i++)
    {
        if(ptr1->data=='1'&&ptr2->data=='1'&&carry==1)
        {
            carry=1;
            ptrh->data='1';
        }
        else if(ptr1->data=='1'&&ptr2->data=='0'&&carry==1)
        {
            carry=1;
            ptrh->data='0';
        }
        else if(ptr1->data=='0'&&ptr2->data=='1'&&carry==1)
        {
            carry=1;
            ptrh->data='0';
        }
        else if(ptr1->data=='0'&&ptr2->data=='0'&&carry==1)
        {
            carry=0;
            ptrh->data='1';
        }
        else if(ptr1->data=='1'&&ptr2->data=='1'&&carry==0)
        {
            carry=1;
            ptrh->data='0';
        }
        else if(ptr1->data=='1'&&ptr2->data=='0'&&carry==0)
        {
            carry=0;
            ptrh->data='1';
        }
        else if(ptr1->data=='0'&&ptr2->data=='1'&&carry==0)
        {
            carry=0;
            ptrh->data='1';
        }
        else if(ptr1->data=='0'&&ptr2->data=='0'&&carry==0)
        {
            carry=0;
            ptrh->data='0';
        }
        ptrh->next=(node*)malloc(sizeof(node));
        ptrh=ptrh->next;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    
    }
    if(carry==1)
    {
        ptrh->next=(node*)malloc(sizeof(node));
        ptrh=ptrh->next;
        ptrh->data='1';
        ptrh->next=NULL;        
    }
    else
        ptrh->next=NULL;
    ptrh=headans;
    while(ptrh->next!=NULL)
    {
        printf("%c",ptrh->data);
        ptrh=ptrh->next;
    }
    printf("%c",ptrh->data);
    printf("\n");
    printans(headans);
}