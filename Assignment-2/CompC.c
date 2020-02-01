#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int listindex = 0;

typedef struct node
{
	int value;
	struct node *next;
}node;

void printlist(node *head)
{
	node *temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->value);
		temp = temp->next;
	}
	printf("\n");
}

node *add(node *head, int value)
{
	node *temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	node *n = (node*)malloc(sizeof(node));
	n->next = NULL;
	n->value = value;
	temp->next =n;
	listindex++;
	return head;
}

node *insert(node *head, int value,int position)
{
	node *n = (node*)malloc(sizeof(node));
	if(position==1)
	{
		n->value = value;
		n->next = head;
		head =n;
	}
	else if(position>listindex)
	{
		printf("OUT OF BOUNDS\n");
	}
	else
	{
		node *temp = head;
		node *previous;
		for(int i=1;i<position;i++)
		{
			previous = temp;
			temp = temp->next;
		}
		previous->next = n;
		n->value = value;
		n->next = temp;
		
	}
	listindex++;
	return head;
}

node *reverse(node* head)
{
	node *current = head;
	node *nextnode;
	node *prev = NULL;
	while(current!=NULL)
	{
		nextnode = current->next;
		current->next = prev;
		prev = current;
		current = nextnode;
	}
	head = prev;
	return prev;
}

node *removeTwo(node *head, int value)
{
	int remflag1=0,remflag2=0;
	node *temp = head;
	if(temp->value == value)
	{
		head = head->next;
	}
	else
	{
		node *temp = head;
		node *previous;
		while(temp!=NULL)
		{
			if(temp->value==value)
			{
				if(temp==head)
				{
					head = head->next;
				}
				else
				{
					previous->next = temp->next;
				}
				remflag1=1;
				listindex--;
				break;
			}
			previous = temp;
			temp = temp->next;
		}
		head = reverse(head);
		temp = head;
		while(temp!=NULL)
		{
			if(temp->value == value)
			{
				if(temp==head)
				{
					head = head->next;
				}
				else
				{
					previous->next = temp->next;
				}
				remflag2 =1;
				listindex--;
				break;
			}
			previous = temp;
			temp = temp->next;
		}

		head = reverse(head);
		if(remflag2==0 && remflag1==0)
		{
			printf("NO SUCH ELEMENT\n");
		}
		else
		{
			printlist(head);
		}

	}
	return head;
}

node *fetch(node *head, int position)
{
	node *temp = head;
	for(int i=1;i<position;i++)
	{
		temp = temp->next;
	}
	printf("%d\n",temp->value);
	return head;
}


int main()
{
	int n;
	scanf("%d",&n);
	char firstinst[1000];
	scanf("%s",firstinst);
	node *head = (node*)malloc(sizeof(node));
	int addflag=0;
	if(strcmp(firstinst,"add")==0)
	{
		scanf("%d",&head->value);
		head->next = NULL;
		listindex++;
		head->next = NULL;
		printf("%d\n",head->value);
	}
	else
	{
		printf("No Elements\n");
	}

	
	for(int i=1;i<n;i++)
	{
		char instruction[1000];
		scanf("%s",instruction);
    	if(strcmp(instruction,"add")==0)
		{
			int value;
			scanf("%d",&value);
			head = add(head,value);
			printlist(head);
			
		}
		else if(strcmp(instruction,"insert")==0)
		{
			int value,position;
			scanf("%d %d",&value,&position);
			head = insert(head,value,position);
			printlist(head);
		}
		else if(strcmp(instruction,"remove")==0)
		{
			int value;
			scanf("%d",&value);
			head = removeTwo(head,value);

		}
		else if(strcmp(instruction,"reverse")==0)
		{
			head = reverse(head);
			printlist(head);
		}
		else
		{
			int lindex;
			scanf("%d",&lindex);
			head = fetch(head,lindex);
			//print the value in the function
		}
	}

	
	
}

	
