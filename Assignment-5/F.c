#include<stdio.h>
#include<stdlib.h>
int n;
int array[1000];

void sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
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
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    
    sort(array,n);

    int sweetNum=1;
    int sweetCount=0;
    int mark1 = array[0];
    for(int i=0;i<n;i++)
    {
        if(mark1==array[i])
        {
            sweetCount += sweetNum;
        }
        else
        {
            sweetNum++;
            sweetCount+=sweetNum;
            mark1=array[i];
        }
        
    }

    printf("%d",sweetCount);
}