#include<stdio.h>
#include<stdlib.h>

int array[1000];
int n,value;

int binary_search(int val, int start, int end)
{
    int mid = (start+end)/2;
    if(start>=end)    
        return -1;
    if(array[mid]==val)
        return mid;
    if(array[start]<=array[mid])
    {
        if(val>=array[start] && array[mid]>=val)
            return binary_search(val,start,mid-1);
        return binary_search(val,mid+1,end);
    }
    else
    {
        if(val>=array[mid] && val<=array[end])
            return binary_search(val,mid+1,end);
        return binary_search(val,start,mid-1);
    }
    
    
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    scanf("%d",&value);

    int ans = binary_search(value,0,n-1);
    if(ans==-1)
    {
        printf("NOT FOUND");
    }
    else
    {
        printf("%d",ans);
    }
    
}