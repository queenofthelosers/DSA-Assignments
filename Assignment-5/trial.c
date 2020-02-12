#include<stdio.h>
#include<stdlib.h>
int n;
int adj[1500][1500];
int maxDistance = INT_MIN;
int answers[8000][3];
int answerindex;
int visited[1000];
void reset(int arr[])
{
    for(int i=0;i<1000;i++)
    {
        arr[i]=0;
    }
}
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

void customsort()
{
    for(int i=0;i<answerindex;i++)
    {
        for(int j=0;j<answerindex-1;j++)
        {
            if(answers[j][2]<answers[j+1][2])
            {
                int tempX = answers[j][0];
                answers[j][0] = answers[j+1][0];
                answers[j+1][0] = tempX;
                
                int tempY = answers[j][1];
                answers[j][1] = answers[j+1][1];
                answers[j+1][1] = tempY;

                int temp = answers[j][2];
                answers[j][2] = answers[j+1][2];
                answers[j+1][2] = temp;
            }
            if(answers[j][2]==answers[j+1][2] && answers[j][0]>answers[j+1][0])
            {
                int tempX = answers[j][0];
                answers[j][0] = answers[j+1][0];
                answers[j+1][0] = tempX;
                
                int tempY = answers[j][1];
                answers[j][1] = answers[j+1][1];
                answers[j+1][1] = tempY;

                int temp = answers[j][2];
                answers[j][2] = answers[j+1][2];
                answers[j+1][2] = temp;
            }
            if(answers[j][2]==answers[j+1][2] && answers[j][0]==answers[j+1][0] && answers[j][1]<answers[j+1][1])
            {
                int tempX = answers[j][0];
                answers[j][0] = answers[j+1][0];
                answers[j+1][0] = tempX;
                
                int tempY = answers[j][1];
                answers[j][1] = answers[j+1][1];
                answers[j+1][1] = tempY;

                int temp = answers[j][2];
                answers[j][2] = answers[j+1][2];
                answers[j+1][2] = temp;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x][y]=1;
        adj[y][x]=1;
    }
    int answerDistance = INT_MIN;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            reset(visited);
            dfs(i,j,0);
            if(answerDistance<=maxDistance)
            {
                answers[answerindex][0] = i;
                answers[answerindex][1] = j;
                answers[answerindex][2] = maxDistance;
                answerDistance=maxDistance;
                answerindex++;
            }
            maxDistance = INT_MIN;
        }
    }

    customsort();
    printf("%d\n",answers[0][2]);
    printf("%d %d",answers[0][0],answers[0][1]);
   
   

}