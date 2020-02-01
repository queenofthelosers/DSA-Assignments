#include<stdio.h>
#include<stdlib.h>
int adj[1000][1000];
int adj_copy[1000][1000];
int n,m;
int mainserver;
int visited[1000];
void dfs(int start)
{
    visited[start]=1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && adj_copy[start][i]==1)
        {
            dfs(i);
        }
    }
}

void reset(int arr[])
{
    for(int i=0;i<1000;i++)
    {
        visited[i]=0;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
        adj_copy[u][v]=1;
        adj_copy[v][u]=1;
    }

    scanf("%d",&mainserver);
    int blackoutflag=1;
    int minconnected=INT_MAX;
    int answer=1000;
    for(int i=0;i<n;i++)
    {
        //try disconnecting each of these servers
        if(i!=mainserver)
        {
            int connected=0;
            for(int j=0;j<n;j++)
            {
                adj_copy[i][j]=0;
                adj_copy[j][i]=0;
            }

            dfs(mainserver);

            for(int j=0;j<n;j++)
            {
                if(visited[j]==1)
                {
                    connected++;
                }
            }
            if(connected<n-1 && connected<minconnected)
            {
                blackoutflag=0;
                minconnected = connected;
                answer = i;
            }

            reset(visited);

            for(int j=0;j<n;j++)
            {
                if(adj[i][j]==1)
                {
                    adj_copy[i][j]=1;
                    adj_copy[j][i]=1;
                }
            }
        }
    }

    if(blackoutflag==1)
    {
        printf("BLACK OUT");
    }
    else
    {
        printf("%d",answer);
    }
}