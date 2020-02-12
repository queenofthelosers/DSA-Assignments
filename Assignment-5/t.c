#include<stdio.h>
#include<stdlib.h>
int adj[1500][1500];
int n;
int visited[1000];
int maxDistance = INT_MIN;
int answers[1500][3];
int answerindex;

void reset()
{
    for(int i=0;i<1000;i++)
    {
        visited[i]=0;
    }
}
void dfs(int start,int end,int distance)
{
    visited[start]=1;
    if(start==end && distance>maxDistance)
    {
        maxDistance=distance;
    }
   
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && adj[start][i]==1)
        {
            dfs(i,end,distance+1);
        }
    }
}
void customsort()
{
    for(int i=0;i<answerindex;i++)
    {
        for(int j=0;j<answerindex-1;j++)
        {
            if(answers[j+1][2]>answers[j][2])
            {
                int temp = answers[j+1][2];
                answers[j+1][2] = answers[j][2];
                answers[j][2] = temp;
                
                int tempX = answers[j+1][0];
                answers[j+1][0] = answers[j][0];
                answers[j][0] = tempX;

                int tempY = answers[j+1][1];
                answers[j+1][1] = answers[j][1];
                answers[j][1] = tempY;
            }
            if(answers[j+1][2]==answers[j][2] && answers[j][0]>answers[j+1][0])
            {
                int temp = answers[j+1][2];
                answers[j+1][2] = answers[j][2];
                answers[j][2] = temp;
                
                int tempX = answers[j+1][0];
                answers[j+1][0] = answers[j][0];
                answers[j][0] = tempX;

                int tempY = answers[j+1][1];
                answers[j+1][1] = answers[j][1];
                answers[j][1] = tempY;

            }
            if(answers[j+1][2]==answers[j][2] && answers[j][0]==answers[j+1][0] && answers[j+1][1]>answers[j][1] )
            {
                int temp = answers[j+1][2];
                answers[j+1][2] = answers[j][2];
                answers[j][2] = temp;
                
                int tempX = answers[j+1][0];
                answers[j+1][0] = answers[j][0];
                answers[j][0] = tempX;

                int tempY = answers[j+1][1];
                answers[j+1][1] = answers[j][1];
                answers[j][1] = tempY;

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
    int answerDistance = INT_MIN;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            reset(visited);
            dfs(i,j,0);
            if(maxDistance>=answerDistance)
            {
                answerDistance = maxDistance;
                answers[answerindex][0] = i;
                answers[answerindex][1] = j;
                answers[answerindex][2] = answerDistance;
                answerindex++;
            }
            maxDistance = INT_MIN;
        }
    }

    customsort();
    printf("%d\n%d %d",answers[0][2],answers[0][0],answers[0][1]);
}