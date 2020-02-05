#include<stdio.h>
#include<stdlib.h>

int indexer[10000];
int array[10000];
int frequency[1000];
int sorted_arr[1000];
int ansarray[1000];

void countsort(int arr[],int size)
{
    int arrindex=0;
    for(int i=0;i<1000;i++)
    {
        while(frequency[i]!=0)
        {
            sorted_arr[arrindex++] = i;
            frequency[i]--;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
        indexer[array[i]]=i;
        frequency[array[i]]++;
    }
    int e;
    scanf("%d",&e);
    countsort(array,n);

    int sum=0;
    int ansindex=0;
    for(int i=0;i<n;i++)
    {
        sum+=sorted_arr[i];
        ansarray[ansindex]=sorted_arr[i];
        ansindex++;
        if(sum>=e)
        {
            break;
        }
    }
    if(ansindex==0)
    {
        printf("NO CHANCE");
    }

    else
    {
        for(int i=0;i<ansindex;i++)
        {
            int v = ansarray[i];
            int index=0;
            for(int j=0;j<n;j++)
            {
                if(v==array[j])
                {
                    array[j]=-1;
                    index=j+1;
                    break;
                }
            }
            printf("%d ",index);
        }
    }
}