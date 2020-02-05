#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int array[n];
    for(int i=0;i<n;i++)
    {
        array[i]=0;
    }
    int l,r,x;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&l,&r,&x);
        for(int j=l;j<=r;j++)
        {
            array[j]+=x;
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
}