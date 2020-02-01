#include<stdio.h>
#include<stdlib.h>
int n,m,p1,q1,p2,q2;
int adj[1000][1000];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int checkbounds(int x,int y)
{
    if(x<m && y<n && x>=0 && y>=0)
    {
        return 1;
    }
    return 0;
}

int dfs(int x,int y)
{
    if(checkbounds(x,y)==0 || adj[x][y]==0)
    {
        return 0;
    }
    if(x==p1 && y==q2)
    {
        return 1;
    }
    for(int i=0;i<4;i++)
    {
        dfs(x+dx[i],y+dy[i]);
        return 1;
    }
    
}


int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    scanf("%d %d",&p1,&q1);
    scanf("%d %d",&p2,&q2);
    int flag= dfs(p1,q1);
    if(flag==0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
}