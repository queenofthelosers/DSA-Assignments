#include<stdio.h>
#include<stdlib.h>
int adj[1000][1000];
int n;
int visited[1000];
int leafdistance[1000];
int mindist=INT_MAX;
void dfs(int start, int dest, int distance)
{
    visited[start]=1;
    if(start==dest && distance<mindist)
    {
        mindist = distance;
    }
    for(int i=0;i<n;i++)
    {
        if(adj[start][i]==1 && visited[i]==0)
        {
            dfs(i,dest,distance+1);
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
    int leafnodes[n];
    int leafindex=0;
    for(int i=0;i<n;i++)
    {
        int parentcount=0;
        for(int j=0;j<n;j++)
        {
            if(adj[j][i]==1)
            {
                parentcount++;
            }
        }
        if(parentcount==1)
        {
            leafnodes[leafindex++]=i;
        }
    }

    int gymdistance=INT_MAX;
    for(int i=0;i<leafindex;i++)
    {
        mindist=INT_MAX;
        dfs(0,leafnodes[i],0);
        leafdistance[leafnodes[i]]=mindist;
        if(gymdistance>mindist)
        {
            gymdistance = mindist;
        }
        for(int j=0;j<1000;j++)
        {
            visited[j]=0;
        }
    }
    int gymcount=0;
    for(int i=0;i<1000;i++)
    {
        if(leafdistance[i]==gymdistance)
        {
            gymcount++;
        }
    }
    printf("%d\n",gymcount);

    for(int i=0;i<1000;i++)
    {
        if(leafdistance[i]==gymdistance)
        {
            printf("%d",i);
            break;
        }
    }

}