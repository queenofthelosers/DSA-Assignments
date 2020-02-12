#include<stdio.h>
#include<stdlib.h>
int n,m;
int p[1000][1000];
int search;

int binSearchRow()
{
    int start = 0;
    int end = n-1;
    int x=-1;
    while(end>=start)
    {
        int mid = (start+end)/2;
        if(p[mid][0]>search)
        {
            end = mid-1;
            x = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    if(x==-1)
    {
        return n-1;
    }
    return x;    
}

int binSearchColumn(int x)
{
    int start = 0;
    int end = m-1;
    int y=-1;
    while(end>=start)
    {
        int mid = (start+end)/2;
        if(p[x][mid]==search)
        {
            y = mid;
            break;
        }
        else if(p[x][mid]>search)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return y;
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
    scanf("%d",&search);
    int X = binSearchRow();
    int Y = binSearchColumn(X);

    if(Y==-1)
    {
        printf("NOT FOUND");
    }
    else
    {
        printf("YES\n%d %d",X,Y);
    }
    
}