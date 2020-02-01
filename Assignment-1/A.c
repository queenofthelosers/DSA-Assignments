#include<stdio.h>
#include<stdlib.h>
int matrix1[100][100];
int matrix2[100][100];
int n,m,x,y;
int checkEquality(int i1,int j1)
{
    int equalCount=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(matrix2[i][j]==matrix1[i1+i][j1+j])
            {
                equalCount++;
            }
        }
    }
    if(equalCount==(x*y))
    {
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }

    scanf("%d %d",&x,&y);
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    int subflag=0;
    for(int i=0;i<n-x+1;i++)
    {
        for(int j=0;j<m-y+1;j++)
        {
            if(matrix1[i][j]==matrix2[0][0])
            {
                if(checkEquality(i,j)==1)
                {
                    subflag=1;
                    printf("YES\n");
                    printf("%d %d",i,j);
                }
            }
        }
    }
    if(subflag==0)
    {
        printf("NO");
    }
    


}