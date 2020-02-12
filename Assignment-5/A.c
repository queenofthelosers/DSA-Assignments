#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int adj[1000][1000];
int n;
int visited[1000];
int answers[5000][3];
int maxDistance = INT_MIN;
void dfs(int start,int end,int distance)
{
    visited[start]=1;
    if(start==end && distance>maxDistance)
    {
        maxDistance = distance;
    }
    for(int i=0;i<n;i++)
    {
        if(adj[start][i]==1 && visited[i]==0)
        {
            dfs(i,end,distance+1);
        }
    }
}

void reset(int arr[])
{
    for(int i=0;i<1000;i++)
    {
        arr[i]=0;
    }
}

void customsort(int answerindex)
{
    //sort according to distance desc, U ascending, V descending

    for(int i=0;i<answerindex;i++)
    {
        for(int j=0;j<answerindex-1;j++)
        {
            if(answers[j+1][2]>answers[j][2])
            {
                int tempU = answers[j][0];
                answers[j][0] = answers[j+1][0];
                answers[j+1][0] = tempU;

                int tempV = answers[j][1];
                answers[j][1] = answers[j+1][1];
                answers[j+1][1] = tempV;

                int tempdist = answers[j][2];
                answers[j][2] = answers[j+1][2];
                answers[j+1][2] = tempdist;
            }
            if(answers[j+1][2]==answers[j][2] && answers[j][0]>answers[j+1][0])
            {
                int tempU = answers[j][0];
                answers[j][0] = answers[j+1][0];
                answers[j+1][0] = tempU;

                int tempV = answers[j][1];
                answers[j][1] = answers[j+1][1];
                answers[j+1][1] = tempV;

                int tempdist = answers[j][2];
                answers[j][2] = answers[j+1][2];
                answers[j+1][2] = tempdist;
            }
            if(answers[j+1][2]==answers[j][2] && answers[j][0]==answers[j+1][0] && answers[j+1][1]>answers[j][1])
            {
                int tempU = answers[j][0];
                answers[j][0] = answers[j+1][0];
                answers[j+1][0] = tempU;

                int tempV = answers[j][1];
                answers[j][1] = answers[j+1][1];
                answers[j+1][1] = tempV;

                int tempdist = answers[j][2];
                answers[j][2] = answers[j+1][2];
                answers[j+1][2] = tempdist;
            }
        }
    }

}

int main()
{
    scanf("%d",&n);
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int answerDistance=INT_MIN;
    int answerindex=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            reset(visited);
            dfs(i,j,0);
            if(answerDistance<=maxDistance)
            {
                answerDistance = maxDistance;
                answers[answerindex][0] = i;
                answers[answerindex][1] = j;
                answers[answerindex][2] = maxDistance;
                answerindex++;
            }
            maxDistance = INT_MIN;
        }
    }

    customsort(answerindex);
    printf("%d\n",answers[0][2]);
    printf("%d %d",answers[0][0],answers[0][1]);

}

/*
14
0 1 
0 2 
0 3 
4 1 
5 1 
4 6 
4 12 
6 10 
6 11 
13 9 
9 2 
8 7 
7 3
*/