#include<stdio.h>
#include<stdlib.h>

int adj[100][100];
int visited[100];
int n,m;
void DFS(int start)
{
    visited[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(adj[start][i]==1 && visited[i]!=1)
        {
            DFS(i);
        }
    }
}
int main()
{
    
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int maxconnect=0;
    int disconnected[n+1];
    for(int i=0;i<=n;i++)
    {
        disconnected[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        DFS(i);
        int connect_count=0;
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==1)
                connect_count++;
        }
        if(maxconnect<connect_count)
        {
            maxconnect = connect_count;
            for(int j=1;j<=n;j++)
            {
                disconnected[j]=0;
            }
            for(int j=1;j<=n;j++)
            {
                if(visited[j]==0)
                {
                    disconnected[j]=1;
                }
            }
        }
        for(int j=0;j<100;j++)
        {
            visited[j]=0;
        }
    }

    printf("%d\n",n-maxconnect);
    for(int i=1;i<=n;i++)
    {
        if(disconnected[i]==1)
        {
            printf("%d ",i);
        }
    }
    
    
}