#include<stdio.h>
#include<stdlib.h>
int adj[1000][1000];
int mainserver;
int n,m;
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
    

}