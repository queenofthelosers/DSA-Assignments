#include<stdio.h>
#include<stdlib.h>
int adj[1000][1000];
int n,m;
int mainserver;
int visited[1000];
void dfs(int start, int disconnected)
{
    visited[start]=1;
    for(int i=0;i<n;i++)
    {
        if(adj[start][i]==1 && visited[i]==0 && i!=disconnected)
        {
            dfs(i,disconnected);
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
    scanf("%d",&mainserver);
    int minconnect=INT_MAX;
    int ansflag=0;
    int answer;
    for(int i=0;i<n;i++)
    {
        if(i!=mainserver)
        {
            dfs(mainserver,i);
            int connectcount=0;
            for(int j=0;j<1000;j++)
            {
                if(visited[j]==1)
                {
                    connectcount++;
                }
            }
            if(connectcount<n-1)
            {
                ansflag=1;
            }
            if(minconnect>connectcount)
            {
                minconnect = connectcount;
                answer=i;
            }
            for(int j=0;j<1000;j++)
            {
                visited[j]=0;
            }
        }
    }

    if(ansflag==1)
    {
        printf("%d",answer);
    }
    else
    {
        printf("BLACK OUT");
    }
}