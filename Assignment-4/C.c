#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
char integers[1000][1000];

void swap(int a,int b)
{
    char temp[1000];
    int i=0;
    int length = strlen(integers[a]);
    while(integers[a][i]!='\0')
    {
        temp[i] = integers[a][i];
        i++;
    }
    temp[i]='\0';
    for(int i=0;i<length;i++)
    {
        integers[a][i] = integers[b][i];
    }
    for(int i=0;i<length;i++)
    {
        integers[b][i] = temp[i];
    }
}

void radixsort()
{
    int length = strlen(integers[0]);
    for(int i=length-1;i>=1;i--)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n-1;k++)
            {
                if(integers[k][i]<integers[k+1][i])
                {
                    swap(k,k+1);
                }
            }
        }
    }
    //sort by sign bit
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(integers[j][0]=='-' && integers[j+1][0]=='+')
            {
                swap(j,j+1);
            }
        }
    }
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
        if(integers[i][0]!='-')
        {
            //shift by one position and put + at 0 position
            for(int j=strlen(integers[i])-1;j>=0;j--)
            {
                integers[i][j+1] = integers[i][j];
            }
            integers[i][0]='+';
        }
    }

    //now find maximum length
    int maxlen = 0;

    for(int i=0;i<n;i++)
    {
        int length = strlen(integers[i]);
        if(length>maxlen)
        {
            maxlen = length;
        }
    }

    //maxlen has been found, now we shift right and apply zeroes at extra bits

    for(int i=0;i<n;i++)
    {
        int shifts = maxlen - strlen(integers[i]);
        for(int x = 0;x<shifts;x++)
        {
            for(int j=strlen(integers[i]);j>=0;j--)
            {
                integers[i][j+1] = integers[i][j];
            }
        }
        for(int k=1;k<=shifts;k++)
        {
            integers[i][k]='0';
        }
    }

    //now apply radix sort

    radixsort();

    for(int i=0;i<n;i++)
    {
        if(integers[i][0]=='-')
        {
            printf("-");
        }
        int zeroflag=1;
        for(int j=1;j<strlen(integers[i])-1;j++)
        {
            if(integers[i][j]!='0' && zeroflag==1)
            {
                printf("%c",integers[i][j]);
                zeroflag=0;
                continue;
            }
            if(zeroflag==0)
            {
                printf("%c",integers[i][j]);
            }
        }
        printf("%c",integers[i][strlen(integers[i])-1]);
        printf("\n");
    }
}