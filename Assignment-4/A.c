#include<stdio.h>
#include<stdlib.h>
int n;
float points[1000][3];
float y[1000];
float allmightX;
float allmightY;
float allmight;
void sort(float arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void newCoordinates(float delim)
{
    for(int i=0;i<n;i++)
    {
        if(points[i][0]!=allmight)
        {
            float x2 = points[i][1];
            float y2 = points[i][2];
            float y1 = delim;
            //int x1 =???
            float x1 = allmightX + (((x2-allmightX)/(y2-allmightY))*(y1-allmightY));
            float x = x1 - allmightX;
            points[i][1]=x;
        }
    }
    //sort by x variation, descending order
}

void finalsort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(points[j+1][1]>points[j][1])
            {
                float tempX = points[j+1][1];
                points[j+1][1] = points[j][1];
                points[j][1] = tempX;

                float temp = points[j+1][0];
                points[j+1][0] = points[j][0];
                points[j][0] = temp;

                float tempY = points[j+1][2];
                points[j+1][2] = points[j][2];
                points[j][2] = tempY;
            }
        }
    }

    for(int i=0;i<n-1;i++)
    {
        if(points[i][1]==points[i+1][1] && points[i][2]>points[i+1][2])
        {
            float tempX = points[i+1][1];
            points[i+1][1] = points[i][1];
            points[i][1] = tempX;

            float temp = points[i+1][0];
            points[i+1][0] = points[i][0];
            points[i][0] = temp;

            float tempY = points[i+1][2];
            points[i+1][2] = points[i][2];
            points[i][2] = tempY;
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
    allmightY = y[0];
    for(int i=0;i<n;i++)
    {
        if(points[i][2]==allmightY)
        {
            allmightX = points[i][1];
            allmight = points[i][0];
            break;
        }
    }

  
    float delimiter = y[1];
    // //draw a horizontal line, and then sort by X coordinate difference (descending order)
   
    newCoordinates(delimiter);
    
    finalsort();
    for(int i=0;i<n;i++)
    {
        if(points[i][0]!=allmight)
        {
            int num = points[i][0]/1.0;
            printf("%d ",num);
        }
    }
}


/*
16
12 -3 -1
15 5 5
13 2 -3
14 3 5
1 11 2
2 -1 4
10 -2 2
5 7 4
4 9 3
7 -3 1
6 -3 0
8 10 -4
9 -1 2
16 1 4
3 4 -3
11 0 3
*/