#include<stdio.h>
#include<stdlib.h>
int n;
int numbers[1000];
int partitioned[1000];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&numbers[i]);
    }
    int fixed;
    scanf("%d",&fixed);
    int highflag=0;
    int lowflag=0;
    int index;
    for(int i=0;i<n;i++)
    {
        if(numbers[i]==fixed)
        {
            index=i;
            break;
        }
    }

    for(int i=0;i<index;i++)
    {
        if(numbers[i]>fixed)
        {
            lowflag=1;
            break;
        }
    }
    for(int i=index;i<n;i++)
    {
        if(numbers[i]<fixed)
        {
            highflag=1;
            break;
        }
    }
    if(highflag==0 && lowflag==0)
    {
        printf("ALL SET");
    }
    else
    {
        int firstindex=500;
        int lastindex=500;
        for(int i=0;i<n;i++)
        {
            if(numbers[i]==fixed)
            {
                partitioned[lastindex++] = fixed;
                numbers[i] = INT_MIN;          
            }
        }

        for(int i=0;i<n;i++)
        {
            if(numbers[i]!=INT_MIN && numbers[i]>=fixed)
            {
                partitioned[lastindex++] = numbers[i];
            }
            if(numbers[i]!=INT_MIN && numbers[i]<fixed)
            {
                firstindex--;
                partitioned[firstindex] = numbers[i];
            }
            
        }

        for(int i=firstindex;i<lastindex;i++)
        {
            printf("%d ",partitioned[i]);
        }
    }
    
        

}