#include<stdio.h>
#include<stdlib.h>

int adj[100][100];
int visited[100];
int answerArray[100];
int ansindex=0;
int n;
void DFS(int start, int curLevel,int desiredLevel)
{
    visited[start]=1;
    if(curLevel==desiredLevel)
    {
        answerArray[ansindex]=start;
        ansindex++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(adj[start][i]==1 && visited[i]!=1)
        {
            DFS(i,curLevel+1,desiredLevel);
        }
    }
}

void sort(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
int main()
{
    
    scanf("%d",&n);
    int parent;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&parent);
        adj[parent][i]=1;
    }
    int level;
    scanf("%d",&level);

    DFS(0,0,level);
    if(ansindex==0)
    {
        printf("-1");
    }
    else
    {
       sort(answerArray,ansindex);
       for(int i=0;i<ansindex;i++)
       {
           printf("%d ",answerArray[i]);
       }
    }
    
    
}