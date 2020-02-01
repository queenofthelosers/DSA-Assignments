#include<stdio.h>
#include<stdlib.h>

void sort(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(array[j+1]>array[j])
            {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int array[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);   
    }
    array[n]=INT_MIN;
    sort(array,n);
    int comp = array[0];
    int maxnum;
    int count1=0,maxfreq=0;
    for(int i=0;i<n+1;i++)
    {
        if(array[i]==comp)
        {
            count1++;
        }
        else
        {
            comp = array[i];
            if(count1>maxfreq)
            {
                maxfreq=count1;
                maxnum = array[i-1];
            }
            count1=1;
        }        
    }
    int required_frequency;
    if(n%2==0)
    {
        required_frequency=n/2;
    }
    else
    {
        required_frequency=n/2 +1;
    }
    
    
    if(maxfreq>=required_frequency)
    {
        printf("%d",maxnum);
    }
    else
    {
        printf("NO MAJORITY ELEMENT");
    }
    
    
}