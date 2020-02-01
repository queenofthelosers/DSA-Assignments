#include<stdio.h>
#include<stdlib.h>

int n;
int numbers[1000];
int subset[1000];
int subsetindex;
int answer[1000];
int answerindex;
int digit_freq[10];
int ansflag=0;
void sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j+1]>arr[j])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]=temp;
            }
        }
    }
}

int check()
{
    int digitsum=0;
    for(int i=0;i<10;i++)
    {
        digit_freq[i]=0;
    }

    for(int i=0;i<subsetindex;i++)
    {
        digitsum+=subset[i];
        digit_freq[subset[i]]++;
    }
    if(digitsum%3==0 && digit_freq[0]>0)
    {
        return 1;
    }
    return 0;
}

int compare()
{
    if(subsetindex>answerindex)
    {
        sort(subset,subsetindex);
        return 1;
    }
    else if(answerindex>subsetindex)
    {
        return 0;
    }
    else
    {
        int returnflag=0;
        sort(subset,subsetindex);
        for(int i=0;i<subsetindex;i++)
        {
            if(answer[i]<subset[i])
            {
                returnflag=1;
                break;
            }
            if(answer[i]>subset[i])
            {
                break;
            }
        }
        return returnflag;
    }
}

void reset(int arr[])
{
    for(int i=0;i<1000;i++)
    {
        arr[i]=0;
    }
}
int main()
{
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
                subset[subsetindex]=numbers[x];
                subsetindex++;
            }   
        }
        
        if(check()==1 && compare()==1)
        {
            // change answer, reorder digits in max order
            ansflag=1;
            reset(answer);
            answerindex=0;
            for(int j=0;j<subsetindex;j++)
            {
                answer[j]=subset[j];
            }
            answerindex=subsetindex;
            
        }
    
        reset(subset);
        subsetindex=0;
    }

    if(ansflag==1)
    {
        for(int i=0;i<answerindex;i++)
        {
            printf("%d",answer[i]);
        }
    }
    else
    {
        printf("NO NUMBER");
    }
    
}