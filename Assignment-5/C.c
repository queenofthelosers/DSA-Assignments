#include<stdio.h>
#include<stdlib.h>
int n,m;
int adj[1000][1000];
int visited[1000];
int itemOrder[1000];
int itemindex;
int cycleflag;
void dfs(int start)
{
    visited[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(adj[start][i]==1 && visited[i]==0)
        {
            dfs(i);
        }
    }
    itemOrder[itemindex++] = start;
}

int dfsCycle(int position,int start,int startflag)
{
    if(startflag==0 && position==start)
    {
        startflag=1;
    }
    else if(startflag==1 && position==start)
    {
        return 1;
    }
    else
    {
        visited[position]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(adj[position][i]==1 && visited[i]==0)
        {
            return dfsCycle(i,start,startflag);
        }
    }
    return 0;
}

void topoSort()
{
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        adj[y][x]=1;
    }

    for(int i=1;i<=n;i++)
    {
        cycleflag = dfsCycle(i,i,0);
        for(int j=0;j<1000;j++)
        {
            visited[j]=0;
        }
        if(cycleflag==1)
        {
            break;
        }
    }
    if(cycleflag==0)
    {
        topoSort();
        for(int i=itemindex-1;i>=0;i--)
        {
            printf("%d ",itemOrder[i]);
        }
    }
    else
    {
        printf("NOT POSSIBLE");
    }
    
        

}

/*
5 8
4 1
2 1
2 4
2 5
3 5
5 4
3 1
2 3
*/