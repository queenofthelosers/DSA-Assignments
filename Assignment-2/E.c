#include<stdio.h>
#include<stdlib.h>
int adj[100][100];
int n,m;
int visited[100];
void DFS(int start)
{
   
    visited[start] = 1;
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
    }
    int answer=-1;
    for(int i=1;i<=n;i++)
    {
        DFS(i);
        int visitcount=0;
        for(int i=0;i<100;i++)
        {
            if(visited[i]==1)
            {
                visitcount++;
            }
        }
        if(visitcount==n)
        {
            answer = i;
        }
    }

    if(answer==-1)
    {
        printf("BAD LUCK");
    }
    else
    {
        printf("%d",answer);
    }
    

}