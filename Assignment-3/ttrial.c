#include<stdio.h>
#include<stdlib.h>
int numbers[1000];
int n;
int subset[1000];
int subsetindex;
int answer[1000];
int ansindex;
void sort(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void reset(int array[])
{
    for(int i=0;i<1000;i++)
    {
        array[i]=0;
    }
}

int check()
{
    int zeroflag=0;
    for(int i=0;i<subsetindex;i++)
    {
        if(subset[i]==0)
        {
            zeroflag=1;
            break;
        }
    }
    int digsum=0;
    for(int i=0;i<subsetindex;i++)
    {
        digsum+=subset[i];
    }
    if(digsum%3==0 && zeroflag==1)
    {
        return 1;
    }
    return 0;
}

int compare()
{
    if(ansindex>subsetindex)
    {
        return 0;
    }
    else if(subsetindex>ansindex)
    {
        sort(subset,subsetindex);
        return 1;
    }
    else
    {
        int returnflag=0;
        sort(subset,subsetindex);
        for(int i=0;i<subsetindex;i++)
        {
            if(answer[i]>subset[i])
            {
                break;
            }
            if(subset[i]>answer[i])
            {
                returnflag=1;
                break;
            }
        }
        return returnflag;
    }
    
}
int main()
{
    int ansflag=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&numbers[i]);
    }
    for(int i=(1<<n)-1;i>0;i--)
    {
        for(int x=0;x<n;x++)
        {
            if(1<<x & i)
            {
               subset[subsetindex++]=numbers[x]; 
            }
        }
        //subset has been generated
        if(check()==1 && compare()==1)
        {
            ansflag=1;
            reset(answer);
            for(int j=0;j<subsetindex;j++)
            {
                answer[j]=subset[j];
            }
            ansindex=subsetindex;
        }
        reset(subset);
        subsetindex=0;
    }
    if(ansflag==0)
    {
        printf("NO NUMBER");
    }
    else
    {   
        for(int i=0;i<ansindex;i++)
        {
        printf("%d",answer[i]);
        }
    }
    
    

}
