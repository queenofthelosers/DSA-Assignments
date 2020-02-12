#include<stdio.h>
#include<stdlib.h>
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int binsearch(int query,int start,int end)
{
    if(end>=start)
    {
        int mid = (start+end)/2;
        if(arr[mid]==query)
        {
            return mid;
        }
        if(arr[mid]>query)
        {
            return binsearch(query,start,mid-1);
        }
        if(arr[mid]<query)
        {
            return binsearch(query,mid+1,start);
        }
    }
    return -1;
        
}
int main()
{
    
    int q;
    scanf("%d",&q);
    int ans = binsearch(q,0,9);
    printf("%d",ans);
}