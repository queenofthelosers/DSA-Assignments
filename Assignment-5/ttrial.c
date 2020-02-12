#include<stdio.h>
#include<stdlib.h>
int n,m;
int p[1000][1000];
int val;

int binary_search(int start,int end,int i)
{
    if(end>=start)
    {
        int mid = (start+end)/2;
        
        if(p[i][mid]==val)
        {
            return mid;
        }
        else if(p[i][mid]>val)
        {
            return binary_search(start,mid-1,i);
        }
        else
        {
            return binary_search(mid+1,end,i);
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
    int ans1=-1;
    int ans2=-1;
    for(int i=0;i<n;i++)
    {
        ans2 = binary_search(0,m-1,i);
        if(ans2!=-1)
        {
            ans1=i;
            break;
        }
    }
    printf("%d %d",ans1,ans2);
    

}

/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
10
*/