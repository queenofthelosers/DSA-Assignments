#include<stdio.h>
#include<stdlib.h>

int array[1000];
int n,z;

int findPivot(int start,int end)
{
    if(start>end)
    {
        return 1;
    }
    if(start==end)
    {
        return end;
    }
    int mid = (start+end)/2;
    if(mid<end && array[mid]>array[mid+1])
    {
        return mid;
    }
    if(mid>start && array[mid]<array[mid-1])
    {
        return mid-1;
    }
    if(array[start]>=array[end])
    {
        return findPivot(start,mid-1);
    }
    else
    {
        return findPivot(mid+1,end);
    }
}

int binarysearch(int key,int start, int end)
{
    if(end>=start)
    {
        int mid = (start+end)/2;
        if(array[mid]==key)
        {
            return mid;
        }
        else if(array[mid]>key)
        {
            return binarysearch(key,start,mid-1);
        }
        else
        {
            return binarysearch(key,mid+1,end);
        }
        
    }
    return -1;
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    scanf("%d",&z);
    int pivot = findPivot(0,n-1);
    if(pivot==-1)
    {
        int ans = binarysearch(z,0,n-1);
        printf("%d",ans);
    }
    if(array[pivot]==z)
    {
        printf("YES\n%d",pivot);
    }
    if(array[0]<=z)
    {
        int ans = binarysearch(z,0,pivot-1);
        if(ans==-1)
        {
            printf("NO");
        }
        else
        {
            printf("YES\n%d",ans);   
        }
    }
    else
    {
        int ans = binarysearch(z,pivot+1,n-1);
        if(ans==-1)
        {
            printf("NO");
        }
        else
        {
            printf("YES\n%d",ans);   
        }
    }
    
}