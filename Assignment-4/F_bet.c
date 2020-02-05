#include<stdio.h>
#include<stdlib.h>
int n,fixed;
int array[1000];
int lesser[1000];
int greater[1000];
int lessindex;
int greaterindex;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    scanf("%d",&fixed);
    int fixedindex=-1;
    for(int i=0;i<n;i++)
    {
        if(array[i]==fixed)
        {
            fixedindex=i;
            break;
        }
    }
    int flag=0;
    for(int i=0;i<=fixedindex;i++)
    {
        if(array[i]>fixed)
        {
            flag=1;
            break;
        }
    }
    for(int i=fixedindex;i<n;i++)
    {
        if(array[i]<fixed)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("ALL SET");
    }
    else{
        for(int i=0;i<n;i++)
        {
            if(fixed>=array[i])
            {
                lesser[lessindex++] = array[i];
            }
            if(fixed<array[i])
            {
                greater[greaterindex++] = array[i];
            }
        }

        for(int i=0;i<lessindex;i++)
        {
            printf("%d ",lesser[i]);
        }
        for(int i=0;i<greaterindex;i++)
        {
            printf("%d ",greater[i]);
        }
    }
}