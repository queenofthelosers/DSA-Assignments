#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char integers[1000][1000];
char temp[1000];
int n;
void swap(int i, int j)
{
    strcpy(temp,integers[i]);
    strcpy(integers[i],integers[j]);
    strcpy(integers[j],temp);
}
int compareNeg(int i,int j)
{
    for(int a=1;a<strlen(integers[i]);a++)
    {
        if(integers[i][a]>integers[j][a])
        {
            return 1;
        }
        else if(integers[i][a]<integers[j][a])
        {
            return 0;
        }
        else
        {
            continue;
        }
        
        
    }
    return 0;
}

int comparePos(int i,int j)
{
    for(int a=0;a<strlen(integers[i]);a++)
    {
        if(integers[i][a]<integers[j][a])
        {
            return 1;
        }
        else if(integers[i][a]>integers[j][a])
        {
            return 0;
        }
        else
        {
            continue;
        }
        
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",integers[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(integers[i][0]=='-' && integers[j][0]=='-')
            {
                if(strlen(integers[i])>strlen(integers[j]))
                {
                    swap(i,j);
                }
                if(strlen(integers[i])==strlen(integers[j]))
                {
                    if(compareNeg(i,j)==1)
                    {
                        swap(i,j);
                    }
                }
            }
            else if(integers[i][0]=='-')
            {
                swap(i,j);
            }
            else if(integers[j][0]=='-')
            {

            }
            else
            {
                if(strlen(integers[j])>strlen(integers[i]))
                {
                    swap(i,j);
                }
                if(strlen(integers[i])==strlen(integers[j]))
                {
                    if(comparePos(i,j)==1)
                    {
                        swap(i,j);
                    }
                }
            }
            
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%s\n",integers[i]);
    }

}