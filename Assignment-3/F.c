#include<stdio.h>
#include<stdlib.h>
int adj[100000][100000];
int n;
int visited[100000];
int leafdistance[100000];
int mindistance = INT_MAX;
void dfs(int start,int end,int distance)
{
    visited[start]=1;
    if(start==end && distance<mindistance)
    {
        mindistance = distance;
    }
    for(int i=0;i<n;i++)
    {
        if(adj[start][i]==1 && visited[i]==0)
        {
            dfs(i,end,distance+1);
        }
    }
}
int main()
{
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    //find all the cities which could be called leaf cities
    int leaf[n];
    int leafindex=0;
    for(int i=0;i<n;i++)
    {
        int parent_count=0;
        for(int j=0;j<n;j++)
        {
            if(adj[j][i]==1)
            {
                parent_count++;
            }
        }
        if(parent_count==1)
        {
            leaf[leafindex++]=i;
        }
    }
    for(int i=0;i<leafindex;i++)
    {
        mindistance = INT_MAX;
        printf("%d ",leaf[i]);
        dfs(0,leaf[i],0);

        for(int j=0;j<100000;j++)
        {
            visited[j]=0;
        }
        leafdistance[leaf[i]]=mindistance;
    }
    int answer=100000;
    int gymcount=0;
    int ansflag=0;
    for(int i=0;i<100000;i++)
    {
        if(leafdistance[i]==mindistance)
        {
            gymcount++;
            if(ansflag==0)
            {
                answer = i;
                ansflag=1;
            }
        }
    }

    printf("%d\n%d",gymcount,answer);
}