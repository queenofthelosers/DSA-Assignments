#include<stdio.h>
#include<stdlib.h>
int n,k;
int array[1000];

int binary_search(int val, int start,int end)
{
    int ans=-1;
    while(end>=start)
    {
        int mid = (start+end)/2;
        if(array[mid]>=val)
        {
            end = mid-1;
            ans = mid;
        }
        else
        {
            start = mid+1;
        } 
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    int m=0;
    for(int i=2;i<n;i++)
    {
        int lowbound = array[i]-k;
        int index = binary_search(lowbound,0,n-1);
        if(index<=i-2)
        {
            m+= (i-index)*(i-index-1)/2;
        }
    }
    printf("%d",m);
}