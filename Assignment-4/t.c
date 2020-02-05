#include<stdio.h>
#include<stdlib.h>

float points[1000][3];
float amY,amX,am;
float y[1000];
int n;

void sort(float arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void newCoordinates(float delimiter)
{
    for(int i=0;i<n;i++)
    {
        if(points[i][0]!=am)
        {
            float x2 = points[i][1];
            float y2 = points[i][2];
            float x1 = amX + (delimiter-amY)*((x2-amX)/(y2-amY));
            float x = x1 - amX;
            points[i][1]=x;
        }
    }
}

void finalsort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(points[j][1]<points[j+1][1])
            {
                float tempX = points[j][1];
                points[j][1] = points[j+1][1];
                points[j+1][1]=tempX;

                float tempY = points[j][2];
                points[j][2] = points[j+1][2];
                points[j+1][2]=tempY;

                float temp = points[j][0];
                points[j][0] = points[j+1][0];
                points[j+1][0] = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(points[j][1]==points[j+1][1] && points[j][2]>points[j+1][2])
            {
                float temp = points[j][0];
                points[j][0] = points[j+1][0];
                points[j+1][0] = temp; 
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%f %f %f",&points[i][0],&points[i][1],&points[i][2]);
        y[i] = points[i][2];
    }

    sort(y,n);
    amY = y[0];
    float delimiter = y[1];
    
    for(int i=0;i<n;i++)
    {
        if(points[i][2]==amY)
        {
            amX = points[i][1];
            am = points[i][0];
            break;
        }
    }

    newCoordinates(delimiter);
    finalsort();

    for(int i=0;i<n;i++)
    {
        if(points[i][0]!=am)
        {
            int ind = points[i][0]/1.0;
            printf("%d ",ind);
        }
    }
    
}