#include<stdio.h>
#include<stdlib.h>
int n,m,l,u,v,a,b,k;
int gasCylinders[1000];
int tollCities[1000];

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

int search(int z)
{
    for(int i=0;i<l;i++)
    {
        if(gasCylinders[i]>=z)
        {
            return gasCylinders[i];
        }
    }
    return -1;
}
int main()
{
    scanf("%d %d %d",&n,&m,&l);
    scanf("%d %d %d %d %d",&u,&v,&a,&b,&k);
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
    int startindex=-1,lastindex=-1;
    for(int i=0;i<m;i++)
    {
        if(tollCities[i]==u)
        {
            startindex=i;
            break;
        }
    }
    int cost=0;
    int reachableflag=1;
    for(int i=startindex;i<m-1;i++)
    {
        if(tollCities[i+1]>=v)
        {
            lastindex=i;
            break;
        }
        int distance = tollCities[i+1]-tollCities[i];
        int z = (distance-b)%a==0?((distance-b)/a):(((distance-b)/a)+1);
        int litres = search(z);
        if(litres==-1)
        {
            reachableflag=0;
            break;
        }
        int c = litres*k;
        cost+=c;
    }
    
    int distance = v-tollCities[lastindex];
    int z = (distance-b)%a==0?((distance-b)/a):(((distance-b)/a)+1);
    int litres = search(z);
    if(litres==-1)
    {
        reachableflag=0;
    }
    int c = litres*k;
    cost+=c;
    if(reachableflag==0)
    {
        printf("NOT POSSIBLE");
    }
    else
    {
        printf("%d",cost);
    }
    
}


/*
100 15 7
11 92 2 3 10
52 81 76 36 5 23 50 90 17 46 3 82 11 92 83
1 8 11 7 2 5 9
*/