#include<stdio.h>
#include<stdlib.h>
int array[1000];

void sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
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
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    sort(array,n);
    int st = n/2;
    printf("%d\n",st);
    if(array[st]==array[n-1])
    {
        printf("%d",array[st]);
    }
    else
    {
        printf("NO NUMBER");
    }
}