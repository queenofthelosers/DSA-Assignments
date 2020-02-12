#include<stdio.h>
#include<stdlib.h>
int n,m,val;
int p[1000][1000];

int binarysearch(int val,int start,int end,int i)
{
    while(end>=start)
    {
        int mid = (start+end)/2;
        if(p[i][mid]==val)
        {
            return mid;
        }
        else if(p[i][mid]>val)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return -1;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
    
    scanf("%d",&val);
    int ans=0;
    int ans2=0;
    for(int i=0;i<n;i++)
    {
        ans = binarysearch(val,0,m-1,i);
        ans2 = i;
        if(ans!=-1)
        {
            break;
        }
    }
    if(ans==-1)
    {
        printf("NOT FOUND");
    }
    else
    {
        printf("YES\n%d %d",ans2,ans);  
    }
    
    
    
    
}