#include<stdio.h>
#include<stdlib.h>
int n,m,u,v,a,k,b,l;
int tollCities[1000];
int gasCylinders[1000];

void sort(int arr[], int size)
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
    scanf("%d %d %d",&n,&m,&l);
    scanf("%d%d%d%d%d",&u,&v,&a,&b,&k);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&tollCities[i]);
    }
    for(int i=0;i<l;i++)
    {
        scanf("%d",&gasCylinders[i]);
    }
    sort(tollCities,m);
    sort(gasCylinders,l);

    int startindex;
    for(int i=0;i<m;i++)
    {
        if(tollCities[i]==u)
        {
            startindex = i;
            break;
        }
    }
    int cost=0;
    for(int i=startindex;i<m-1;i++)
    {

    }
}