#include<stdio.h>
#include<stdlib.h>
int n,k;
int array[1000];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    int p1=0;
    int p2=n-1;
    int triples=0;
    while(p1!=p2)
    {
        int diff = array[p2]-array[p1];
        if(diff>k)
        {
            p2--;
        }
        else
        {
            int numbers = p2-p1;
            if(numbers>=2)
            {
                triples+=(p2-p1)*(p2-p1-1)/2;
            }
            p1++;
            p2=n-1;
        }
        
    }
    printf("%d",triples);
}