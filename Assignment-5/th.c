#include<stdio.h>
#include<stdlib.h>

int n,k;
int array[1000];
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    int triples=0;
    int p2=n-1;
    int p1=0;
    while(p2>p1)
    {
        int diff = array[p2] - array[1];
        if(diff>k)
        {
            p2--;
        }
        else
        {
            if(p2-p1>=2)
            {
                triples+=(p2-p1)*(p2-p1-1)/2;
            }
            p2=n-1;
            p1++;
        }
        
    }
    printf("%d",triples);
}